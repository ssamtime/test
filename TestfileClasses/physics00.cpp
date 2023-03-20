//���� ����Ʈ
//https://dygks910910.tistory.com/77
#include "physics00.h"

USING_NS_CC;

Scene* physics00::createScene()
{
	return physics00::create();
}

bool physics00::init()
{
	//1.initWithPhysics�� ����ϸ� �������带 ������ ���� ������ �� �ִ�.
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
	//���� ȿ���� ����� ��ũ�� �ٿ����(Screen Boundary)����
	//�߷��� ����Ǵ� ������ �߷��� ����,������ ����
	
	//���� ���̴� ȭ�� ����� ������
	auto visibleSize = _director->getVisibleSize();

	//�߷��� �������� �ʴ� ��� �⺻���� Vec2(0.0f,-98.0f)
	Vec2 gravity = Vec2(0.0f, -128.0f);
	//���� Scene�� PhysicsWorld ������ �޾ƿ´�.
	//PhysicsWorld�� ��ü�� �浹 �� ��Ÿ ������ �Ӽ��� �ùķ��̼��Ѵ�.
	//PhysicsWorld�� ��ü�� ���� �������� �ʴ´�.
	//��� Scene ��ü���� ������ �� �ִ�.
	m_world = this->getPhysicsWorld();

	//setDebugDrawMask(): ���� �ùķ��̼��� ����� ��ü�� �����ڽ� ǥ��(����׿� �ڽ� ǥ��)
	m_world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//setGravity() : �߷��� ����� ���⸦ ����
	m_world->setGravity(gravity);

	//setSpeed(): ���Ͽ� ���� �߷��� ���ӵ��� ����
	m_world->setSpeed(2.0f);

	//setSubsteps(): �����Ӱ��� �������� Ƚ���� ����
	m_world->setSubsteps(5);

	//------------------------------------------------
	//PhysicsBody :createEdgeBox ->����� �ڽ�
	/*
		�� 1 �Ű����� : ���� �ùķ��̼��� ����� ������ �����Ѵ�.
		�� 2 �Ű����� : ��ü�� �е�,�ݹ߷�,������ ����
		�� 3 �Ű����� : ����� �簢�ڽ��� �ܰ��� �β�
	*/
	
	auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 5);

	//���� �ùķ��̼��� ������ ��ü
	auto edgeNode = Node::create();

	//Node ��ġ�� �����Ͽ� ���� ȿ���� ȭ�� ��ü�� �ڵ����� �Ѵ�.
	edgeNode->setPosition(Vec2(visibleSize)*0.5f);

	//���� ������ ��ü�� �����Ѵ�.
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
	//��������Ʈ ��ü ����
	auto sprite = Sprite::create("r1.png");
	sprite->setPosition(pos);
	sprite->setScale(0.5);

	//��ü ����
	//��ü�� �߻����� ��ü�� �����Ӽ��� �����Ѵ�.
	//����,��ġ,ȸ������,�ӵ��� ����(damping)�� �����Ѵ�.
	//cocos2d-x �ȿ����� physicsbody ��ü�� ��ü�̴�.
	auto body = PhysicsBody::createCircle(sprite->getContentSize().width / 2);
	//auto body = PhsicsBody::createBox(sprite->getContentSize());

	//�ٵ��� ���� ���ϱ�
	body->setMass(100.0f);
	
	body->setDynamic(true);
	
	sprite->setPhysicsBody(body);
	this->addChild(sprite);
}
