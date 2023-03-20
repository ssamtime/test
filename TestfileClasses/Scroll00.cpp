#include "scroll00.h"

USING_NS_CC;

Scene* scroll00::createScene()
{
	return scroll00::create();
}

bool scroll00::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);
	
	/////////////////////
	layer1 = Layer::create();
	this->addChild(layer1);

	layer2 = Layer::create();
	this->addChild(layer2);

	//화면의 픽셀 크기를 구한다
	winSize = Director::getInstance()->getWinSize();

	//배경을 만든다.
	this->createBackground();
	//드래곤을 만든다.
	this->createDragon();
	//메뉴 버튼을만든다.
	this->createArrowButtons();


	
	return true;
}

void scroll00::createBackground()
{
	//배경 레이어1
	auto background1 = Sprite::create("Basic/background1.png");
	background1->setAnchorPoint(Vec2(0, 0));
	background1->setPosition(Vec2(0, 0));

	//배경 레이어2
	auto background2 = Sprite::create("Basic/background2.png");
	background2->setAnchorPoint(Vec2(0, 0));
	background2->setPosition(1280, 0);

	//이미지가 만나는 가장자리 (edge)에 검은 선이 생기는 것을 방지하기 위하여 Anti=Alising을 끈다.
	background1->getTexture()->setAliasTexParameters();
	background2->getTexture()->setAliasTexParameters();
	
	//배경 스프라이트를 레이어에 넣는다
	layer1->addChild(background1);
	layer2->addChild(background2);
}

void scroll00::createDragon()
{
	//움직이는 드래곤 넣기 시작
	auto texture = Director::getInstance()->getTextureCache()->addImage("Basic/dragon_animation.png");

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.2f);

	for (int i = 0; i < 6; i++)
	{
		int index = 1 % 4;
		int rowIndex = i / 4;

		animation->addSpriteFrameWithTexture(texture, Rect(index * 138, rowIndex * 148 + 70, 110, 70));

	}

	//스프라이트 생성 및 초기화
	dragon = Sprite::createWithTexture(texture, Rect(0, 70, 110, 70));
	dragon->setPosition(Vec2(240, 360));
	dragon->setFlippedX(true);
	dragon->setScale(2);
	layer1->addChild(dragon);

	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	dragon->runAction(rep);
}

void scroll00::createArrowButtons()
{
	//leftSprite = Sprite::create("Basic/b1.png");
	//leftSprite->setPosition(Vec2(180, 70));

	////이동 버튼으로 사용할 버튼은 layer2에 추가한다.
	//layer2->addChild(leftSprite, 2);

	////눌렀을 때 쓰일 화살표
	//leftPressedSprite = Sprite::create("Basic/b2.png");
	//leftPressedSprite->setPosition(leftSprite->getPosition());

	//layer2->addChild(leftSprite, 1);

	////오른쪽 화살표
	//rightSprite = Sprite::create("Basic/f1.png");
	//rightSprite->setPosition(Vec2(300, 70));

	//layer2->addChild(rightSprite, 2);

	////눌렀을 때 쓰일 오른쪽 화살표
	//rightPressedSprite = Sprite::create("Basic/f2.png");
	//rightPressedSprite->setPosition(rightSprite->getPosition());

	//layer2->addChild(rightPressedSprite, 1);
}

void scroll00::onEnter()
{
	Scene::onEnter();
}

void scroll00::onExit()
{
	Scene::onExit();
}

void scroll00::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * evnet)
{
}

void scroll00::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * evnet)
{
}

void scroll00::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * evnet)
{
}

bool scroll00::isTouchInside(cocos2d::Sprite * sprite, cocos2d::Touch * touch)
{
	return false;
}

void scroll00::startMovingBackground()
{
}

void scroll00::stopMovingBackground()
{
}

void scroll00::moveBackground(float t)
{
}
