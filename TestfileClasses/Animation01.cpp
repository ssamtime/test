#include "Animation01.h"

USING_NS_CC;

Scene* Animation01::createScene()
{
	return Animation01::create();
}

bool Animation01::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	//�پ��� ������� ��������Ʈ ��Ʈ �ؽ�ó�� �����.
	/*
	*----------------------------------
	Type 1 : from Sprite
	*----------------------------------
	*/
	auto sprite = Sprite::create("Animation/run_sheet.png");
	auto texture1 = sprite->getTexture();

	/*
	*----------------------------------
	Type 1 : from Texture
	*----------------------------------
	*/
	//auto texture2 = Director::getInstance()->getTextureCache()->addImage("Animation/run_sheet");

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.12);
	
	//���ٿ� 4���� ���̶� ������ �������ߴ�
	for (int i = 0; i < 4; i++)
	{
		int column = i % 4;
		animation->addSpriteFrameWithTexture(texture1, Rect(column * 174, 0, 174, 197));
		
	}

	//��������Ʈ ���� �� �ʱ�ȭ
	auto pCookie = Sprite::createWithTexture(texture1, Rect(0, 0, 18.5, 19.3));
	pCookie->setPosition(640, 360);
	this->addChild(pCookie);

	//�ִϸ��̼� �׼� ����
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	pCookie->runAction(rep);

	return true;
}
