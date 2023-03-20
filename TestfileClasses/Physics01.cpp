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

	//������ ũ�� �޾ƿ�
	auto visibleSize = _director->getVisibleSize();

	//���� ��ü�� ��������Ʈ
	auto sprite = Sprite::create("r1.png");
	sprite->setPosition(Vec2(visibleSize)*0.5f);

	//��ü����
	//��ü: �߻����� ��ü�� �����Ӽ��� �����Ѵ�.
	//����, ��ġ, ȸ������, �ӵ��� ������ �����Ѵ�.
	//cocos2d-x �ȿ����� physicalbody�� ��ü�̴�.
	auto body = PhysicsBody::createCircle(sprite->getContentSize().width / 2);

	// setDynamic(bool): ��ü�� �����Ӽ��� ����,�������� ����
	body->setDynamic(false); //�������μ���

	//setContactTestBisMark(int) : ��� ��ü�� ����� �� �浹�� �߻��ϴ� ����
	body->setContactTestBitmask(1);

	//setCollisionBitmask(int)" �浹�ϱ����� ��ȣ�� ��������
	body->setCollisionBitmask(2);

	sprite->setPhysicsBody(body);
	this->addChild(sprite);

	//------------------------------

	//��ġ �̺�Ʈ ������
	auto touch = EventListenerTouchOneByOne::create();
	touch->onTouchBegan = CC_CALLBACK_2(Physics01::onTouchBegan, this);
	touch->onTouchEnded = CC_CALLBACK_2(Physics01::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);

	//�浹 �̺�Ʈ ������
	auto contact = EventListenerPhysicsContact::create();
	contact->onContactBegin = CC_CALLBACK_1(Physics01::onContactBegin, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(contact, this);

	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	return true;
}

void Physics01::createMyPhysicalWorld()
{
	//����ȿ���� ����� ��ũ�� �ٿ���� ����
	//�߷��� ����Ǵ� ������ �߷��� ����, ������ ����
	auto visibleSize = _director->getVisibleSize();

	//�߷����������� �ʟ����
	//gravity Vexxt2((0.0f,-98.0)
	Vect gravity = Vect(0.01, -128.0);


	//����scene�� physicsWorld�� ������ �޾ƿ´�.
	m_world = this->getPhysicsWorld();

	//setDebugDrawMask():���� �ùķ��̼��� ����� ��ü�� �����ڽ�ǥ��
	m_world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//setGravity(): �߷��� ����� ���⸦ ����
	m_world->setGravity(gravity);

	//setSpeed(): ���Ͽ� ���� �߷°��ӵ��� ����
	m_world->setSpeed(2.0f);

	//setsubsteps()" �����Ӱ��� ��������Ƚ���� ����
	m_world->setSubsteps(5);

	//------------------------
	//PhysicalBody :: createEdgeBox

	/*
	��1�Ű����� :���� �ùķ��̼��� ����� ��������
	��2�Ű�����: ��ü�� �е�,�ݹ߷� ,������
	��3�Ű�����:����׹ڽ��� �β�
	*/
	auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 5);

	//���� �ùķ��̼��� ����� ��ü
	auto edgeNode = Node::create();

	//Node ��ġ�� �����Ͽ� ����ȿ���� ȭ�� ��ü�� �ڵ������Ѵ�.
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
		log("�浹�� �߻��߽��ϴ�.");
	}

	return true;
}

void Physics01::addNewSpriteAtPosition(cocos2d::Vec2 pos)
{
	//��������Ʈ ��ü����
	auto sprite = Sprite::create("r1.png");

	sprite->setPosition(pos);
	sprite->setScale(0.5f);

	//physicsBody����
	auto body = PhysicsBody::createCircle(sprite->getContentSize().width / 2);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);

	sprite->setPhysicsBody(body);
	this->addChild(sprite);
}


