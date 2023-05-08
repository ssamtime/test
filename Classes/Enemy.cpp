#include "Enemy.h"

USING_NS_CC;

cocos2d::Sprite* playerbullet1;
cocos2d::Sprite* bomb;
//목숨 총알 폭탄만들기

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

bool Enemy::init()
{
	arabian1 = Sprite::create("arabian.png");
	arabian1->setScale(3);
	arabian1->setAnchorPoint(Vec2(0, 0));
	arabian1->setPosition(Vec2(800, 100));
	arabian1->setZOrder(4);
    this->addChild(arabian1);
	arabianrunning1(arabian1);

	arabian2 = Sprite::create("arabian.png");
	arabian2->setScale(3);
	arabian2->setAnchorPoint(Vec2(0, 0));
	arabian2->setPosition(Vec2(1000, 100));
	arabian2->setZOrder(4);
	this->addChild(arabian2);
	arabianrunning2(arabian2);

	arabian3 = Sprite::create("arabian.png");
	arabian3->setScale(3);
	arabian3->setAnchorPoint(Vec2(0, 0));
	arabian3->setPosition(Vec2(1200, 100));
	arabian3->setZOrder(4);
	this->addChild(arabian3);
	arabianrunning3(arabian3);

	boss = Sprite::create("boss1.png");
	boss->setScale(3);
	boss->setAnchorPoint(Vec2(0, 0));
	boss->setPosition(Vec2(1000, 300));
	boss->setZOrder(5);
	this->addChild(boss);
	bosshp = 100;
	bossidle = true;
	auto movebossright = MoveBy::create(3, Vec2(300, 0));
	auto movebossleft = MoveBy::create(3, Vec2(-300, 0));
	auto movebossseq = Sequence::create(movebossright, movebossleft, nullptr);
	bossmoverepforever = RepeatForever::create(movebossseq);
	bossmoverepforever->retain();
	auto movebossup = MoveBy::create(2, Vec2(0, 20));
	auto movebossdown = MoveBy::create(2, Vec2(0, -20));
	auto movebossseq2 = Sequence::create(movebossup, movebossdown, nullptr);
	bossmoverepforever2 = RepeatForever::create(movebossseq2);
	bossmoverepforever2->retain();

	leftengine = Sprite::create("leftNormal.png");
	leftengine->setAnchorPoint(Vec2(0, 0));
	leftengine->setPosition(Vec2(boss->getPositionX() + 23, boss->getPositionY() + 151));
	leftengine->setScale(3);
	leftengine->setZOrder(6);
	this->addChild(leftengine);

	auto leftengineanimation = Animation::create();
	leftengineanimation->setDelayPerUnit(0.4);
	leftengineanimation->addSpriteFrameWithFile("leftNormal.png");
	leftengineanimation->addSpriteFrameWithFile("leftRed.png");
	leftengineanimation->addSpriteFrameWithFile("leftNormal.png");
	leftengineanimation->addSpriteFrameWithFile("leftYellow.png");
	leftengineanimation->addSpriteFrameWithFile("leftNormal.png");
	leftengineanimation->addSpriteFrameWithFile("leftBlue.png");
	auto leftengineanimate = Animate::create(leftengineanimation);
	leftengineRep = RepeatForever::create(leftengineanimate);
	leftengineRep->retain();


	rightengine = Sprite::create("rightNormal.png");
	rightengine->setAnchorPoint(Vec2(0, 0));
	rightengine->setPosition(Vec2(boss->getPositionX() + 600, boss->getPositionY() + 150));
	rightengine->setScale(3);
	rightengine->setZOrder(6);
	this->addChild(rightengine);

	auto rightengineanimation = Animation::create();
	rightengineanimation->setDelayPerUnit(0.4);
	rightengineanimation->addSpriteFrameWithFile("rightNormal.png");
	rightengineanimation->addSpriteFrameWithFile("rightRed.png");
	rightengineanimation->addSpriteFrameWithFile("rightNormal.png");
	rightengineanimation->addSpriteFrameWithFile("rightYellow.png");
	rightengineanimation->addSpriteFrameWithFile("rightNormal.png");
	rightengineanimation->addSpriteFrameWithFile("rightBlue.png");
	auto rightengineanimate = Animate::create(rightengineanimation);
	rightengineRep = RepeatForever::create(rightengineanimate);
	rightengineRep->retain();

	leftsmallflame = Sprite::create("hollow.png");
	leftsmallflame->setAnchorPoint(Vec2(0, 0));
	leftsmallflame->setPosition(Vec2(boss->getPositionX() + 97, boss->getPositionY() -13));
	leftsmallflame->setScale(3);
	leftsmallflame->setZOrder(6);
	this->addChild(leftsmallflame);

	auto leftsmallflameanimation = Animation::create();
	leftsmallflameanimation->setDelayPerUnit(0.15);
	leftsmallflameanimation->addSpriteFrameWithFile("smallflame1.png");
	leftsmallflameanimation->addSpriteFrameWithFile("smallflame2.png");
	leftsmallflameanimation->addSpriteFrameWithFile("smallflame3.png");
	leftsmallflameanimation->addSpriteFrameWithFile("smallflame4.png");
	leftsmallflameanimate = Animate::create(leftsmallflameanimation);

	rightsmallflame = Sprite::create("hollow.png");
	rightsmallflame->setFlippedX(true);
	rightsmallflame->setAnchorPoint(Vec2(0, 0));
	rightsmallflame->setPosition(Vec2(boss->getPositionX() + 623, boss->getPositionY() - 13));
	rightsmallflame->setScale(3);
	rightsmallflame->setZOrder(6);
	this->addChild(rightsmallflame);

	auto rightsmallflameanimation = Animation::create();
	rightsmallflameanimation->setDelayPerUnit(0.15);
	rightsmallflameanimation->addSpriteFrameWithFile("smallflame1.png");
	rightsmallflameanimation->addSpriteFrameWithFile("smallflame2.png");
	rightsmallflameanimation->addSpriteFrameWithFile("smallflame3.png");
	rightsmallflameanimation->addSpriteFrameWithFile("smallflame4.png");
	rightsmallflameanimate = Animate::create(rightsmallflameanimation);
	
	leftflame = Sprite::create("hollow.png");
	leftflame->setAnchorPoint(Vec2(0, 0));
	leftflame->setPosition(Vec2(boss->getPositionX() + 72, boss->getPositionY() - 352));
	leftflame->setScale(3);
	leftflame->setZOrder(6);
	this->addChild(leftflame);

	rightflame = Sprite::create("hollow.png");
	rightflame->setAnchorPoint(Vec2(0, 0));
	rightflame->setPosition(Vec2(boss->getPositionX() + 590, boss->getPositionY() - 352));
	rightflame->setScale(3);
	rightflame->setZOrder(6);
	this->addChild(rightflame);

	auto enginefiresprite1 = Sprite::create("flamerow1.png");
	auto enginefiretexture1 = enginefiresprite1->getTexture();
	auto animation1 = Animation::create();
	animation1->setDelayPerUnit(0.2);

	for (int i = 0; i < 9; i++)
	{
		animation1->addSpriteFrameWithTexture(enginefiretexture1, Rect( i* 50, 0, 50, 160));
	}
	
	leftflameanimate1 = Animate::create(animation1);
	rightflameanimate1 = Animate::create(animation1);
	leftflameanimate1->retain();
	rightflameanimate1->retain();

	auto enginefiresprite2 = Sprite::create("flamerow2.png");
	auto enginefiretexture2 = enginefiresprite2->getTexture();
	auto animation2 = Animation::create();
	animation2->setDelayPerUnit(0.2);

	for (int i = 0; i < 12; i++)
	{
		animation2->addSpriteFrameWithTexture(enginefiretexture2, Rect(i * 50, 0, 50, 160));
	}

	leftflameanimate2 = Animate::create(animation2);
	rightflameanimate2 = Animate::create(animation2);
	leftflameanimate2->retain();
	rightflameanimate2->retain();
	/*rightflame->runAction(leftflameanimate2);*/

	auto enginefiresprite3 = Sprite::create("flamerow3.png");
	auto enginefiretexture3 = enginefiresprite3->getTexture();
	auto animation3 = Animation::create();
	animation3->setDelayPerUnit(0.2);

	for (int i = 0; i < 4; i++)
	{
		animation3->addSpriteFrameWithTexture(enginefiretexture3, Rect(i * 50, 0, 50, 160));
	}

	leftflameanimate3 = Animate::create(animation3);
	rightflameanimate3 = Animate::create(animation3);
	leftflameanimate3->retain();
	rightflameanimate3->retain();

	auto enginefiresprite4 = Sprite::create("flamerow4.png");
	auto enginefiretexture4 = enginefiresprite4->getTexture();
	auto animation4 = Animation::create();
	animation4->setDelayPerUnit(0.2);

	for (int i = 0; i < 6; i++)
	{
		animation4->addSpriteFrameWithTexture(enginefiretexture4, Rect(i * 50, 0, 50, 160));
	}

	leftflameanimate4 = Animate::create(animation4);
	rightflameanimate4 = Animate::create(animation4);
	leftflameanimate4->retain();
	rightflameanimate4->retain();

	auto enginefiresprite5 = Sprite::create("flamerow5.png");
	auto enginefiretexture5 = enginefiresprite5->getTexture();
	auto animation5 = Animation::create();
	animation5->setDelayPerUnit(0.15);

	for (int i = 0; i < 3; i++)
	{
		animation5->addSpriteFrameWithTexture(enginefiretexture5, Rect(i * 51, 0, 51, 160));
	}
	for (int i = 0; i < 6; i++)
	{
		animation5->addSpriteFrameWithTexture(enginefiretexture5, Rect(155+i*66, 0,66, 160));
	}

	leftflameanimate5 = Animate::create(animation5);
	rightflameanimate5 = Animate::create(animation5);
	leftflameanimate5->retain();
	rightflameanimate5->retain();
	

	auto enginefiresprite6 = Sprite::create("flamerow6.png");
	auto enginefiretexture6 = enginefiresprite6->getTexture();
	auto animation6 = Animation::create();
	animation6->setDelayPerUnit(0.12);

	for (int i = 0; i < 7; i++)
	{
		animation6->addSpriteFrameWithTexture(enginefiretexture6, Rect(i * 65, 0, 65, 160));
	}

	leftflameanimate6 = Animate::create(animation6);
	rightflameanimate6 = Animate::create(animation6);
	leftflameanimate6->retain();
	rightflameanimate6->retain();
	


	auto callFunc = CallFunc::create(CC_CALLBACK_0(Enemy::AnimationCallback, this));

	leftflamesequence = Sequence::create(leftsmallflameanimate, leftsmallflameanimate, leftsmallflameanimate, leftsmallflameanimate, callFunc, nullptr);
	leftflamesequence->retain();
	rightflamesequence = Sequence::create(rightsmallflameanimate, rightsmallflameanimate, rightsmallflameanimate, rightsmallflameanimate,callFunc, nullptr);
	rightflamesequence->retain();

	int a=player->getPositionX(), b=boss->getPositionX();
	

	isCollided1 = true; // 충돌 체크를 한번만 실행하기 위한 플래그 변수
	isCollided2 = true;
	isCollided3 = true;
	arabian1Alive = true;
	arabian2Alive = true;
	arabian3Alive = true;


	this->scheduleUpdate();
	return true;
}

