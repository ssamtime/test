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

	//전체 폰트 사이즈 설정
	MenuItemFont::setFontSize(50);
	
	auto pMenuItem = MenuItemFont::create("Action",
		CC_CALLBACK_1(Action01::doAction, this));
	pMenuItem->setColor(Color3B::GREEN);

	//메뉴 생성
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
	//by는 현재값에서 지정한 값만큼 변하는 액션 수행
	//to는 지정한 값으로 변하는 액션 수행
	auto myActionTo = MoveTo::create(2, Vec2(400, pCookie->getPosition().y));
	auto myActionBy = MoveBy::create(2, Vec2(400, 0));

	pCookie->runAction(myActionTo);
	pCookieGirl->runAction(myActionBy);
}

void Action01::doActionBezier()
{
	//객체가 시간동안 곡선을 그리면서 지나간다
	//ccBezierConfig는 cocos2d-x에서 선언된 자료형이며 끝점,제어점1,제어점2로 구성되어있다.
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
	//by는 현재값에서 지정한 값만큼 변하는 액션수행
	//to는 지정한 값으로 변하는 액션수행
	
	auto myActionTo = JumpTo::create(2, Vec2(pCookie->getPosition().x + 200,
		pCookie->getPosition().y), 50, 3);
	auto myActionBy = JumpBy::create(2, Vec2(pCookieGirl->getPosition().x + 200, 0), 50, 3);

	pCookie->runAction(myActionTo);
	pCookieGirl->runAction(myActionBy);
}

void Action01::doActionRotate()
{
	//RotateTo : 결과에 가까운 쪽으로 최소한으로 회전
	//RotateBy : 적힌 숫자만큼 시계방향으로 회전
	//-degree하면 시계반대방향으로 회전

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
	//To는 절대적으로 RGB값으로 변경
	//By는 현재값에서 RGB값이 더해져서 변경
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
