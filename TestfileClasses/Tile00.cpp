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

	//타일맵 읽어오기
	tmap = TMXTiledMap::create("TileMap/TileDessert.tmx");
	background = tmap->getLayer("Background");
	items = tmap->getLayer("Items");
	//items->setVisible(false);
	metainfo = tmap->getLayer("MetaInfo");
	metainfo->setVisible(false);

	this->addChild(tmap, 0, 11); //addchild(이름,zorder,tag)

	//타일맵에서 Objects라고 지정한 오브젝트 레이어의 객체들 가져오기
	auto objects = tmap->getObjectGroup("Objects");

	//오브젝트 레이어에서 Objects라고 지정한 속성값을 읽어온다.
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

			// 드래곤의 방향을 바꿔준다.
			dragon->setFlippedX(true);
		}
		else
		{
			playerPos.x -= tmap->getTileSize().width;

			// 드래곤의 방향을 바꿔준다.
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
		// 드래곤의 새로운 위치 지정
		this->setPlayerPosition(playerPos);
	}

	// 드래곤의 위치에 맞춰 화면 위치 조정
	this->setViewPointCenter(dragon->getPosition());
}

void Tile00::createDragon()
{
	// 움직이는 드래곤 넣기 시작
	auto texture = Director::getInstance()->getTextureCache()->addImage("Basic/dragon_animation.png");

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);

	for (int i = 0; i < 6; i++)
	{
		int index = i % 4;
		int rowIndex = i / 4;

		animation->addSpriteFrameWithTexture(texture, Rect(index * 138, rowIndex * 148 + 70, 110, 70));
	}

	// 스프라이트 생성 및 초기화
	dragon = Sprite::createWithTexture(texture, Rect(0, 70, 110, 70));
	dragon->setPosition(dragonPosition);
	this->addChild(dragon);

	// 드래곤 방향을 바꿔주고
	dragon->setFlippedX(true);

	// 드래곤의 사이즈를 줄여준다.
	// 맵에 비해서 드래곤의 사이즈가 크다.
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
	// 탭된 위치 구하기
	Vec2 tileCoord(this->tileCoordForPosition(position));

	// 현재 터치된 위치의 타일 gid 구하기
	// 터치된 위치의 타일이 타일맵에서 어떤 위치에 있는지
	// 가져온다.
	int tileGid = this->metainfo->getTileGIDAt(tileCoord);

	// tileGid가 null 이 아니라면
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

				// 먹은 수만큼 점수를 올려주는 코딩을 추가적으로 필요하다.
				log("아이템 획득!! 이 메시지가 여러번 출력되는지 확인");
			}
		}
	}

	// 파라미터로 들어온 위치에 드래곤 위치 조정하기
	dragon->setPosition(position);

	
}