void Enemy::AnimationCallback()
{
	leftsmallflame->setVisible(false);
	rightsmallflame->setVisible(false);
	auto hideAction = Hide::create();
	auto movebyrightflame = MoveBy::create(0.5, Vec2(rightflame->getPositionX() - 20, rightflame->getPositionY()));
	auto reversemovebyrightflame = MoveBy::create(0.1, Vec2(rightflame->getPositionX() + 20, rightflame->getPositionY()));
	auto leftflameanimatesequnce = Sequence::create(leftflameanimate1, leftflameanimate2, leftflameanimate3, leftflameanimate4, leftflameanimate5, nullptr);
	auto rightflameanimatesequnce = Sequence::create(rightflameanimate1, rightflameanimate2, rightflameanimate3, rightflameanimate4, rightflameanimate5, nullptr);

	auto leftflamerep = RepeatForever::create(leftflameanimatesequnce);
	auto rightflamerep = RepeatForever::create(rightflameanimatesequnce);
	leftflame->runAction(leftflamerep);
	rightflame->setFlippedX(true);
	rightflame->runAction(rightflamerep);
	
	CCLOG("AnimationCallback");
}

void Enemy::update(float f)
{
	if (arabian1->getBoundingBox().intersectsRect(playerbullet1->getBoundingBox()) && isCollided1)
	{
		arabiandeath(arabian1,11,12);
		playerbullet1->setPosition(Vec2(0, 2000));
		isCollided1 = false;
		arabian1Alive = false;
	}
	if (arabian1->getBoundingBox().intersectsRect(bomb->getBoundingBox()) && isCollided1)
	{
		arabiandeath(arabian1, 11, 12);
		bomb->setPosition(Vec2(0, 2000));
		isCollided1 = false;
		arabian1Alive = false;
	}
	if (arabian2->getBoundingBox().intersectsRect(playerbullet1->getBoundingBox()) && isCollided2 )
	{
		arabiandeath(arabian2, 21, 22);
		playerbullet1->setPosition(Vec2(0, 2000));
		isCollided2 = false;
		arabian2Alive = false;
	}
	if (arabian2->getBoundingBox().intersectsRect(bomb->getBoundingBox()) && isCollided2)
	{
		arabiandeath(arabian2, 21, 22);
		bomb->setPosition(Vec2(0, 2000));
		isCollided2 = false;
		arabian2Alive = false;
	}
	if (arabian3->getBoundingBox().intersectsRect(playerbullet1->getBoundingBox()) && isCollided3 )
	{
		arabiandeath(arabian3, 31, 32);
		playerbullet1->setPosition(Vec2(0, 2000));
		isCollided3 = false;
		arabian3Alive = false;
	}
	if (arabian3->getBoundingBox().intersectsRect(bomb->getBoundingBox()) && isCollided3)
	{
		arabiandeath(arabian3, 31, 32);
		bomb->setPosition(Vec2(0, 2000));
		isCollided3 = false;
		arabian3Alive = false;
	}
	if (boss->getBoundingBox().intersectsRect(playerbullet1->getBoundingBox()) )
	{
		bosshp -= 1;
		playerbullet1->setPosition(Vec2(0, 2000));
		auto movebyright = MoveBy::create(0.1, Vec2(10, 0));
		auto moveleft = MoveBy::create(0.1, Vec2(-10, 0));
		auto shakeseq = Sequence::create(movebyright, moveleft, nullptr);
		auto shakelittle = Repeat::create(shakeseq, 3);

		auto movebyright2 = MoveBy::create(0.5, Vec2(100, -20));
		auto moveleft2 = MoveBy::create(0.5, Vec2(-100, -20));
		auto shakeseq2 = Sequence::create(movebyright2, moveleft2, nullptr);
		auto shakebig = Repeat::create(shakeseq2, 5);
		auto hideaction = Hide::create();
		auto shakeseq3 = Sequence::create(shakebig, hideaction , nullptr);

		auto turnred = TintTo::create(0.1f, Color3B::RED);
		auto returncolor = TintTo::create(0.1f, Color3B::WHITE);
		auto colorsequnce = Sequence::create(turnred, returncolor, nullptr);
		boss->runAction(colorsequnce);

		auto movetofar1 = MoveTo::create(0.1, Vec2(0, 3000));
		auto movetofar2 = MoveTo::create(0.1, Vec2(0, 3000));
		auto movetofar3 = MoveTo::create(0.1, Vec2(0, 3000));
		auto movetofar4 = MoveTo::create(0.1, Vec2(0, 3000));
		auto movetofar5 = MoveTo::create(0.1, Vec2(0, 3000));
		auto movetofar6 = MoveTo::create(0.1, Vec2(0, 3000));
		if (bosshp == 80)
		{
			boss->setTexture("boss22.png");
			boss->runAction(shakelittle);
		}
		if (bosshp == 80)
		{
			boss->setTexture("boss33.png");
			boss->runAction(shakelittle);
		}
		if (bosshp == 70)
		{
			boss->setTexture("boss44.png");
			boss->runAction(shakelittle);
		}
		if (bosshp ==0)
		{
			boss->setTexture("bossdeath.png");
			boss->runAction(shakeseq3);
			leftsmallflame->runAction(movetofar1);
			rightsmallflame->runAction(movetofar2);
			leftflame->runAction(movetofar3);
			rightflame->runAction(movetofar4);
			rightengine->runAction(movetofar5);
			leftengine->runAction(movetofar6);
		}
		
		CCLOG("%d", bosshp);
	}
	if (boss->getBoundingBox().intersectsRect(bomb->getBoundingBox()))
	{
		bosshp -= 10;
		bomb->setPosition(Vec2(0, 2000));
		auto movebyright = MoveBy::create(0.1, Vec2(10, 0));
		auto moveleft = MoveBy::create(0.1, Vec2(-10, 0));
		auto shakeseq = Sequence::create(movebyright, moveleft, nullptr);
		auto shakelittle = Repeat::create(shakeseq, 3);

		auto movebyright2 = MoveBy::create(0.5, Vec2(100, -20));
		auto moveleft2 = MoveBy::create(0.5, Vec2(-100, -20));
		auto shakeseq2 = Sequence::create(movebyright2, moveleft2, nullptr);
		auto shakebig = Repeat::create(shakeseq2, 5);
		auto hideaction = Hide::create();
		auto shakeseq3 = Sequence::create(shakebig, hideaction, nullptr);

		auto turnred = TintTo::create(0.1f, Color3B::RED);
		auto returncolor = TintTo::create(0.1f, Color3B::WHITE);
		auto colorsequnce = Sequence::create(turnred, returncolor, nullptr);
		boss->runAction(colorsequnce);

		auto movetofar1 = MoveTo::create(0.1, Vec2(0, 3000));
		auto movetofar2 = MoveTo::create(0.1, Vec2(0, 3000));
		auto movetofar3 = MoveTo::create(0.1, Vec2(0, 3000));
		auto movetofar4 = MoveTo::create(0.1, Vec2(0, 3000));
		auto movetofar5 = MoveTo::create(0.1, Vec2(0, 3000));
		auto movetofar6 = MoveTo::create(0.1, Vec2(0, 3000));
		if (bosshp > 80&& bosshp <= 90)
		{
			boss->setTexture("boss22.png");
			boss->runAction(shakelittle);
		}
		if (bosshp >70 && bosshp <= 80 )
		{
			boss->setTexture("boss33.png");
			boss->runAction(shakelittle);
		}
		if (bosshp > 60 && bosshp <= 70 )
		{
			boss->setTexture("boss44.png");
			boss->runAction(shakelittle);
		}
		if ( bosshp <= 50 )
		{
			boss->setTexture("bossdeath.png");
			boss->runAction(shakeseq3);
			leftsmallflame->runAction(movetofar1);
			rightsmallflame->runAction(movetofar2);
			leftflame->runAction(movetofar3);
			rightflame->runAction(movetofar4);
			rightengine->runAction(movetofar5);
			leftengine->runAction(movetofar6);
		}

		CCLOG("%d", bosshp);
	}

	if (player->getPositionX() == boss->getPositionX()&&bossidle)
	{
		leftsmallflame->stopAllActions();
		rightsmallflame->stopAllActions();
		rightengine->stopAllActions();
		leftengine->stopAllActions();
		boss->stopAllActions();
		boss->stopAllActions();

		leftsmallflame->runAction(leftflamesequence);
		rightsmallflame->runAction(rightflamesequence);
		rightengine->runAction(rightengineRep);
		leftengine->runAction(leftengineRep);
		boss->runAction(bossmoverepforever);
		boss->runAction(bossmoverepforever2);

		bossidle = false;
	}

	if (bosshp>0)
	{
		rightengine->setPosition(Vec2(boss->getPositionX() + 600, boss->getPositionY() + 150));
		leftengine->setPosition(Vec2(boss->getPositionX() + 23, boss->getPositionY() + 151));
		rightflame->setPosition(Vec2(boss->getPositionX() + 590, boss->getPositionY() - 352));
		leftflame->setPosition(Vec2(boss->getPositionX() + 72, boss->getPositionY() - 352));
		leftsmallflame->setPosition(Vec2(boss->getPositionX() + 97, boss->getPositionY() - 13));
		rightsmallflame->setPosition(Vec2(boss->getPositionX() + 623, boss->getPositionY() - 13));
	}
	
}

