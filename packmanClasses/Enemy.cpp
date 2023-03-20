#include "Enemy.h"
#include "GameManager.h"

USING_NS_CC;

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

Enemy* Enemy::create(cocos2d::Node* _listener, Coordinate pos, cocos2d::SEL_CallFunc _selector)
{
    Enemy* ret = new Enemy();

    if (ret && ret->init(_listener, pos, _selector))
        ret->autorelease();
    else
        CC_SAFE_DELETE(ret);

    return ret;
}

bool Enemy::init(cocos2d::Node* _listener, Coordinate pos, cocos2d::SEL_CallFunc _selector)
{
    this->_listener = _listener;
    this->_selector = _selector;

    srand(time(NULL));

    _enemy = Sprite::create("enemy.png");
    _enemy->setPosition(0, 0);
    _enemy->setAnchorPoint(Vec2(0, 0));
    this->addChild(_enemy);

    // 자기자신 맵 포지션 초기화
    this->_pos = pos;
    // 이동할 목표 포지션 (처음에는 그냥 현재 포지션으로 설정한다.)
    this->confirmPos = Coordinate(_pos.x, _pos.y);

    // 레이어 크기 지정
    this->setContentSize(_enemy->getContentSize());
    this->scheduleUpdate();
    return true;
}

void Enemy::update(float f)
{
    // 목표 좌표 설정
    this->SetDestPos();

    // 이동 중에 A* 경로가 바뀌어 버린다면 문제가 생길 수 있으므로
    // 무조건 이동이 끝난 후 A* 로 다시 계산을 한다.
    if (isSearchMove == false)
    {
        // Astar 초기화
        this->InitAstar();
    }

    // 계산한 위치에 따라 움직임
    if (_points.size() != 0)
    {
        // 지속적인 유연한 움직임을 위함
        if (!isSearchMove)
        {
            _pos.x = _points.front().x;
            _pos.y = _points.front().y;
            _points.pop_front();

            // 적 이동 방향 벡터 구함
            direction = Vec2(_pos.x * CELL_WIDTH,
                ((MAP_HEIGHT - 1) - _pos.y) * CELL_HEIGHT) - 
                this->getPosition();
            // normalize로 벡터를 1로 만들어 방향만 남긴다.
            direction.normalize();
        }
    }

    // 적이 이동해야할 거리가 0.5f보다 크다면 이동한다.
    if (this->getPosition().distance(Vec2(_pos.x * CELL_WIDTH,
        ((MAP_HEIGHT - 1) - _pos.y) * CELL_HEIGHT)) > 0.5f)
    {
        isSearchMove = true;
        this->setPosition(this->getPosition() + (direction * f * _speed));
    }
    else
    {
        this->setPosition(Vec2(_pos.x * CELL_WIDTH,
            ((MAP_HEIGHT - 1) - _pos.y) * CELL_HEIGHT));
        isSearchMove = false;
    }

    if (this->confirmPos.Equare(this->_pos))
        this->isDefaultMove = false;
}

void Enemy::SetDestPos()
{
    switch (_state)
    {
    case EnemyState::MOVE:
        if (!isDefaultMove)
        {
            isDefaultMove = true;
            confirmPos = Coordinate((rand() % MAP_WIDTH),
                (rand() % MAP_HEIGHT));

            while (1)
            {
                // 유효 범위를 벗어났으면 스킵
                // 유효 범위 : 맵의 범위를 벗어나는지 안 벗어나는지
                if ((confirmPos.y < 0 || confirmPos.y >= MAP_HEIGHT ||
                    confirmPos.x < 0 || confirmPos.x >= MAP_WIDTH) ||
                    GameManager::getInstance().nMap[confirmPos.y][confirmPos.x] == MapObject::WALL)
                {
                    confirmPos = Coordinate((rand() % MAP_WIDTH),
                        (rand() % MAP_HEIGHT));
                }
                else
                    break;
            }
        }
        break;
    case EnemyState::SEARCH:
        if (!GameManager::getInstance().isGameEnd)
            confirmPos = GameManager::getInstance().GetPlayerPos();
        break;
    }

}

