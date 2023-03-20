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

	//��������Ʈ ��Ʈ �ؽ�ó�� ����� �������� ������ �����ϴ� ���� �ƴϰ�
	//�̸� ������ ���������� �̿��Ͽ� ������ �����Ѵ�.

	//��������Ʈ ��Ʈ�� ��ġ���������� �о���δ�.
	//���� ���丮�� plist�� ���� �̸��� png������ �־�� �Ѵ�.
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

	//���� ù��° ���������� ���ΰ� ��������Ʈ�� �����.
	auto pCookie = Sprite::createWithSpriteFrameName("run01.png");
	pCookie->setPosition(Vec2(248, 300));
	this->addChild(pCookie);

	//�ִϸ��̼� �����
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.12);
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	pCookie->runAction(rep);



	return true;
}
