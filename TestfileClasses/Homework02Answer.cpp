#include "Homework02Answer.h"

USING_NS_CC;

Scene* Homework02Answer::createScene()
{
	return Homework02Answer::create();
}

bool Homework02Answer::init()
{
	if (!Scene::init())
	{
		return false;
	}
	////////////////////////////////

	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);


	TTFConfig ttfConfig("fonts/CookieRun Black.ttf", 40);

	pLabel = Label::createWithTTF(ttfConfig, "This font is CookieRun Black");
	pLabel->setPosition(Vec2(640, 200));
	pLabel->setColor(Color3B::BLACK);
	pLabel->setOpacity(0);
	this->addChild(pLabel);

	sprite1 = Sprite::create("Basic/CyanSquare.png");
	sprite1->setPosition(Vec2(400, 360));
	this->addChild(sprite1);
	sprite2 = Sprite::create("Basic/MagentaSquare.png");
	sprite2->setPosition(Vec2(640, 360));
	this->addChild(sprite2);



	this->schedule(schedule_selector(Homework02Answer::eventupdate), 0.5);



	return true;
}

void Homework02Answer::eventupdate(float f)
{
	if (pLabel->getStringLength() > currentLetter)
	{
		auto pSprite = pLabel->getLetter(currentLetter);
		if (pSprite != nullptr)
		{
			pSprite->setOpacity(255);
			auto pJump = JumpBy::create(0.5, Vec2(0, 0), 50, 1);
			pSprite->runAction(pJump);
		}
		currentLetter++;
	}
	else
		this->unschedule(schedule_selector(Homework02Answer::eventupdate));

}
void Homework02Answer::onEnter()
{
	Scene::onEnter();

	listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(Homework02Answer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Homework02Answer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Homework02Answer::onTouchEnded, this);
	

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, sprite1);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sprite2);
}
void Homework02Answer::onExit()
{
	_eventDispatcher->removeAllEventListeners();

	Scene::onExit();

}

bool Homework02Answer::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());

	Vec2 locationInNode = touch->getLocation();

	if (target->getBoundingBox().containsPoint(locationInNode))
	{
		target->setOpacity(180);
		return true;
	}
}

void Homework02Answer::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());

	target->setPosition(target->getPosition() + touch->getDelta());

	auto enemy = (target == sprite1) ? sprite2 : sprite1;

	if (target->getBoundingBox().intersectsRect(enemy->getBoundingBox()))
	{
		this->doCollisionCheck(target, enemy);
	}
}

void Homework02Answer::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
}

void Homework02Answer::doCollisionCheck(cocos2d::Sprite * target, cocos2d::Sprite * enemy)
{
	//두 스프라이트가 충돌했을 때
	float deltaX = target->getPositionX() - enemy->getPositionX();
	float deltaY = target->getPositionY() - enemy->getPositionY();

	//가로축에서 충돌이 발생한 경우
	if (fabs(deltaX) > fabs(deltaY))
	{
		if (deltaX > 0)
		{
			float moveDelta0 = enemy->getBoundingBox().getMaxX() - target->getBoundingBox().getMinX();
			enemy->setPositionX(enemy->getPositionX() - moveDelta0);
		}
		else 
		{
			float moveDelta0 = target->getBoundingBox().getMaxX() - enemy->getBoundingBox().getMinX();
			//sprit1을 오른쪽으로 이동
			enemy->setPositionX(enemy->getPositionX() + moveDelta0);
		}
	}
	else //세로축에서 충돌한 경우
	{
		if (deltaY > 0)
		{
			float moveDelta0 = enemy->getBoundingBox().getMaxY() - target->getBoundingBox().getMinY();
			//sprite1을 아래쪽으로 이동
			enemy->setPositionY(enemy->getPositionY() - moveDelta0);
		}
		else
		{
			float movedDelta0 = target->getBoundingBox().getMaxY() - enemy->getBoundingBox().getMinY();
			//sprite1을 위쪽으로 이동
			enemy->setPositionY(enemy->getPositionY() + movedDelta0);
		}
	}
}