// Astar 데이터 초기화
void Enemy::InitAstar()
{
    if (!confirmPos.Equare(dest))
    {
        // 1. 목표지점을 세팅해준다.
        dest = confirmPos;

        // 최종 이동 경로 초기화
        while (!_points.empty())
        {
            _points.pop_front();
        }
        _points.clear();

        // 노드 정보가 들어 있다면 초기화
        while (!pq.empty())
        {
            pq.pop();
        }

        // 나머지 배열 객체들 초기화
        for (int i = 0; i < MAP_HEIGHT; i++)
        {
            for (int j = 0; j < MAP_WIDTH; j++)
            {
                open[i][j] = 9999999;
                closed[i][j] = 0;
                parent[i][j] = Coordinate(0, 0);
            }
        }

        // 시작점 발견(시작점 예약 진행)
        open[_pos.y][_pos.x] = 0; // 시작점이니까 G는 0이고 H 값임.
        PQNode pqNode;
        pqNode.F = 0;
        pqNode.G = 0;
        pqNode.X = _pos.x;
        pqNode.Y = _pos.y;
        pq.push(pqNode);

        Astar();
    }
}

void Enemy::Astar()
{
    while (pq.size() > 0)
    {
        // 제일 좋은 후보를 찾는다.
        PQNode node = pq.front();
        pq.pop();

        // 동일한 좌표를 여러 경로로 찾아서, 더 빠른 경로로 인해서 이미 방문(closed) 
        // 된 경우 스킵
        if (closed[node.Y][node.X])
            continue;

        // 방문 한다.
        closed[node.Y][node.X] = true;

        //목적지에 도착했으면 바로 종료
        if (node.Y == dest.y && node.X == dest.x)
        {
            break;
        }


        int size = (sizeof(deltaY) / sizeof(int));
        // 상하좌우 등 이동할 수 있는 좌표인지 확인해서 예약(open) 한다.
        for (int i = 0; i < size; i++)
        {
            int nextX = node.X + deltaX[i];
            int nextY = node.Y + deltaY[i];

            // 유효 범위를 벗어났으면 스킵
            if (nextY < 0 || nextY >= MAP_HEIGHT ||
                nextX < 0 || nextX >= MAP_WIDTH)
            {
                continue;
            }

            // 벽으로 막혀서 갈 수 없으면 스킵
            if (GameManager::getInstance().nMap[nextY][nextX] == MapObject::WALL)
            {
                continue;
            }

            // 이미 방문한 곳이면 스킵
            if (closed[nextY][nextX])
            {
                continue;
            }

            // 비용 계산
            int g = node.G + cost[i];
            // distance 거리 계산하는 공식
            int h = (dest.y - nextY) + (dest.x - nextX);

            // 다른 경로에서 더 빠른 길을 이미 찾았으면 스킵(업뎃 할 필요가 없으니까)
            if (open[nextY][nextX] < g + h)
            {
                continue;
            }

            // 예약 진행
            open[nextY][nextX] = g + h;
            PQNode pqNode2;
            pqNode2.F = g + h;
            pqNode2.G = g;
            pqNode2.X = nextX;
            pqNode2.Y = nextY;
            pq.push(pqNode2);
            parent[nextY][nextX] = Coordinate(node.X, node.Y);
        }
    }
    CalcPathFromParent(dest);
}

void Enemy::CalcPathFromParent(Coordinate dest)
{
    int x = dest.x;
    int y = dest.y;

    while (parent[y][x].y != y || parent[y][x].x != x)
    {
        _points.push_back(Coordinate(x, y));

        // 부모를 비교한다.
        Vec2 pos(parent[y][x].x, parent[y][x].y);
        x = pos.x;
        y = pos.y;
    }

    // 거꾸로 이동해야 하므로 좌표 목록을 뒤집어 준다.
    _points.reverse();
}
