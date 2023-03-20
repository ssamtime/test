#include "Physics01.h"

USING_NS_CC;

Scene* Physics01::createScene()
{
	return Physics01::create();
}

bool Physics01::init()
{
	if (Scene::initWithPhysics())
	{
		createMyPhysicalWorld();
	}
	else
	{
		return false;
	}
	///////////////////

	//윈도우 크기 받아옴
	auto visibleSize = _director->getVisibleSize();

	//정적 객체용 스프라이트
	auto sprite = Sprite::create("r1.png");
	sprite->setPosition(Vec2(visibleSize)*0.5f);

	//강체설정
	//강체: 추상적인 객체의 물리속성을 설명한다.
	//질량, 위치, 회전각도, 속도와 저항을 포함한다.
	//cocos2d-x 안에서는 physicalbody가 강체이다.
	auto body = PhysicsBody::createCircle(sprite->getContentSize().width / 2);

	// setDynamic(bool): 객체의 물리속성을 동적,정적으로 설정
	body->setDynamic(false); //정적으로설정

	//setContactTestBisMark(int) : 어떠한 객체와 닿았을 때 충돌잉 발생하는 설정
	body->setContactTestBitmask(1);

	//setCollisionBitmask(int)" 충돌하기위한 번호를 개별설정
	body->setCollisionBitmask(2);

	sprite->setPhysicsBody(body);
	this->addChild(sprite);

	//------------------------------

	//터치 이벤트 리스너
	auto touch = EventListenerTouchOneByOne::create();
	touch->onTouchBegan = CC_CALLBACK_2(Physics01::onTouchBegan, this);
	touch->onTouchEnded = CC_CALLBACK_2(Physics01::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);

	//충돌 이벤트 리스너
	auto contact = EventListenerPhysicsContact::create();
	contact->onContactBegin = CC_CALLBACK_1(Physics01::onContactBegin, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(contact, this);

	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	return true;
}

void Physics01::createMyPhysicalWorld()
{
	//물리효과가 적용된 스크린 바운더리 설정
	//중력이 적용되는 범위와 중력의 세기, 방향을 설정
	auto visibleSize = _director->getVisibleSize();

	//중력을설정하지 않읅경우
	//gravity Vexxt2((0.0f,-98.0)
	Vect gravity = Vect(0.01, -128.0);


	//현재scene의 physicsWorld의 정보를 받아온다.
	m_world = this->getPhysicsWorld();

	//setDebugDrawMask():물리 시뮬레이션이 적용된 객체의 판정박스표시
	m_world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//setGravity(): 중력의 방향과 세기를 결정
	m_world->setGravity(gravity);

	//setSpeed(): 낙하에 따른 중력가속도를 설정
	m_world->setSpeed(2.0f);

	//setsubsteps()" 프레임간의 물리연상횟수를 설정
	m_world->setSubsteps(5);

	//------------------------
	//PhysicalBody :: createEdgeBox

	/*
	제1매개변수 :물링 시뮬레이션이 적용될 범위설정
	제2매개변수: 물체의 밀도,반발력 ,마찰력
	제3매개변수:디버그박스의 두께
	*/
	auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 5);

	//물리 시뮬레이션을 적용될 객체
	auto edgeNode = Node::create();

	//Node 위치를 조정하여 물리효과가 화면 전체를 뒤덮도록한다.
	edgeNode->setPosition(Vec2(visibleSize)*0.5f);
	edgeNode->setPhysicsBody(body);

	this->addChild(edgeNode);
}

bool Physics01::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{

	return true;
}

void Physics01::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto touchPoint = touch->getLocation();
	addNewSpriteAtPosition(touchPoint);
}

bool Physics01::onContactBegin(cocos2d::PhysicsContact & contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getCollisionBitmask();
	auto nodeB = contact.getShapeB()->getBody()->getCollisionBitmask();

	if ((nodeA == 1 && nodeB == 2) || (nodeB == 1 && nodeA == 2))
	{
		log("충돌이 발생했습니다.");
	}

	return true;
}

void Physics01::addNewSpriteAtPosition(cocos2d::Vec2 pos)
{
	//스프라이트 객체생성
	auto sprite = Sprite::create("r1.png");

	sprite->setPosition(pos);
	sprite->setScale(0.5f);

	//physicsBody생성
	auto body = PhysicsBody::createCircle(sprite->getContentSize().width / 2);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);

	sprite->setPhysicsBody(body);
	this->addChild(sprite);
}


