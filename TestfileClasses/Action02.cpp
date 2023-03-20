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
	
	//�޴�����
	auto pMenu = Menu::create(pMenuItem, nullptr);
	//�޴���ġ
	pMenu->setPosition(Vec2(640, 100));
	this->addChild(pMenu);

	pCookie = Sprite::create("Character/cookie.png");
	pCookie->setPosition(Vec2(300, 300));
	this->addChild(pCookie);

	return true;
}

void Action02::doAction(Ref * pSender)
{
	//pMan�� ��ġ�� �ʱ�ȭ�ص� ������, 
	//��ü���Ÿ� ���� �Ǵٸ� �޼��带 �����ֱ� ���� ������ �ٽ� ������ �ߴ�.
	//this->removeChild(pMan,true);
	//this->removeChildByTag(11,true);
	pCookie->removeFromParentAndCleanup(true);

	pCookie->Sprite::create("Character/cookie.png");
	pCookie->setPosition(Vec2(300, 300));
	this->addChild(pCookie);

	//������ �޼���ȣ���� �ϳ��� �ּ��� Ǯ��鼭 ������ �غ���
	//this-> ActionSequence();
	//this-> ActionSpawn();
	//this-> ActionRepeat();
	//this-> ActionRepeatForever();
	//this-> ActionDelayTime();
	this->Actionscroll();
}

//�������� 2�� �̻��� �׼ǿ��� �׼��� ������ ����� ���������� �׼��� �����Ѵ�.
void Action02::ActionSequence()
{
	auto action = Sequence::create(
		MoveBy::create(2, Vec2(pCookie->getPosition().x + 400, 0)),
		RotateBy::create(2, 720), nullptr);

	pCookie->runAction(action);
}

//������ ��ϵ� ��� �׼��� ���ÿ� �����ϴ� �׼��̴�.
//�׷��� ���⼭ �����ؾ��� ���� ���۽ð��� ���� ������
//�׼��� ������ �ð��� �� �׼ǿ��� ������ �ð��� ���� �ٸ��ٴ� ���̴�.
//���� ������ �ð��� ���� �ٸ� �׼����� ������ �����ϰ� �ش� ������ �������� ������ҷ� ����ߴٸ�,
//�׼� �ð��� ���� �� �׼��� �Ϸ��� �Ŀ� ������ ��ϵ� �׼��� ����ȴ�.
void Action02::ActionSpawn()
{
	//4�ʿ� 4�� ����(1�ʴ� 1��)
	//ȸ���� 2�ʸ�
	//�׷��Ƿ� ����2������ ȸ���ϰ�, ������ �ð����� ������ �Ѵ�.
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
