#include "Action03.h"

USING_NS_CC;

Scene* Action03::createScene()
{
	return Action03::create();
}

bool Action03::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	auto pMenuItem = MenuItemFont::create("Action",
		CC_CALLBACK_1(Action03::doAction, this));
	pMenuItem->setColor(Color3B::BLACK);

	//메뉴생성
	auto pMenu = Menu::create(pMenuItem, nullptr);

	//메뉴
	pMenu->setPosition(Vec2(640, 100));

	this->addChild(pMenu);

	//동그란 버튼 스프라이트 추가
	pBall = Sprite::create("Character/pet.png");
	pBall->setPosition(Vec2(100, 200));
	pBall->setScale(0.7f);
	this->addChild(pBall);

	//cookie1 sprite 추가
	pCookie = Sprite::create("Character/cookie.png");
	pCookie->setPosition(Vec2(100, 350));
	pCookie->setScale(0.5);
	this->addChild(pCookie);

	//cookiewoman 1,2 sprite추가
	pCookiewoman1 = Sprite::create("Character/cookie_woman.png");
	pCookiewoman1->setPosition(Vec2(100, 500));
	pCookiewoman1->setScale(0.5);
	this->addChild(pCookiewoman1);

	pCookiewoman2 = Sprite::create("Character/cookie_woman2.png");
	pCookiewoman2->setPosition(Vec2(100, 650));
	pCookiewoman2->setScale(0.5);
	this->addChild(pCookiewoman2);


	return true;
}

void Action03::doAction(Ref * pSender)
{
	//Reset
	pBall->setPosition(Vec2(100, 200));
	pCookie->setPosition(Vec2(100, 350));
	pCookiewoman1->setPosition(Vec2(100, 500));
	pCookiewoman2->setPosition(Vec2(100, 650));

	//doActionEase();
	//doActionElastic();
	//doActionBounce();
	doActionSpeed();
}

//이즈액션 사용하기
/*
이즈 액션은 액션 내부의 액션기간을 수정하는 특별한 복합 액션이다.
일반적인 액션의 경우 시간의 흐름에 따른 액션의 수행량은 일정하다.
이즈액션은 선형적인 액션의 동작 기간을 수정한다.
예를 들면 내부 액션을 가속화하거나 저속화한다.
- EaseIn : 액션이 처음에 느렸다가 끝에서 빨라진다.
- EaseOut : 첨 빨랐다가 느려짐
- EaseInOut : 처음에 느렸다가 중간에 빨라지고 다시 느려짐

*/
void Action03::doActionEase()
{
	//정상속도
	auto move = MoveBy::create(3.0f, Vec2(400, 0));
	//처음에 느렸다가 빨라지기
	auto ease_in = EaseIn::create(move->clone(), 3.0f);
	//느려지기 : 빨랐다가 느려지기
	auto ease_out = EaseOut::create(move->clone(), 3.0f);
	//빨라졌다가 느려지기: 시작 끝느리고 중간 빠름
	auto ease_inout = EaseInOut::create(move->clone(), 3.0f);

	pBall->runAction(move);
	pCookie->runAction(ease_in);
	pCookiewoman1->runAction(ease_out);
	pCookiewoman2->runAction(ease_inout);
}

//탄성
/*
 이 액션은 탄성 시뮬레이션 기간을 수정한다.
 탄성 액션은 0보다 크고 1보다 작은 time 값을 사용하며 내부액션은 특정값에의해 영향을 받는다.
  
  -두번째 파라미터인 'period'파라미터에서 얼마만큼 탄력적인가를 지정
  - 기본값: 0.3
  - 권고값: 0.3부터 0.45
*/
void Action03::doActionElastic()
{
	//정상속도
	auto move = MoveBy::create(3.0f, Vec2(400, 0));

	//탄성--------------------------------------------------
	auto ease_in = EaseElasticIn::create(move->clone(), 0.4f);
	auto ease_out = EaseElasticOut::create(move->clone(), 0.4f);
	auto ease_inout = EaseElasticInOut::create(move->clone(), 0.4f);

	pBall->runAction(move);
	pCookie->runAction(ease_in);
	pCookiewoman1->runAction(ease_out);
	pCookiewoman2->runAction(ease_inout);
	
}

//이즈 바운스 액션은 통통 튀기는 효과를 시뮬레이션 한다.
/*
주의점 : MoveBy, ScaleBy, RotateBy 와 같은 간단한 액션은 이즈 바운스액션에 적용해도 무방하지만
sequence 또는 Spawn 액션은 예상치 못한 결과를 얻을 수 있다.
*/
void Action03::doActionBounce()
{
	//정상 속도
	auto move = MoveBy::create(3.0f, Vec2(480, 0));
	//바운스 -------------
	auto ease_in = EaseBounceIn::create(move->clone());
	auto ease_out = EaseBounceOut::create(move->clone());
	auto ease_inout = EaseBounceInOut::create(move->clone());

	pBall->runAction(move);
	pCookie->runAction(ease_in);
	pCookiewoman1->runAction(ease_out);
	pCookiewoman2->runAction(ease_inout);
}

//스피드 액션은 내부 액션의 속도를 높인다,
/*
 사용 예) 캐릭터가 아이템을 먹으면 속도가 일정시간동안 높아지거나 낮아지는것
*/
void Action03::doActionSpeed()
{
	//정상속도
	auto move = MoveBy::create(3.0f, Vec2(480, 0));

	//스피드
	auto ease_in = Speed::create(move->clone(), 1.0f);
	auto ease_out = Speed::create(move->clone(), 2.0f);
	auto ease_inout = Speed::create(move->clone(), 3.0f);

	pBall->runAction(move);
	pCookie->runAction(ease_in);
	pCookiewoman1->runAction(ease_out);
	pCookiewoman2->runAction(ease_inout);
}

