#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer); //addchild 해줘야댐ㅎ

	//객체는 create 메서드로 생성한다.
	//create 매서드로 객체를 생성하게 되면 c++ new를 통해서 객체를 생성하고
	//delete가 자동으로 호출되어 메모리에서 객체가 제거된다.
	//auto를 사용하면 여기서는 변수 pCookie의 클래스 타입인 cocos2d::Sprite* 로 지정된다.
	auto pCookie = Sprite::create("Character/cookie.png");
	
	//Vector 크기와 방향으로 정의되는 값이다.
	//x,y: x나y 축을 따라 얼마나 이동했는가를 표시
	pCookie->setPosition(Vec2(400, 360));
	//숫자가 클수록 이미지가 앞쪽에 위치된다.
	pCookie->setLocalZOrder(2);
	this->addChild(pCookie);
	
	//앵커포인트. 기본은 0.5 0.5
	//pCookie->setAnchorPoint(Vec2(0, 0));
	//pCookie->setAnchorPoint(Vec2(0,1));
	//pCookie->setAnchorPoint(Vec2(1,1));
	
	auto pWoman = Sprite::create("Character/cookie_woman.png");
	pWoman->setPosition(Vec2(700, 360));
	pWoman->setLocalZOrder(2);
	this->addChild(pWoman);

	auto pBackground = Sprite::create("Background/land.png");
	pBackground->setPosition(Vec2(640, 360));
	this->addChild(pBackground);

    return true;
}
