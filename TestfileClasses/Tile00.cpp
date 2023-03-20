#include "Tile00.h"

USING_NS_CC;

Scene* Tile00::createScene()
{
	return Tile00::create();
}

bool Tile00::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	winSize = Director::getInstance()->getWinSize();

	//Ÿ�ϸ� �о����
	tmap = TMXTiledMap::create("TileMap/TileDessert.tmx");
	background = tmap->getLayer("Background");
	items = tmap->getLayer("Items");
	//items->setVisible(false);
	metainfo = tmap->getLayer("MetaInfo");
	metainfo->setVisible(false);

	this->addChild(tmap, 0, 11); //addchild(�̸�,zorder,tag)

	//Ÿ�ϸʿ��� Objects��� ������ ������Ʈ ���̾��� ��ü�� ��������
	auto objects = tmap->getObjectGroup("Objects");

	//������Ʈ ���̾�� Objects��� ������ �Ӽ����� �о�´�.
	ValueMap spawnPoint = objects->getObject("Objects");

	int x = spawnPoint["x"].asInt();
	int y = spawnPoint["y"].asInt();

	dragonPosition = Vec2(x, y);

	this->createDragon();

	return true;
}

void Tile00::onEnter()
{
	Scene::onEnter();

	listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(Tile00::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(Tile00::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Tile00::onExit()
{
	_eventDispatcher->removeEventListener(listener);
	Scene::onExit();
}

bool Tile00::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	return true;
}

void Tile00::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto touchPoint = touch->getLocation();
	touchPoint = this->convertToNodeSpace(touchPoint);

	Vec2 playerPos = dragon->getPosition();
	Vec2 diff = touchPoint - playerPos;

	if (abs(diff.x) > abs(diff.y))
	{
		if (diff.x > 0)
		{
			playerPos.x += tmap->getTileSize().width;

			// �巡���� ������ �ٲ��ش�.
			dragon->setFlippedX(true);
		}
		else
		{
			playerPos.x -= tmap->getTileSize().width;

			// �巡���� ������ �ٲ��ش�.
			dragon->setFlippedX(false);
		}
	}
	else
	{
		if (diff.y > 0)
		{
			playerPos.y += tmap->getTileSize().height;
		}
		else
			playerPos.y -= tmap->getTileSize().height;
	}

	if (playerPos.x <= (tmap->getMapSize().width * tmap->getTileSize().width) &&
		playerPos.y <= (tmap->getMapSize().height * tmap->getTileSize().height) &&
		playerPos.y >= 0 && playerPos.x >= 0)
	{
		// �巡���� ���ο� ��ġ ����
		this->setPlayerPosition(playerPos);
	}

	// �巡���� ��ġ�� ���� ȭ�� ��ġ ����
	this->setViewPointCenter(dragon->getPosition());
}

void Tile00::createDragon()
{
	// �����̴� �巡�� �ֱ� ����
	auto texture = Director::getInstance()->getTextureCache()->addImage("Basic/dragon_animation.png");

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);

	for (int i = 0; i < 6; i++)
	{
		int index = i % 4;
		int rowIndex = i / 4;

		animation->addSpriteFrameWithTexture(texture, Rect(index * 138, rowIndex * 148 + 70, 110, 70));
	}

	// ��������Ʈ ���� �� �ʱ�ȭ
	dragon = Sprite::createWithTexture(texture, Rect(0, 70, 110, 70));
	dragon->setPosition(dragonPosition);
	this->addChild(dragon);

	// �巡�� ������ �ٲ��ְ�
	dragon->setFlippedX(true);

	// �巡���� ����� �ٿ��ش�.
	// �ʿ� ���ؼ� �巡���� ����� ũ��.
	dragon->setScale(0.5);

	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	dragon->runAction(rep);
}

void Tile00::setViewPointCenter(cocos2d::Vec2 position)
{
}

cocos2d::Vec2 Tile00::tileCoordForPosition(cocos2d::Vec2 position)
{
	int x = position.x / tmap->getTileSize().width;
	int y = ((tmap->getMapSize().height * tmap->getTileSize().height) - position.y) / tmap->getTileSize().height;

	return Vec2(x, y);
}

void Tile00::setPlayerPosition(cocos2d::Vec2 position)
{
	// �ǵ� ��ġ ���ϱ�
	Vec2 tileCoord(this->tileCoordForPosition(position));

	// ���� ��ġ�� ��ġ�� Ÿ�� gid ���ϱ�
	// ��ġ�� ��ġ�� Ÿ���� Ÿ�ϸʿ��� � ��ġ�� �ִ���
	// �����´�.
	int tileGid = this->metainfo->getTileGIDAt(tileCoord);

	// tileGid�� null �� �ƴ϶��
	if (tileGid)
	{
		Value properties = tmap->getPropertiesForGID(tileGid);

		if (!properties.isNull())
		{
			std::string wall = properties.asValueMap()["Wall"].asString();
			if (wall == "YES")
			{
				log("WALL...");
				return;
			}

			std::string item1 = properties.asValueMap()["Items"].asString();
			if (item1 == "Apple")
			{
				this->metainfo->removeTileAt(tileCoord);
				items->removeTileAt(tileCoord);

				// ���� ����ŭ ������ �÷��ִ� �ڵ��� �߰������� �ʿ��ϴ�.
				log("������ ȹ��!! �� �޽����� ������ ��µǴ��� Ȯ��");
			}
		}
	}

	// �Ķ���ͷ� ���� ��ġ�� �巡�� ��ġ �����ϱ�
	dragon->setPosition(position);

	
}