void Enemy::arabiandeath(cocos2d::Sprite* obj,int n1,int n2)
{
	obj->stopActionByTag(n1);
	obj->stopActionByTag(n2);
	
	auto sprite1 = Sprite::create("arabianDeath.png");
	auto texture1 = sprite1->getTexture();

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.12);

	for (int i = 0; i < 2; i++)
	{
		int column = i % 11;
		animation->addSpriteFrameWithTexture(texture1, Rect(column * 48, 0, 48, 50));
	}
	for (int i = 2; i <10; i++)
	{
		int column = i % 11;
		animation->addSpriteFrameWithTexture(texture1, Rect(96+column * 58, 0, 58, 50));
	}
	
	auto animate = Animate::create(animation);
	obj->runAction(animate);
	
	
}

void Enemy::arabianrunning1(cocos2d::Sprite* obj)
{
	animation2 = Animation::create();
	animation2->setDelayPerUnit(0.12);
	animation2->addSpriteFrameWithFile("arabianRunning1.png");
	animation2->addSpriteFrameWithFile("arabianRunning2.png");
	animation2->addSpriteFrameWithFile("arabianRunning3.png");
	animation2->addSpriteFrameWithFile("arabianRunning4.png");
	animation2->addSpriteFrameWithFile("arabianRunning5.png");
	animation2->addSpriteFrameWithFile("arabianRunning6.png");
	animation2->addSpriteFrameWithFile("arabianRunning7.png");
	animation2->addSpriteFrameWithFile("arabianRunning8.png");
	animation2->addSpriteFrameWithFile("arabianRunning9.png");
	animation2->addSpriteFrameWithFile("arabianRunning10.png");
	animation2->addSpriteFrameWithFile("arabianRunning11.png");
	animation2->addSpriteFrameWithFile("arabianRunning12.png");
	
	animate2 = Animate::create(animation2);
	rep1 = RepeatForever::create(animate2);
	obj->runAction(rep1);

	pMoveBy1 = MoveBy::create(10, Vec2(-2000, 0));
	obj->runAction(pMoveBy1);
	rep1->setTag(11);
	pMoveBy1->setTag(12);
}
void Enemy::arabianrunning2(cocos2d::Sprite* obj)
{
	animation2 = Animation::create();
	animation2->setDelayPerUnit(0.12);
	animation2->addSpriteFrameWithFile("arabianRunning1.png");
	animation2->addSpriteFrameWithFile("arabianRunning2.png");
	animation2->addSpriteFrameWithFile("arabianRunning3.png");
	animation2->addSpriteFrameWithFile("arabianRunning4.png");
	animation2->addSpriteFrameWithFile("arabianRunning5.png");
	animation2->addSpriteFrameWithFile("arabianRunning6.png");
	animation2->addSpriteFrameWithFile("arabianRunning7.png");
	animation2->addSpriteFrameWithFile("arabianRunning8.png");
	animation2->addSpriteFrameWithFile("arabianRunning9.png");
	animation2->addSpriteFrameWithFile("arabianRunning10.png");
	animation2->addSpriteFrameWithFile("arabianRunning11.png");
	animation2->addSpriteFrameWithFile("arabianRunning12.png");

	animate2 = Animate::create(animation2);
	rep2 = RepeatForever::create(animate2);
	obj->runAction(rep2);

	pMoveBy2 = MoveBy::create(10, Vec2(-2000, 0));
	obj->runAction(pMoveBy2);
	rep2->setTag(21);
	pMoveBy2->setTag(22);
}
void Enemy::arabianrunning3(cocos2d::Sprite* obj)
{
	animation2 = Animation::create();
	animation2->setDelayPerUnit(0.12);
	animation2->addSpriteFrameWithFile("arabianRunning1.png");
	animation2->addSpriteFrameWithFile("arabianRunning2.png");
	animation2->addSpriteFrameWithFile("arabianRunning3.png");
	animation2->addSpriteFrameWithFile("arabianRunning4.png");
	animation2->addSpriteFrameWithFile("arabianRunning5.png");
	animation2->addSpriteFrameWithFile("arabianRunning6.png");
	animation2->addSpriteFrameWithFile("arabianRunning7.png");
	animation2->addSpriteFrameWithFile("arabianRunning8.png");
	animation2->addSpriteFrameWithFile("arabianRunning9.png");
	animation2->addSpriteFrameWithFile("arabianRunning10.png");
	animation2->addSpriteFrameWithFile("arabianRunning11.png");
	animation2->addSpriteFrameWithFile("arabianRunning12.png");

	animate2 = Animate::create(animation2);
	rep3 = RepeatForever::create(animate2);
	obj->runAction(rep3);

	pMoveBy3 = MoveBy::create(10, Vec2(-2000, 0));
	obj->runAction(pMoveBy3);
	rep3->setTag(31);
	pMoveBy3->setTag(32);
}



