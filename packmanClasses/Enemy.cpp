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

    // �ڱ��ڽ� �� ������ �ʱ�ȭ
    this->_pos = pos;
    // �̵��� ��ǥ ������ (ó������ �׳� ���� ���������� �����Ѵ�.)
    this->confirmPos = Coordinate(_pos.x, _pos.y);

    // ���̾� ũ�� ����
    this->setContentSize(_enemy->getContentSize());
    this->scheduleUpdate();
    return true;
}

void Enemy::update(float f)
{
    // ��ǥ ��ǥ ����
    this->SetDestPos();

    // �̵� �߿� A* ��ΰ� �ٲ�� �����ٸ� ������ ���� �� �����Ƿ�
    // ������ �̵��� ���� �� A* �� �ٽ� ����� �Ѵ�.
    if (isSearchMove == false)
    {
        // Astar �ʱ�ȭ
        this->InitAstar();
    }

    // ����� ��ġ�� ���� ������
    if (_points.size() != 0)
    {
        // �������� ������ �������� ����
        if (!isSearchMove)
        {
            _pos.x = _points.front().x;
            _pos.y = _points.front().y;
            _points.pop_front();

            // �� �̵� ���� ���� ����
            direction = Vec2(_pos.x * CELL_WIDTH,
                ((MAP_HEIGHT - 1) - _pos.y) * CELL_HEIGHT) - 
                this->getPosition();
            // normalize�� ���͸� 1�� ����� ���⸸ �����.
            direction.normalize();
        }
    }

    // ���� �̵��ؾ��� �Ÿ��� 0.5f���� ũ�ٸ� �̵��Ѵ�.
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
                // ��ȿ ������ ������� ��ŵ
                // ��ȿ ���� : ���� ������ ������� �� �������
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

// Astar ������ �ʱ�ȭ
void Enemy::InitAstar()
{
    if (!confirmPos.Equare(dest))
    {
        // 1. ��ǥ������ �������ش�.
        dest = confirmPos;

        // ���� �̵� ��� �ʱ�ȭ
        while (!_points.empty())
        {
            _points.pop_front();
        }
        _points.clear();

        // ��� ������ ��� �ִٸ� �ʱ�ȭ
        while (!pq.empty())
        {
            pq.pop();
        }

        // ������ �迭 ��ü�� �ʱ�ȭ
        for (int i = 0; i < MAP_HEIGHT; i++)
        {
            for (int j = 0; j < MAP_WIDTH; j++)
            {
                open[i][j] = 9999999;
                closed[i][j] = 0;
                parent[i][j] = Coordinate(0, 0);
            }
        }

        // ������ �߰�(������ ���� ����)
        open[_pos.y][_pos.x] = 0; // �������̴ϱ� G�� 0�̰� H ����.
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
        // ���� ���� �ĺ��� ã�´�.
        PQNode node = pq.front();
        pq.pop();

        // ������ ��ǥ�� ���� ��η� ã�Ƽ�, �� ���� ��η� ���ؼ� �̹� �湮(closed) 
        // �� ��� ��ŵ
        if (closed[node.Y][node.X])
            continue;

        // �湮 �Ѵ�.
        closed[node.Y][node.X] = true;

        //�������� ���������� �ٷ� ����
        if (node.Y == dest.y && node.X == dest.x)
        {
            break;
        }


        int size = (sizeof(deltaY) / sizeof(int));
        // �����¿� �� �̵��� �� �ִ� ��ǥ���� Ȯ���ؼ� ����(open) �Ѵ�.
        for (int i = 0; i < size; i++)
        {
            int nextX = node.X + deltaX[i];
            int nextY = node.Y + deltaY[i];

            // ��ȿ ������ ������� ��ŵ
            if (nextY < 0 || nextY >= MAP_HEIGHT ||
                nextX < 0 || nextX >= MAP_WIDTH)
            {
                continue;
            }

            // ������ ������ �� �� ������ ��ŵ
            if (GameManager::getInstance().nMap[nextY][nextX] == MapObject::WALL)
            {
                continue;
            }

            // �̹� �湮�� ���̸� ��ŵ
            if (closed[nextY][nextX])
            {
                continue;
            }

            // ��� ���
            int g = node.G + cost[i];
            // distance �Ÿ� ����ϴ� ����
            int h = (dest.y - nextY) + (dest.x - nextX);

            // �ٸ� ��ο��� �� ���� ���� �̹� ã������ ��ŵ(���� �� �ʿ䰡 �����ϱ�)
            if (open[nextY][nextX] < g + h)
            {
                continue;
            }

            // ���� ����
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

        // �θ� ���Ѵ�.
        Vec2 pos(parent[y][x].x, parent[y][x].y);
        x = pos.x;
        y = pos.y;
    }

    // �Ųٷ� �̵��ؾ� �ϹǷ� ��ǥ ����� ������ �ش�.
    _points.reverse();
}
