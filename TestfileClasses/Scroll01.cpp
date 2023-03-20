#include "Scroll01.h"

USING_NS_CC;

Scene* Scroll01::createScene()
{
    return Scroll01::create();
}

// on "init" you need to initialize your instance
bool Scroll01::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

	auto wlayer = 
		LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	////////////////////////////////
	layer1 = Layer::create();
	this->addChild(layer1);

	layer2 = Layer::create();
	this->addChild(layer2);

	// 화면의 픽셀 크기를 구한다.
	winSize = Director::getInstance()->
		getWinSize();

	// 배경을 만든다.
	this->createBackground();

	//// 드래곤을 만든다.
	this->createDragon();

	//// 메뉴 버튼을 만든다.
	this->createArrowButtons();
	
    return true;
}

void Scroll01::createBackground()
{
	// 배경 레이어 1
	auto background1 =
		Sprite::
		create
		("Images/background1.png");
	background1->setAnchorPoint(Vec2(0, 0));
	background1->setPosition(Vec2(0, 0));

	// 배경 레이어 2
	auto background2 =
		Sprite::
		create
		("Images/background2.png");
	background2->setAnchorPoint(Vec2(0, 0));
	background2->setPosition(1280, 0);

	// 이미지가 만나는 가장자리(edge)에 검은
	// 선이 생기는 것을 방지하기 위하여
	// Anti-Aliasing을 끈다.
	background1->getTexture()->
		setAliasTexParameters();
	background2->getTexture()->
		setAliasTexParameters();

	// 배경 스프라이트를 레이어에 넣는다.
	layer1->addChild(background1);
	layer1->addChild(background2);
}

void Scroll01::createDragon()
{
	// 움직이는 드래곤 넣기 시작
	auto texture = Director::getInstance()
		->getTextureCache()
		->addImage
		("Images/dragon_animation.png");

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.2f);

	for (int i = 0; i < 6; i++)
	{
		int index = i % 4;
		int rowIndex = i / 4;

		animation->addSpriteFrameWithTexture(texture,
				Rect(index * 138, rowIndex * 148 + 70, 110, 70));
	}

	// 스프라이트 생성 및 초기화
	dragon = Sprite::createWithTexture
	(texture, Rect(0, 70, 110, 70));
	dragon->setPosition(Vec2(240, 360));
	dragon->setFlippedX(true);
	dragon->setScale(2);
	layer1->addChild(dragon);

	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	dragon->runAction(rep);

}

void Scroll01::createArrowButtons()
{
	leftSprite = Sprite::create("Images/b1.png");
	leftSprite->setPosition(Vec2(180, 70));

	// 이동 버튼으로 사용할 버튼은 layer2에 추가한다.
	layer2->addChild(leftSprite, 2);

	// 눌렀을 때 쓰일 화살표
	leftPressedSprite =
		Sprite::create("Images/b2.png");
	leftPressedSprite->
		setPosition(leftSprite->getPosition());

	layer2->addChild(leftPressedSprite, 1);

	// 오른쪽 화살표
	rightSprite = Sprite::create("Images/f1.png");
	rightSprite->setPosition(Vec2(300, 70));

	layer2->addChild(rightSprite, 2);

	// 눌렀을 때 쓰일 오른쪽 화살표
	rightPressedSprite =
		Sprite::create("Images/f2.png");
	rightPressedSprite->
		setPosition(rightSprite->getPosition());
	layer2->addChild(rightPressedSprite, 1);
}


void Scroll01::onEnter()
{
	Scene::onEnter();

	// 싱글터치 모드로 터치리스너 등록
	listener = 
		EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = 
		CC_CALLBACK_2(Scroll01::onTouchBegan, 
			this);
	listener->onTouchMoved =
		CC_CALLBACK_2(Scroll01::onTouchMoved,
			this);
	listener->onTouchEnded =
		CC_CALLBACK_2(Scroll01::onTouchEnded
			, this);

	_eventDispatcher->
		addEventListenerWithSceneGraphPriority
		(listener, this);
}

