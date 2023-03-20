#include "image01.h"

USING_NS_CC;

Scene* Image01::createScene()
{
	return Image01::create();
}

bool Image01::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);
	//appdeligate에 추가해야..
	auto white = Sprite::create("white-512x512.png");
	//이미지를 가로로 150,세로로 150 픽셀만큼 잘라서 보여준다.
	white->setTextureRect(Rect(0, 0, 300, 150));
	white->setColor(Color3B::GREEN);
	white->setPosition(Vec2(640, 360));
	white->setScale(2); //크기 n배
	white->setOpacity(100);//투명도 설정 0~255
	white->setVisible(true);//이미지를 보여줄건지 설정
	white->setRotation(45.0); //이미지 회전 degree 기준
	white->setFlippedX(true);//이미지를 x축으로 뒤집음

	this->addChild(white);


	return true;
}
