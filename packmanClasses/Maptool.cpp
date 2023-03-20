#include "Maptool.h"

USING_NS_CC;
using namespace std;

Scene* Maptool::createScene()
{
	return Maptool::create();
}

bool Maptool::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	//참고 배경
	auto sprite = Sprite::create("background.png");
	sprite->setAnchorPoint(Vec2(0, 0));
	sprite->setPosition(Vec2(0, 0));
	sprite->setZOrder(2);
	this->addChild(sprite);

	Size size = sprite->getContentSize();

	float startY = sprite->getPosition().y + sprite->getContentSize().height - CELL_HEIGHT;
	
	//클릭할 타일맵 세팅
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			auto sprite2 = Sprite::create("empty.png");
			sprite2->setAnchorPoint(Vec2(0, 0));
			sprite2->setPosition(Vec2(j*CELL_WIDTH, startY - (i*CELL_HEIGHT)));
			sprite2->setOpacity(100);
			sprite2->setZOrder(3);
			this->addChild(sprite2);
			_vectSprite.push_back(sprite2);
		}
	}

	//타일맵 기본값 세팅
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			//맵을 세팅하기 전 기본값을 세팅해준다.
			nMap[i][j] = (int)MapObject::EMPTY;
		}
	}

	curObject = "bigCandy.png";

	/////////////////////////////////->세이브 버튼 메뉴
	MenuItemFont::setFontSize(20);

	auto pMenuItem1 = MenuItemFont::create(
		"Save", CC_CALLBACK_1(Maptool::DoClick, this));
	auto pMenuItem2 = MenuItemFont::create(
		"LoadMap", CC_CALLBACK_1(Maptool::DoClick, this));
	auto pMenuItem3 = MenuItemFont::create(
		"ExitTool", CC_CALLBACK_1(Maptool::DoClick, this));

	pMenuItem1->setTag(1);
	pMenuItem2->setTag(2);
	pMenuItem3->setTag(3);

	auto pmenu = Menu::create(pMenuItem1, pMenuItem2, pMenuItem3, nullptr);

	pmenu->alignItemsHorizontally();

	this->addChild(pmenu);
	pmenu->setPosition(240, 600);
	pmenu->setColor(Color3B::BLACK);
	pmenu->alignItemsHorizontallyWithPadding(10);

	pmenu->setZOrder(100);

	///////////////////////////////////->오브젝트 선택 메뉴
	MenuItemFont::setFontSize(15);

	auto pMenuObjItem1 = MenuItemFont::create(
		"Player", CC_CALLBACK_1(Maptool::DoChangeCurObjectState, this));
	auto pMenuObjItem2 = MenuItemFont::create(
		"enemy", CC_CALLBACK_1(Maptool::DoChangeCurObjectState, this));
	auto pMenuObjItem3 = MenuItemFont::create(
		"normalCandy", CC_CALLBACK_1(Maptool::DoChangeCurObjectState, this));
	auto pMenuObjItem4 = MenuItemFont::create(
		"Wall", CC_CALLBACK_1(Maptool::DoChangeCurObjectState, this));
	
	pMenuObjItem1->setTag(1000);
	pMenuObjItem2->setTag(2000);
	pMenuObjItem3->setTag(3000);
	pMenuObjItem4->setTag(4000);

	auto pMenu2 = Menu::create(pMenuObjItem1, pMenuObjItem2, pMenuObjItem3, pMenuObjItem4, nullptr);

	pMenu2->alignItemsHorizontally();

	this->addChild(pMenu2);
	pMenu2->setPosition(240, 550);
	pMenu2->setColor(Color3B::BLACK);
	pMenu2->alignItemsHorizontallyWithPadding(20);

	pMenu2->setZOrder(100);
	
	return true;
}

void Maptool::onEnter()
{
	Scene::onEnter();

	//싱글터치 모드로 터치리스너 등록
	listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(Maptool::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(Maptool::onTouchEnded, this);

	vectEventListener.push_back(listener);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, _vectSprite[0]);

	for (int i = 1; i < _vectSprite.size(); i++)
	{
		cocos2d::EventListenerTouchOneByOne* temp = listener->clone();
		vectEventListener.push_back(temp);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(temp, _vectSprite[i]);
	}
}

