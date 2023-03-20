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
	//appdeligate�� �߰��ؾ�..
	auto white = Sprite::create("white-512x512.png");
	//�̹����� ���η� 150,���η� 150 �ȼ���ŭ �߶� �����ش�.
	white->setTextureRect(Rect(0, 0, 300, 150));
	white->setColor(Color3B::GREEN);
	white->setPosition(Vec2(640, 360));
	white->setScale(2); //ũ�� n��
	white->setOpacity(100);//���� ���� 0~255
	white->setVisible(true);//�̹����� �����ٰ��� ����
	white->setRotation(45.0); //�̹��� ȸ�� degree ����
	white->setFlippedX(true);//�̹����� x������ ������

	this->addChild(white);


	return true;
}
