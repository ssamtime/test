#include "RayCast00.h"

USING_NS_CC;

Scene* RayCast00::createScene()
{
	return RayCast00::create();
}

bool RayCast00::init()
{
	if (Scene::initWithPhysics())
	{
		createMyPhysicsWorld();
	}
	else
		return false;
	///////////////////
	
	//(��Ƽ)��ġ �̺�Ʈ ������
	auto touch = EventListenerTouchAllAtOnce::create();
	touch->onTouchesEnded = CC_CALLBACK_2(RayCast00::onTouchesEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);

	_node = nullptr;

	this->schedule(schedule_selector(RayCast00::myTick));

	return true;
}

void RayCast00::createMyPhysicsWorld()
{
	auto visibleSize = _director->getVisibleSize();

	//�߷��� ����� ������ ����
	Vect gravity = Vect(0.0f, -128.0f);

	//���� Scene�� PhysicsWorld ������ ��ũ��Ų��.
	m_world = this->getPhysicsWorld();

	//setDebugDrawMask() : ���� ��Ģ�� ����� ��ü�� �����ڽ� ǥ��
	m_world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//�߷��� ����� ������ ����
	m_world->setGravity(gravity);

	//setSpeed() : ���Ͽ� ���� �߷� ���ӵ��� ����
	m_world->setSpeed(2.0f);

	//setSubsteps() : ���� �����ӿ��� ���� �����ӻ����� ���� ����Ƚ���� ����. �⺻���� 1�̴�.
	m_world->setSubsteps(5);

	//PhysicsBody::createEdgeBox
	/*
		�� 1�μ�: ���� �ùķ��̼��� ����� ��������
		�� 2�μ�: �е�(density), �ݹ߷�(restitution), ������(fraction)
		�� 3�μ�: ���� �ùķ��̼� ���� ������ ǥ���ϴ� ���� ����
	*/
	auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 5);

	//���� �ùķ��̼��� ������ ��ü(�ֻ��� Ŭ���� Node ���)
	auto edgeNode = Node::create();

	//Node ��ġ ������ ���� ȭ�� ��ü�� ���� �ùķ��̼��� ����ǵ��� �Ѵ�.
	edgeNode->setPosition(Vec2(visibleSize)*0.5f);

	//���� ����
	edgeNode->setPhysicsBody(body);
	this->addChild(edgeNode);
}

void RayCast00::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * event)
{
	for (auto& touch : touches)
	{
		auto location = touch->getLocation();

		auto sprite = addNewSpriteAtPosition(location);
		sprite->setTag(1);

		this->addChild(sprite);
	}
}

bool RayCast00::anyRay(cocos2d::PhysicsWorld & world, const cocos2d::PhysicsRayCastInfo & info, void * data)
{
	//Raycast�� �浹�� ��ü�� PhysicsBody�� ���޹޴´�.
	*((Vec2*)data) = info.contact;
	auto body = info.shape->getBody();

	//Raycast�� �浹�� ��ü�� Tag�� ���
	auto sp = (Sprite*)body->getNode();
	int tag = sp->getTag();

	log("TagInfo : %d", tag);


	return true;
}

cocos2d::Sprite * RayCast00::addNewSpriteAtPosition(cocos2d::Vec2 pos)
{
	auto pSprite = Sprite::create("r1.png");
	pSprite->setPosition(pos);
	pSprite->setTag(1);

	//���� //�е�, �ݹ߷�, ������
	auto material = PhysicsMaterial(0.1f, 1.0f, 0.5f);
	auto body = PhysicsBody::createCircle(pSprite->getContentSize().width / 2, material);
	pSprite->setPhysicsBody(body);

	return pSprite;
}

void RayCast00::myTick(float dt)
{
	//Raycast�� ����� Vec2 ���
	Vec2 point1 = Vec2(128, 360);
	Vec2 point2 = Vec2(1152, 360);
	Vec2 point3 = point2;

	//�ν��Ͻ� �ߺ� ���� ������ ���� removeChild
	this->removeChild(_node);

	//ȭ�鿡 Raycast�� ����ȭ�ϴ� DrawNode �ν��Ͻ�
	_node = DrawNode::create();

	//Raycast �ݹ��Լ�
	auto func = CC_CALLBACK_3(RayCast00::anyRay, this);

	//------------------------------

	//void PhysicsWorld::rayCast(callFunc,start,end,data)
	/*
		CallFunc:��Ư�� ������Ʈ�� �浹���� ��� ȣ���ϴ� �Լ�
		Start: Raycast�� �����
		end: Raycast�� ������
		data: ��Ư�� ���������� �浹������� �浹�� ���� ��ǥ�� �����ϴ� ����
	*/

	m_world->rayCast(func, point1, point2, &point3);

	//drawSegment((�����, ������, ���� ����, ���� ����);
	_node->drawSegment(point1, point2, 5, Color4F::RED);

	if (point2 != point3)
	{
		//drawDot(Ư�� ��ġ,��Ʈ ũ��, ��Ʈ ����)
		_node->drawDot(point3, 50, Color4F::WHITE);
	}
	this->addChild(_node);

}