void Maptool::onExit()
{
	for (int i = 0; i < vectEventListener.size(); i++)
	{
		_eventDispatcher->removeEventListener(vectEventListener[i]);
	}

	Scene::onExit();
}

bool Maptool::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	Vec2 locationInNode = touch->getLocation();
	Size S = target->getContentSize();
	Rect rect = Rect(target->getPosition().x, target->getPosition().y, S.width, S.height);

	if (rect.containsPoint(locationInNode))
	{
		//스프라이트 표시
		auto sprite5 = Sprite::create(curObject);
		sprite5->setAnchorPoint(Vec2(0, 0));
		sprite5->setPosition(target->getPosition());
		if (curObject == "empty.png")
			sprite5->setColor(Color3B::BLACK);
		sprite5->setZOrder(5);
		this->addChild(sprite5);

		//맵에 저장
		int indexX = sprite5->getPosition().x / CELL_WIDTH;
		int indexY = sprite5->getPosition().y / CELL_HEIGHT;
		indexY = (30 - indexY) % 30;

		//마지막 끝줄 예외 처리
		indexY = ((sprite5->getPosition().y / CELL_HEIGHT) == 0) ? 30 : indexY;

		nMap[indexY][indexX] = (int)curState;

		return true;
	}

	return false;
}

void Maptool::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
}

void Maptool::DoClick(Ref * pSender)
{
	auto tItem = (MenuItem*)pSender;
	int i = tItem->getTag();

	switch (i)
	{
	case 1:
		SaveObjectData();
		break;
	case 2:
		LoadObjectData();
		break;
	case 3:
		_director->getTextureCache()->removeUnusedTextures();
		auto pScene = StartScene::createScene();
		Director::getInstance()->replaceScene(pScene);
		break;
	}
}

void Maptool::CreateObject(std::string fileName, Coordinate objPos)
{
	auto pObj = Sprite::create(fileName);
	pObj->setPosition(Vec2(objPos.x, objPos.y));
	pObj->setAnchorPoint(Vec2(0, 0));
	pObj->setZOrder(5);
	this->addChild(pObj);

	if (fileName == "empty.png");
	pObj->setColor(Color3B::BLACK);
}

void Maptool::LoadObjectData()
{
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

		SetpositionObject();
	}
}

void Maptool::SaveObjectData()
{
	ofstream writeFile;

	writeFile.open("text.txt", std::ofstream::out | std::ofstream::trunc);

	string str = "";
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			str += std::to_string(nMap[i][j]) + " ";
		}
		str += "\n";
	}
	writeFile.write(str.c_str(), str.length());
	
	writeFile.close();
}

void Maptool::DoChangeCurObjectState(Ref * pSender)
{
	auto tItem = (MenuItem*)pSender;
	int i = tItem->getTag();
	if (i == 1000)
	{
		curObject = "player0.png";
		curState = MapObject::PLAYER;
	}
	else if (i == 2000)
	{
		curObject = "enemy.png";
		curState = MapObject::ENEMY;
	}
	else if (i == 3000)
	{
		curObject = "Candy.png";
		curState = MapObject::CANDY;
	}
	else if (i == 4000)
	{
		curObject = "empty.png";
		curState = MapObject::WALL;
	}
}

void Maptool::SetpositionObject()
{
	std::string fileName = "";
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (nMap[i][j] == MapObject::PLAYER) { fileName = "player0.png"; }
			else if (nMap[i][j] == MapObject::ENEMY) { fileName = "enemy.png"; }
			else if (nMap[i][j] == MapObject::CANDY) { fileName = "Candy.png"; }
			else if (nMap[i][j] == MapObject::WALL) { fileName = "empty.png"; }
			else { fileName = ""; }

			if (fileName != "")
				CreateObject(fileName, Coordinate(j * 17, (30 - i) * 17));
		}
	}
}
