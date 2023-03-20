#include "Action02.h"

USING_NS_CC;

Scene* Action02::createScene()
{
	return Action02::create();
}

bool Action02::init()
{
	if (!Scene::init())
	{
		return false;
	}


	/*auto wlayer = LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(wlayer);*/

	pBG1 = Sprite::create("Background/land.png");
	pBG1->setAnchorPoint(ccp(0, 0));
	pBG1->setPosition(Vec2(0, 0));
	this->addChild(pBG1);

	pBG2 = Sprite::create("Background/land.png");
	pBG2->setAnchorPoint(ccp(0, 0));
	pBG2->setPosition(Vec2(pBG1->getContentSize().width, 0));
	this->addChild(pBG2);

	

	//
	auto pMenuItem = MenuItemFont::create("Action",
		CC_CALLBACK_1(Action02::doAction, this));
	pMenuItem->setColor(Color3B::WHITE);
	
	//메뉴생성
	auto pMenu = Menu::create(pMenuItem, nullptr);
	//메뉴위치
	pMenu->setPosition(Vec2(640, 100));
	this->addChild(pMenu);

	pCookie = Sprite::create("Character/cookie.png");
	pCookie->setPosition(Vec2(300, 300));
	this->addChild(pCookie);

	return true;
}

void Action02::doAction(Ref * pSender)
{
	//pMan의 위치만 초기화해도 되지만, 
	//객체제거를 위한 또다른 메서드를 보여주기 위해 제거후 다시 생성을 했다.
	//this->removeChild(pMan,true);
	//this->removeChildByTag(11,true);
	pCookie->removeFromParentAndCleanup(true);

	pCookie->Sprite::create("Character/cookie.png");
	pCookie->setPosition(Vec2(300, 300));
	this->addChild(pCookie);

	//다음의 메서드호출을 하나씩 주석을 풀어가면서 실행을 해본다
	//this-> ActionSequence();
	//this-> ActionSpawn();
	//this-> ActionRepeat();
	//this-> ActionRepeatForever();
	//this-> ActionDelayTime();
	this->Actionscroll();
}

//시퀀스는 2개 이상의 액션에서 액션의 순서를 만들고 순차적으로 액션을 실행한다.
void Action02::ActionSequence()
{
	auto action = Sequence::create(
		MoveBy::create(2, Vec2(pCookie->getPosition().x + 400, 0)),
		RotateBy::create(2, 720), nullptr);

	pCookie->runAction(action);
}

//스폰은 등록된 모든 액션을 동시에 실행하는 액션이다.
//그런데 여기서 주의해야할 점은 시작시간이 같은 것이지
//액션이 끝나는 시간은 각 액션에서 지정한 시간에 따라 다르다는 점이다.
//만약 끝나는 시간이 서로 다른 액션으로 스폰을 구성하고 해당 스폰을 시퀀스의 구성요소로 등록했다면,
//액션 시간이 가장 긴 액션을 완료한 후에 다음에 등록된 액션이 실행된다.
void Action02::ActionSpawn()
{
	//4초에 4번 점프(1초당 1번)
	//회전은 2초만
	//그러므로 점프2번동안 회전하고, 나머지 시간에는 점프만 한다.
	auto action = Spawn::create(
		JumpBy::create(4, Vec2(400, 0), 50, 4),
		RotateBy::create(2, 720), nullptr);

	pCookie->runAction(action);
}

void Action02::ActionRepeat()
{
	auto myActionForward = MoveBy::create(1, Vec2(400, 0));
	auto myActionBackward = myActionForward->reverse();
	auto myAction = Sequence::create(myActionForward, myActionBackward, nullptr);

	auto rep1 = Repeat::create(myAction, 3);
	pCookie->runAction(rep1);
}

void Action02::ActionRepeatForever()
{
	auto myActionForward = MoveBy::create(0.5, Vec2(400, 0));
	auto myActionBackward = myActionForward->reverse();
	auto myAction = Sequence::create(myActionForward, myActionBackward, nullptr);

	auto rep = RepeatForever::create(myAction);
	pCookie->runAction(rep);
}

void Action02::ActionDelayTime()
{
	auto act1 = RotateTo::create(1, 150);
	auto act2 = RotateTo::create(1, 0);

	auto myAction = Sequence::create(
		DelayTime::create(2.0f), act1,
		DelayTime::create(1.0f), act2, nullptr);

	auto rep1 = RepeatForever::create(myAction);
	pCookie->runAction(rep1);
	
}

void Action02::Actionscroll()
{
	auto moveBackward1 = MoveBy::create(2, Vec2(-1963, 0));
	auto moveTo1 = MoveTo::create(0, Vec2(pBG2->getPositionX(), 0));
	auto seq1 = Sequence::create(moveBackward1, moveTo1, nullptr);
	auto rep1 = RepeatForever::create(seq1);
	pBG1->runAction(rep1);

	auto moveBackward2 = MoveBy::create(2, Vec2(-1963, 0));
	auto moveTo2 = MoveTo::create(0, Vec2(pBG1->getPositionX(), 0));
	auto seq2 = Sequence::create(moveBackward2, moveTo2, nullptr);
	auto rep2 = RepeatForever::create(seq2);
	pBG2->runAction(rep2);
}
