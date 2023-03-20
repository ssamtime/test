#include "Action01.h"

USING_NS_CC;

Scene* Action01::createScene()
{
	return Action01::create();
}

bool Action01::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	//��ü ��Ʈ ������ ����
	MenuItemFont::setFontSize(50);
	
	auto pMenuItem = MenuItemFont::create("Action",
		CC_CALLBACK_1(Action01::doAction, this));
	pMenuItem->setColor(Color3B::GREEN);

	//�޴� ����
	auto pMenu = Menu::create(pMenuItem, nullptr);
	pMenu->setPosition(Vec2(640, 360));
	this->addChild(pMenu);

	pCookie = Sprite::create("Character/cookie.png");
	pCookie->setPosition(Vec2(300, 400));
	this->addChild(pCookie);

	pCookieGirl = Sprite::create("Character/cookie_woman.png");
	pCookieGirl->setPosition(Vec2(300, 200));
	this->addChild(pCookieGirl);


	return true;
}

void Action01::doAction(Ref * pSender)
{
	//doActionMove();
	//doActionBezier();
	//doActionJump();
	//doActionRotate();
	//doActionScale();
	//doActionTint();

	//doActionPlace();
	//doActionBlink();
	//doActionShow();
	doActionFadeInOut();
}


void Action01::doActionMove()
{
	//by�� ���簪���� ������ ����ŭ ���ϴ� �׼� ����
	//to�� ������ ������ ���ϴ� �׼� ����
	auto myActionTo = MoveTo::create(2, Vec2(400, pCookie->getPosition().y));
	auto myActionBy = MoveBy::create(2, Vec2(400, 0));

	pCookie->runAction(myActionTo);
	pCookieGirl->runAction(myActionBy);
}

void Action01::doActionBezier()
{
	//��ü�� �ð����� ��� �׸��鼭 ��������
	//ccBezierConfig�� cocos2d-x���� ����� �ڷ����̸� ����,������1,������2�� �����Ǿ��ִ�.
	Vec2 startP = pCookie->getPosition();
	Vec2 middleP1 = Vec2(startP.x, startP.y + 200);
	Vec2 middleP2 = Vec2(startP.x+200, startP.y + 200);
	Vec2 endP = Vec2(startP.x + 400, startP.y);

	ccBezierConfig bezierConfig;
	bezierConfig.controlPoint_1 = middleP1;
	bezierConfig.controlPoint_2 = middleP2;
	bezierConfig.endPosition = endP;

	auto bezierTo = BezierTo::create(1.0, bezierConfig);
	pCookie->setPosition(startP);
	pCookie->runAction(bezierTo);

}

void Action01::doActionJump()
{
	//by�� ���簪���� ������ ����ŭ ���ϴ� �׼Ǽ���
	//to�� ������ ������ ���ϴ� �׼Ǽ���
	
	auto myActionTo = JumpTo::create(2, Vec2(pCookie->getPosition().x + 200,
		pCookie->getPosition().y), 50, 3);
	auto myActionBy = JumpBy::create(2, Vec2(pCookieGirl->getPosition().x + 200, 0), 50, 3);

	pCookie->runAction(myActionTo);
	pCookieGirl->runAction(myActionBy);
}

void Action01::doActionRotate()
{
	//RotateTo : ����� ����� ������ �ּ������� ȸ��
	//RotateBy : ���� ���ڸ�ŭ �ð�������� ȸ��
	//-degree�ϸ� �ð�ݴ�������� ȸ��

	auto myActionTo = RotateTo::create(1, 270);
	auto myActionBy = RotateBy::create(1, -270);
	pCookie->runAction(myActionTo);
	pCookieGirl->runAction(myActionBy);
}

void Action01::doActionScale()
{
	auto myActionTo = ScaleTo::create(1, 2.0);
	auto myActionBy = ScaleBy::create(1, 2.0);

	pCookie->runAction(myActionTo);
	pCookieGirl->runAction(myActionBy);
}

void Action01::doActionTint()
{
	//To�� ���������� RGB������ ����
	//By�� ���簪���� RGB���� �������� ����
	auto myActionTo = TintTo::create(1, 128, 128, 128);
	auto myActionBy = TintBy::create(1, 0, -30, 30);

	pCookie->runAction(myActionTo);
	pCookieGirl->runAction(myActionBy);
}

void Action01::doActionPlace()
{
	auto myAction = Place::create(Vec2(pCookie->getPosition().x + 300, 200));
	pCookie->runAction(myAction);
}

void Action01::doActionBlink()
{
	auto myAction = Blink::create(1, 5);
	pCookie->runAction(myAction);
}

void Action01::doActionShow()
{
	/*if (pCookie->isVisible())
	{
		auto myAction = Hide::create();
		pCookie->runAction(myAction);
	}
	else
	{
		auto myAction = Show::create();
		pCookie->runAction(myAction);
	}*/

	if (pCookie->isVisible())
	{
		pCookie->setVisible(false);
	}
	else
	{
		pCookie->setVisible(true);
	}
}

void Action01::doActionFadeInOut()
{
	if (pCookie->getOpacity() == 0)
	{
		auto myAction = FadeIn::create(1.5);
		pCookie->runAction(myAction);
	}
	else
	{
		auto myAction = FadeOut::create(1.5);
		pCookie->runAction(myAction);
	}
		
}
