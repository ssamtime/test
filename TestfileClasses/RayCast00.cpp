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
	
	//(멀티)터치 이벤트 리스너
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

	//중력의 세기와 방향을 설정
	Vect gravity = Vect(0.0f, -128.0f);

	//현재 Scene의 PhysicsWorld 정보를 링크시킨다.
	m_world = this->getPhysicsWorld();

	//setDebugDrawMask() : 물리 법칙이 적용된 객체의 판정박스 표시
	m_world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//중력의 세기와 방향을 적용
	m_world->setGravity(gravity);

	//setSpeed() : 낙하에 따른 중력 가속도를 설정
	m_world->setSpeed(2.0f);

	//setSubsteps() : 현재 프레임에서 다음 프레임사이의 물리 연산횟수를 설정. 기본값은 1이다.
	m_world->setSubsteps(5);

	//PhysicsBody::createEdgeBox
	/*
		제 1인수: 물리 시뮬레이션이 적용될 범위설정
		제 2인수: 밀도(density), 반발력(restitution), 마찰력(fraction)
		제 3인수: 물리 시뮬레이션 적용 범위를 표시하는 선의 굵기
	*/
	auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 5);

	//물리 시뮬레이션을 적용할 객체(최상위 클래스 Node 사용)
	auto edgeNode = Node::create();

	//Node 위치 조정을 통해 화면 전체에 물리 시뮬레이션이 적용되도록 한다.
	edgeNode->setPosition(Vec2(visibleSize)*0.5f);

	//물리 적용
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
	//Raycast와 충돌한 객체의 PhysicsBody를 전달받는다.
	*((Vec2*)data) = info.contact;
	auto body = info.shape->getBody();

	//Raycast와 충돌한 객체의 Tag를 출력
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

	//물리 //밀도, 반발력, 마찰력
	auto material = PhysicsMaterial(0.1f, 1.0f, 0.5f);
	auto body = PhysicsBody::createCircle(pSprite->getContentSize().width / 2, material);
	pSprite->setPhysicsBody(body);

	return pSprite;
}

void RayCast00::myTick(float dt)
{
	//Raycast에 사용할 Vec2 목록
	Vec2 point1 = Vec2(128, 360);
	Vec2 point2 = Vec2(1152, 360);
	Vec2 point3 = point2;

	//인스턴스 중복 생성 방지를 위한 removeChild
	this->removeChild(_node);

	//화면에 Raycast를 가시화하는 DrawNode 인스턴스
	_node = DrawNode::create();

	//Raycast 콜백함수
	auto func = CC_CALLBACK_3(RayCast00::anyRay, this);

	//------------------------------

	//void PhysicsWorld::rayCast(callFunc,start,end,data)
	/*
		CallFunc:불특정 오브젝트와 충돌했을 경우 호출하는 함수
		Start: Raycast의 출발점
		end: Raycast의 도착점
		data: 불특정 오브젝으와 충돌했을경우 충돌한 곳의 좌표를 보관하는 버퍼
	*/

	m_world->rayCast(func, point1, point2, &point3);

	//drawSegment((출발점, 도착점, 선의 굵기, 선의 색상);
	_node->drawSegment(point1, point2, 5, Color4F::RED);

	if (point2 != point3)
	{
		//drawDot(특정 위치,도트 크기, 도트 색상)
		_node->drawDot(point3, 50, Color4F::WHITE);
	}
	this->addChild(_node);

}
