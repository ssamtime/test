#include "Homework02.h"

USING_NS_CC;

Scene* Homework02::createScene()
{
	return Homework02::create();
}

bool Homework02::init()
{
	if (!Scene::init())
	{
		return false;
	}
	////////////////////////////////

	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	sprite1 = Sprite::create("Basic/CyanSquare.png");
	sprite1->setPosition(Vec2(300, 360) + Vec2(-150, 150));
	this->addChild(sprite1);

	sprite2 = Sprite::create("Basic/MagentaSquare.png");
	sprite2->setPosition(Vec2(300, 360));
	this->addChild(sprite2);

	this->scheduleUpdate();

	//--------------------------LabelAction

	auto pLabel = Label::createWithTTF("asdf", "fonts/CookieRun Black.ttf", 40);
	pLabel->setColor(Color3B::BLACK);
	pLabel->setPosition(Vec2(200, 200));
	this->addChild(pLabel);


	for (int i = 0; i < pLabel->getStringLength(); i++)
	{
		auto wChar = (Sprite*)pLabel->getLetter(i);

		//wChar->setPosition(Vec2(300+50 * i, 100));
		wChar->setColor(Color3B::BLACK);
		auto hide = Hide::create();
		wChar->runAction(hide);

		auto show = Show::create();
		auto seq = Sequence::create(DelayTime::create(1.0f + i), show, nullptr);
		wChar->runAction(seq);
	}
	
	return true;
}

void Homework02::update(float f)
{
	if (sprite1->getBoundingBox().intersectsRect(sprite2->getBoundingBox()) && sprite1->getOpacity() == 180)
	{

		//log("Collision Check");
		if (sprite1->getPositionX() <= sprite2->getPositionX() - 75)
		{
			auto deltaX = sprite1->getBoundingBox().getMaxX() - sprite2->getBoundingBox().getMinX();
			sprite2->setPosition(Vec2(sprite1->getPositionX() + 100, sprite2->getPositionY()));
		}
		else if (sprite1->getPositionX() >= sprite2->getPositionX() + 75)
		{
			sprite2->setPosition(Vec2(sprite1->getPositionX() - 100, sprite2->getPositionY()));
		}
		else if (sprite1->getPositionY() <= sprite2->getPositionY() - 75)
		{
			sprite2->setPosition(Vec2(sprite2->getPositionX(), sprite1->getPositionY() + 100));
		}
		else if (sprite1->getPositionY() >= sprite2->getPositionY() + 75)
		{
			sprite2->setPosition(Vec2(sprite2->getPositionX(), sprite1->getPositionY() - 100));
		}
	}
	else if (sprite2->getBoundingBox().intersectsRect(sprite1->getBoundingBox()))
	{

		if (sprite2->getPositionX() <= sprite1->getPositionX() - 75)
		{
			sprite1->setPosition(Vec2(sprite2->getPositionX() + 100, sprite1->getPositionY()));
		}
		else if (sprite2->getPositionX() >= sprite1->getPositionX() + 75)
		{
			sprite1->setPosition(Vec2(sprite2->getPositionX() - 100, sprite1->getPositionY()));
		}
		else if (sprite2->getPositionY() <= sprite1->getPositionY() - 70)
		{
			sprite1->setPosition(Vec2(sprite1->getPositionX(), sprite2->getPositionY() + 100));
		}
		else if (sprite2->getPositionY() >= sprite1->getPositionY() + 70)
		{
			sprite1->setPosition(Vec2(sprite1->getPositionX(), sprite2->getPositionY() - 100));
		}
	}
}
void Homework02::onEnter()
{
	Scene::onEnter();

	//�̱���ġ���� ���
	listener = EventListenerTouchOneByOne::create();
	//��ġ �̺�Ʈ ó����带 �����Ѵ�. �̰�������Ʈ�� ����������� Z-Order�� ���ϳ��� ��ü�� ��ġ�̺�Ʈ�� ȥ�ڼ����Ѵ�.
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

}
void Homework02::onExit()
{
	_eventDispatcher->removeAllEventListeners();

	Scene::onExit();

}