void Scroll01::onExit()
{
	_eventDispatcher->
		removeEventListener(listener);
	Scene::onExit();
}

// 손가락이 닫는 순간 호출된다.
bool Scroll01::onTouchBegan(Touch* touch,
	Event* event)
{
	// 아래 boolean 변수 대신에
	// leftSprite와 rightSprite의 visible값을
	// 직접 사용해도 무방하다.
	isLeftPressed = false;
	isRightPressed = false;

	// 터치가 왼쪽 또는 오른쪽 화살표 안에 들어왔는지
	// 확인한다.
	if (this->isTouchInside(leftSprite, 
		touch) == true)
	{
		leftSprite->setVisible(false);
		isLeftPressed = true;
	}
	else if (this->isTouchInside(rightSprite,
		touch) == true)
	{
		rightSprite->setVisible(false);
		isRightPressed = true;
	}

	// 버튼이 눌러졌으면 화면을 움직인다.
	if (isLeftPressed == true || 
		isRightPressed == true)
	{
		this->startMovingBackground();
	}

	return true;
}

// 손가락을 화면에서 떼지 않고 이리저리 움직일 때
// 계속해서 호출된다.
void Scroll01::onTouchMoved(Touch* touch,
	Event* event)
{
	// 손가락이 버튼을 벗어나면 움직임을 중단한다.
	if (isLeftPressed == true &&
		this->isTouchInside(leftSprite, touch)
		== false)
	{
		leftSprite->setVisible(true);
		this->stopMovingBackground();
	}
	else if (isRightPressed == true &&
		this->isTouchInside(rightSprite, touch)
		== false)
	{
		rightSprite->setVisible(true);
		this->stopMovingBackground();
	}
}

void Scroll01::onTouchEnded
(Touch* touch, Event* evnet)
{
	// 배경 화면을 멈춘다.
	if (isLeftPressed == true 
		|| isRightPressed == true)
		this->stopMovingBackground();

	// 감춰뒀던 버튼이미지를 다시 보이게 할거에요.
	if (isLeftPressed == true)
		leftSprite->setVisible(true);

	if (isRightPressed == true)
		rightSprite->setVisible(true);
}

// 터치가 버튼 sprite안에서 이루어졌는지 확인한다.
bool Scroll01::isTouchInside(Sprite* sprite,
	Touch* touch)
{
	auto touchPoint = touch->getLocation();

	bool bTouch = sprite->getBoundingBox().
		containsPoint(touchPoint);

	return bTouch;
}

void Scroll01::startMovingBackground()
{
	// 만약에 버튼 두개가 다 눌러졌으면
	// 화면을 이동시키지 않는다.
	if (isLeftPressed == true &&
		isRightPressed == true)
		return;

	log("start moving");

	this->schedule(
		schedule_selector
		(Scroll01::moveBackground));
}

void Scroll01::stopMovingBackground()
{
	log("stop moving");
	this->unschedule(
		schedule_selector
		(Scroll01::moveBackground));
}

void Scroll01::moveBackground(float t)
{
	// 매 프레임마다 움직일 거리
	auto moveStep = 5;
	if (isLeftPressed)
	{
		moveStep = -5;
		dragon->setFlippedX(false);
	}
	else
	{
		moveStep = 5;
		dragon->setFlippedX(true);
	}
		
	auto newPos =
		Vec2(dragon->getPosition().x + moveStep,
			dragon->getPosition().y);

	if (newPos.x < 0)
		newPos.x = 0;
	else if (newPos.x > 1280 * 2)
	{
		newPos.x = 1280 * 2;
	}

	dragon->setPosition(newPos);

	layer1->runAction(Follow::create(dragon, 
		Rect(0, 0, 1280 * 2, 720)));
	log("moving background");
}