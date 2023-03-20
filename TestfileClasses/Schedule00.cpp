#include "Schedule00.h"

USING_NS_CC;

Scene* Schedule00::createScene()
{
	return Schedule00::create();
}

bool Schedule00::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	nNum = 0;

	///////////////////////////////
	//매 프레임마다 실행하기
	//첫번째 스케줄은 별도로 시간을 지정해 주지 않았기 때문에 기본적으로 매 프레임마다 호출된다.
	//1초당 최대 프레임은 60프레임이다.
	//60이라는 것은 매번 60프레임이 불리는것은 아니고 성능이나 상태에따라 다를수 있다.
	this->schedule(schedule_selector(Schedule00::callEveryFrame));

	// 지정된 시간마다 실행하기
	// 이번에는 1초마다 호출된다. 역시 정확히 1초마다 불리는 것은 아닐수 있다.
	this->schedule(schedule_selector(Schedule00::myTick), 1.0f);

	//딜레이 타임 후 한번 실행하기
	//3초에 딱 한번 실행되고 자동으로 종료
	this->scheduleOnce(schedule_selector(Schedule00::myTickOnce), 3.0f);

	//매프레임마다
	this->scheduleUpdate();

	return true;
}

void Schedule00::callEveryFrame(float f)
{
	nNum++;
	if (nNum > 60)
	{
		nNum = 1;
	}
	log("fps...%d", nNum);
}

void Schedule00::myTick(float f)
{
	log("tick **************************");
}

void Schedule00::myTickOnce(float f)
{
	log("tickOnce after delay");
}

void Schedule00::update(float delta)
{
	log("update");
}
