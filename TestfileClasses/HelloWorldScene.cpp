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
	this->addChild(wlayer); //addchild ����ߴ菉

	//��ü�� create �޼���� �����Ѵ�.
	//create �ż���� ��ü�� �����ϰ� �Ǹ� c++ new�� ���ؼ� ��ü�� �����ϰ�
	//delete�� �ڵ����� ȣ��Ǿ� �޸𸮿��� ��ü�� ���ŵȴ�.
	//auto�� ����ϸ� ���⼭�� ���� pCookie�� Ŭ���� Ÿ���� cocos2d::Sprite* �� �����ȴ�.
	auto pCookie = Sprite::create("Character/cookie.png");
	
	//Vector ũ��� �������� ���ǵǴ� ���̴�.
	//x,y: x��y ���� ���� �󸶳� �̵��ߴ°��� ǥ��
	pCookie->setPosition(Vec2(400, 360));
	//���ڰ� Ŭ���� �̹����� ���ʿ� ��ġ�ȴ�.
	pCookie->setLocalZOrder(2);
	this->addChild(pCookie);
	
	//��Ŀ����Ʈ. �⺻�� 0.5 0.5
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
