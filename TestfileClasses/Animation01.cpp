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

	//다양한 방법으로 스프라이트 시트 텍스처를 만든다.
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
	
	//한줄에 4장이 끝이라서 사이즈 계산해줘야댐
	for (int i = 0; i < 4; i++)
	{
		int column = i % 4;
		animation->addSpriteFrameWithTexture(texture1, Rect(column * 174, 0, 174, 197));
		
	}

	//스프라이트 생성 및 초기화
	auto pCookie = Sprite::createWithTexture(texture1, Rect(0, 0, 18.5, 19.3));
	pCookie->setPosition(640, 360);
	this->addChild(pCookie);

	//애니메이션 액션 실행
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	pCookie->runAction(rep);

	return true;
}
