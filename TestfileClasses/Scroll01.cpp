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

	// ȭ���� �ȼ� ũ�⸦ ���Ѵ�.
	winSize = Director::getInstance()->
		getWinSize();

	// ����� �����.
	this->createBackground();

	//// �巡���� �����.
	this->createDragon();

	//// �޴� ��ư�� �����.
	this->createArrowButtons();
	
    return true;
}

void Scroll01::createBackground()
{
	// ��� ���̾� 1
	auto background1 =
		Sprite::
		create
		("Images/background1.png");
	background1->setAnchorPoint(Vec2(0, 0));
	background1->setPosition(Vec2(0, 0));

	// ��� ���̾� 2
	auto background2 =
		Sprite::
		create
		("Images/background2.png");
	background2->setAnchorPoint(Vec2(0, 0));
	background2->setPosition(1280, 0);

	// �̹����� ������ �����ڸ�(edge)�� ����
	// ���� ����� ���� �����ϱ� ���Ͽ�
	// Anti-Aliasing�� ����.
	background1->getTexture()->
		setAliasTexParameters();
	background2->getTexture()->
		setAliasTexParameters();

	// ��� ��������Ʈ�� ���̾ �ִ´�.
	layer1->addChild(background1);
	layer1->addChild(background2);
}

void Scroll01::createDragon()
{
	// �����̴� �巡�� �ֱ� ����
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

	// ��������Ʈ ���� �� �ʱ�ȭ
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

	// �̵� ��ư���� ����� ��ư�� layer2�� �߰��Ѵ�.
	layer2->addChild(leftSprite, 2);

	// ������ �� ���� ȭ��ǥ
	leftPressedSprite =
		Sprite::create("Images/b2.png");
	leftPressedSprite->
		setPosition(leftSprite->getPosition());

	layer2->addChild(leftPressedSprite, 1);

	// ������ ȭ��ǥ
	rightSprite = Sprite::create("Images/f1.png");
	rightSprite->setPosition(Vec2(300, 70));

	layer2->addChild(rightSprite, 2);

	// ������ �� ���� ������ ȭ��ǥ
	rightPressedSprite =
		Sprite::create("Images/f2.png");
	rightPressedSprite->
		setPosition(rightSprite->getPosition());
	layer2->addChild(rightPressedSprite, 1);
}


void Scroll01::onEnter()
{
	Scene::onEnter();

	// �̱���ġ ���� ��ġ������ ���
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

// �հ����� �ݴ� ���� ȣ��ȴ�.
bool Scroll01::onTouchBegan(Touch* touch,
	Event* event)
{
	// �Ʒ� boolean ���� ��ſ�
	// leftSprite�� rightSprite�� visible����
	// ���� ����ص� �����ϴ�.
	isLeftPressed = false;
	isRightPressed = false;

	// ��ġ�� ���� �Ǵ� ������ ȭ��ǥ �ȿ� ���Դ���
	// Ȯ���Ѵ�.
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

	// ��ư�� ���������� ȭ���� �����δ�.
	if (isLeftPressed == true || 
		isRightPressed == true)
	{
		this->startMovingBackground();
	}

	return true;
}

// �հ����� ȭ�鿡�� ���� �ʰ� �̸����� ������ ��
// ����ؼ� ȣ��ȴ�.
void Scroll01::onTouchMoved(Touch* touch,
	Event* event)
{
	// �հ����� ��ư�� ����� �������� �ߴ��Ѵ�.
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
	// ��� ȭ���� �����.
	if (isLeftPressed == true 
		|| isRightPressed == true)
		this->stopMovingBackground();

	// ����״� ��ư�̹����� �ٽ� ���̰� �Ұſ���.
	if (isLeftPressed == true)
		leftSprite->setVisible(true);

	if (isRightPressed == true)
		rightSprite->setVisible(true);
}

// ��ġ�� ��ư sprite�ȿ��� �̷�������� Ȯ���Ѵ�.
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
	// ���࿡ ��ư �ΰ��� �� ����������
	// ȭ���� �̵���Ű�� �ʴ´�.
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
	// �� �����Ӹ��� ������ �Ÿ�
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