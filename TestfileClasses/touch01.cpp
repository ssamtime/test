#include "touch01.h"

USING_NS_CC;

Scene* touch01::createScene()
{
	return touch01::create();
}

bool touch01::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	//-------------------------------------------
	auto pLabel = LabelTTF::create("블럭을 터치해서 드래그 하세요.", "fonts/CookieRun Black.ttf", 20);
	pLabel->setPosition(Vec2(640, 360));
	pLabel->setColor(Color3B(0, 0, 0));
	this->addChild(pLabel, 101);

	sprite1=Sprite::create("Basic/CyanSquare.png");
	sprite1->setPosition(Vec2(640, 360) + Vec2(-80, 80));
	this->addChild(sprite1);

	sprite2 = Sprite::create("Basic/MagentaSquare.png");
	sprite2->setPosition(Vec2(640, 360));
	this->addChild(sprite2);

	sprite3 = Sprite::create("Basic/YellowSquare.png");
	sprite3->setPosition(Vec2(640, 360) - Vec2(80, 80));
	this->addChild(sprite3);

	sprite1->setTag(1);
	sprite2->setTag(2);
	sprite3->setTag(3);


	return true;
}

void touch01::onEnter()
{
	Scene::onEnter();

	//싱글터치모드로 등록
	listener = EventListenerTouchOneByOne::create();
	//터치 이벤트 처리모드를 지정한다. 이경우오브젝트가 겹쳐있을경우
	//Z-Order가 제일높은 객체가 터치이벤트를 혼자수신한다.
	listener->setSwallowTouches(true);

	//싱글터치 이벤트 리스너의 터치 시작시 발생하는 이벤트를 람다식을 이용해 등록한다.
	listener->onTouchBegan = [=](Touch* touch, Event* event) //[=] :주소말고 값만..
	{
		log("touch began");

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Vec2 locationInNode = touch->getLocation();
		Size s = target->getContentSize();
		Rect rect = Rect(target->getPosition().x - (s.width / 2),
			target->getPosition().y - (s.height / 2), s.width, s.height);

		if (rect.containsPoint(locationInNode))
		{
			reZorder(target);

			target->setOpacity(180);
			return true;
		}
		
		return false;
	};

	listener->onTouchMoved = [](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setPosition(target->getPosition() + touch->getDelta());
	};

	listener->onTouchEnded = [](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setOpacity(255);
	};
	
	//이벤트 디스패처에 싱글터치 이벤트 리스너를 등록한다.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, sprite1);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sprite2);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sprite3);

}
void touch01::onExit()
{
	_eventDispatcher->removeAllEventListeners();

	Scene::onExit();
	
}

void touch01::reZorder(cocos2d::Sprite * pSender)
{
	sprite1->setLocalZOrder(0);
	sprite2->setLocalZOrder(0);
	sprite3->setLocalZOrder(0);

	pSender->setLocalZOrder(1);
}
