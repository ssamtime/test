//참고 사이트
//https://dygks910910.tistory.com/77
#include "physics00.h"

USING_NS_CC;

Scene* physics00::createScene()
{
	return physics00::create();
}

bool physics00::init()
{
	//1.initWithPhysics를 사용하면 물리월드를 포함한 씬을 생성할 수 있다.
	if (Scene::initWithPhysics())
	{
		createMyPhysicsWorld();
	}
	else
	{
		return false;
	}
	///////////////////
	auto touch = EventListenerTouchOneByOne::create();
	touch->onTouchBegan = CC_CALLBACK_2(physics00::onTouchBegan, this);
	touch->onTouchEnded = CC_CALLBACK_2(physics00::onTouchEnded, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);

	return true;
}

void physics00::createMyPhysicsWorld()
{
	//물리 효과가 적용된 스크린 바운더리(Screen Boundary)설정
	//중력이 적용되는 범위와 중력의 세기,방향을 설정
	
	//눈에 보이는 화면 사이즈를 가져옴
	auto visibleSize = _director->getVisibleSize();

	//중력을 설정하지 않는 경우 기본값이 Vec2(0.0f,-98.0f)
	Vec2 gravity = Vec2(0.0f, -128.0f);
	//현재 Scene의 PhysicsWorld 정보를 받아온다.
	//PhysicsWorld의 개체는 충돌 및 기타 물리적 속성을 시뮬레이션한다.
	//PhysicsWorld의 개체를 직접 만들지는 않는다.
	//대신 Scene 개체에서 가져올 수 있다.
	m_world = this->getPhysicsWorld();

	//setDebugDrawMask(): 물리 시뮬레이션이 적용된 객체의 판정박스 표시(디버그용 박스 표시)
	m_world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//setGravity() : 중력의 방향과 세기를 결정
	m_world->setGravity(gravity);

	//setSpeed(): 낙하에 따른 중력의 가속도를 설정
	m_world->setSpeed(2.0f);

	//setSubsteps(): 프레임간의 물리연산 횟수를 설정
	m_world->setSubsteps(5);

	//------------------------------------------------
	//PhysicsBody :createEdgeBox ->디버그 박스
	/*
		제 1 매개변수 : 물리 시뮬레이션이 적용될 범위를 설정한다.
		제 2 매개변수 : 물체의 밀도,반발력,마찰력 설정
		제 3 매개변수 : 디버그 사각박스의 외곽선 두께
	*/
	
	auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 5);

	//물리 시뮬레이션을 적용할 객체
	auto edgeNode = Node::create();

	//Node 위치를 조정하여 물리 효과가 화면 전체를 뒤덮도록 한다.
	edgeNode->setPosition(Vec2(visibleSize)*0.5f);

	//물리 정보를 객체에 부착한다.
	edgeNode->setPhysicsBody(body);

	this->addChild(edgeNode);
}

bool physics00::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	

	return true;
}

void physics00::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto touchPoint = touch->getLocation();
	addNewSpriteAtPosition(touchPoint);

}

void physics00::addNewSpriteAtPosition(cocos2d::Vec2 pos)
{
	//스프라이트 객체 생성
	auto sprite = Sprite::create("r1.png");
	sprite->setPosition(pos);
	sprite->setScale(0.5);

	//강체 설정
	//강체란 추상적인 객체의 물리속성을 설명한다.
	//질량,위치,회전각도,속도와 저항(damping)을 포함한다.
	//cocos2d-x 안에서는 physicsbody 객체가 강체이다.
	auto body = PhysicsBody::createCircle(sprite->getContentSize().width / 2);
	//auto body = PhsicsBody::createBox(sprite->getContentSize());

	//바디의 질량 정하기
	body->setMass(100.0f);
	
	body->setDynamic(true);
	
	sprite->setPhysicsBody(body);
	this->addChild(sprite);
}
