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
	auto pLabel = LabelTTF::create("���� ��ġ�ؼ� �巡�� �ϼ���.", "fonts/CookieRun Black.ttf", 20);
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

	//�̱���ġ���� ���
	listener = EventListenerTouchOneByOne::create();
	//��ġ �̺�Ʈ ó����带 �����Ѵ�. �̰�������Ʈ�� �����������
	//Z-Order�� ���ϳ��� ��ü�� ��ġ�̺�Ʈ�� ȥ�ڼ����Ѵ�.
	listener->setSwallowTouches(true);

	//�̱���ġ �̺�Ʈ �������� ��ġ ���۽� �߻��ϴ� �̺�Ʈ�� ���ٽ��� �̿��� ����Ѵ�.
	listener->onTouchBegan = [=](Touch* touch, Event* event) //[=] :�ּҸ��� ����..
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
	
	//�̺�Ʈ ����ó�� �̱���ġ �̺�Ʈ �����ʸ� ����Ѵ�.
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
