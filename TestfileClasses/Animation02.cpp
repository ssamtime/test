#include "Animation02.h"

USING_NS_CC;

Scene* Animation02::createScene()
{
	return Animation02::create();
}

bool Animation02::init()
{
	if (!Scene::init())
	{
		return false;
	}

	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	//스프라이트 시트 텍스처를 만들어 수동으로 파일을 구분하는 것이 아니고
	//미리 지정한 정보파일을 이용하여 파일을 구분한다.

	//스프라이트 시트의 위치정보파일을 읽어들인다.
	//같은 디렉토리에 plist와 같은 이름의 png파일이 있어야 한다.
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Animation/spritesheet.plist");

	Vector<SpriteFrame*> animFrames;

	char str[100] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		sprintf(str, "run0%d.png", i + 1);
		SpriteFrame* frame = cache->getSpriteFrameByName(str);
		animFrames.pushBack(frame);
	}

	//제일 첫번째 프레임으로 주인공 스프라이트를 만든다.
	auto pCookie = Sprite::createWithSpriteFrameName("run01.png");
	pCookie->setPosition(Vec2(248, 300));
	this->addChild(pCookie);

	//애니메이션 만들기
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.12);
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	pCookie->runAction(rep);



	return true;
}
