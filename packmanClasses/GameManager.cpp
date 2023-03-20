#include "GameManager.h"

USING_NS_CC;
using namespace std;

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

GameManager* GameManager::create(cocos2d::Node* _listener, cocos2d::SEL_CallFunc _selector)
{
    GameManager* ret = &(getInstance());
    
    if (ret && ret->init(_listener, _selector))
        ret->autorelease();
    else
        CC_SAFE_DELETE(ret);

    return ret;
}

bool GameManager::init(cocos2d::Node* _listener, cocos2d::SEL_CallFunc _selector)
{
    this->_listener = _listener;
    this->_selector = _selector;

    auto layerColor = LayerColor::create(Color4B::WHITE);
    this->addChild(layerColor);

    // ���
    ///////////////////////////////////////
    bg = Sprite::create("background.png");
    bg->setAnchorPoint(Vec2(0, 0));
    bg->setPosition(Vec2(0, 0));
    bg->setZOrder(1);
    this->addChild(bg);


    // Ready �̹��� �߰�
    auto sprite = Sprite::create("Ready.png");
    sprite->setPosition(Director::getInstance()->getWinSize().width / 2, Director::getInstance()->getWinSize().height / 2);
    sprite->setZOrder(1000);
    this->addChild(sprite);

    // ���� ������ �о� ���� �ݹ� �ۼ�
    auto startEvent = CallFunc::create
    ([this] {this->FileDataRead();
    this->schedule(schedule_selector(GameManager::MoveTime));   });

    sprite->runAction(Sequence::create(DelayTime::create(1.5f),
        startEvent, RemoveSelf::create(), nullptr));

    return true;
}

void GameManager::FileDataRead()
{
    // ���� �����
    ifstream readFile;
    readFile.open("test.txt");

    if (readFile.is_open())
    {
        int i = 0, j = 0;
        while (!readFile.eof())
        {
            char nObjNum;

            readFile.get(nObjNum);

            if (nObjNum == ' ' || nObjNum == '\n')
                continue;

            nMap[i][j] = nObjNum - '0';
            j++;

            if (j == 28)
            {
                j = 0;
                i++;
            }
        }

        this->SetPlayerPosition();
        this->SetPositionObject();
    }
}

void GameManager::EnemyCallback()
{
}

void GameManager::SetPlayerPosition()
{
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            if (nMap[i][j] == MapObject::PLAYER)
            {
                Player* pPlayer = Player::create(this, callfunc_selector(GameManager::EnemyCallback));
                pPlayer->setPosition(j * CELL_WIDTH, (30 - i) * CELL_HEIGHT);
                pPlayer->_mapPos = Coordinate(j, i);
                pPlayer->setAnchorPoint(Vec2(0, 0));
                pPlayer->setZOrder(2);
                this->addChild(pPlayer);
                vecPlayer.push_back(pPlayer);
            }
        }
    }
}

void GameManager::SetPositionObject()
{
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            auto pObj = Sprite::create();
            std::string fileName = "null";

            if (nMap[i][j] == MapObject::ENEMY)
            {
                Enemy* pEnemy = Enemy::create(this, Coordinate(j, i), callfunc_selector(GameManager::EnemyCallback));
                pEnemy->setPosition(j * CELL_WIDTH, (30 - i) * CELL_HEIGHT);
                pEnemy->setAnchorPoint(Vec2(0, 0));
                pEnemy->setZOrder(3);
                this->addChild(pEnemy);
                vecEnemy.push_back(pEnemy);
            }
            else if (nMap[i][j] == MapObject::CANDY)
            {
                fileName = "Candy.png";
                vecCandy.push_back(pObj);
            }
            else if (nMap[i][j] == MapObject::WALL)
            {
                fileName = "empty.png";
                vecWall.push_back(pObj);
            }

            // fileName�� ������Ʈ �Ǿ��ٸ� ����ִ� �ڸ��� �ƴϴ�.
            if (fileName != "null")
            {
                pObj->setTexture(fileName);
                pObj->setPosition(j * CELL_HEIGHT, (30 - i) * CELL_WIDTH);
                pObj->setAnchorPoint(Vec2(0, 0));
                pObj->setZOrder(2);
                this->addChild(pObj);

                // �� �� �����̸��� empty��� ���̶�� �ǹ��̴� ���� ������ �������ش�.
                if (fileName == "empty.png")
                {
                    pObj->setOpacity(10);
                }
            }
        }
    }
}

Coordinate GameManager::GetPlayerPos()
{
    return vecPlayer.at(0)->_mapPos;
}

void GameManager::MoveTime(float f)
{
    // ������ ������ �ʾҴٸ�
    if (!isGameEnd)
    {
        IsEatingCandy();

        if (IsEnemyCollision())
        {
            // ������ ������.
            isGameEnd = true;
            // ������Ʈ�� �����.
            this->unscheduleUpdate();

            // ���Ϳ� �浹��
            vecPlayer.at(0)->setVisible(false);
            vecPlayer.at(0)->removeFromParent();
            vecPlayer.clear();

            // ���ӿ��� ������ ������
            this->GameOver();

            return;
        }

		for (int i = 0; i < vecEnemy.size(); i++)
		{
			// �Ÿ��� ����� ���ٸ� ����´�.
			if (vecPlayer.at(0)->getPosition().distance(vecEnemy.at(i)->getPosition()) < 100.0f)
			{
				// ��������� ���¸� �ٲ��ش�.
				vecEnemy[i]->_state = EnemyState::SEARCH;
			}
		}
    }

}

void GameManager::GameOver()
{
    // GameOver ǥ��
    auto sprite = Sprite::create("GameOver.png");
    sprite->setPosition(Director::getInstance()->getWinSize().width / 2,
        Director::getInstance()->getWinSize().height / 2);
    sprite->setZOrder(1000);
    this->addChild(sprite);

    auto seq = Sequence::create(DelayTime::create(2.0f), CallFunc::create([this]() {
        (_listener->*_selector)();
        }), nullptr);

    this->runAction(seq);
}

void GameManager::IsEatingCandy()
{
	for (int i = 0; i < vecCandy.size(); i++)
	{
		if (vecPlayer.at(0)->getBoundingBox().intersectsRect(vecCandy.at(i)->getBoundingBox()))
		{
			if (vecCandy.at(i)->isVisible())
			{
				candyCount++;
			}
			vecCandy.at(i)->setVisible(false);
		}
	}

	if (vecCandy.size() == candyCount)
	{
		//TODO: �¸��߾��
		this->GameOver(); //�¸������� ���� �ѱ�� ���� �ϴ�
	}
}

bool GameManager::IsEnemyCollision()
{
	for (int i = 0; i < vecEnemy.size(); i++)
	{
		if (vecEnemy.at(i)->getBoundingBox().intersectsRect(vecPlayer.at(0)->getBoundingBox()))
		{
			return true;
		}
	}

    return false;
}
