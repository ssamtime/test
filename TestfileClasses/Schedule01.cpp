#include "Schedule01.h"

USING_NS_CC;

Scene* Schedule01::createScene()
{
	return Schedule01::create();
}

bool Schedule01::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	auto item1 = MenuItemFont::create("start", CC_CALLBACK_1(Schedule01::doStart,this));
	item1->setColor(Color3B(0, 0, 0));

	auto item2 = MenuItemFont::create("Pause", CC_CALLBACK_1(Schedule01::doPause, this));
	item2->setColor(Color3B(0, 0, 0));

	auto item3 = MenuItemFont::create("Resume", CC_CALLBACK_1(Schedule01::doResume, this));
	item3->setColor(Color3B(0, 0, 0));

	auto item4 = MenuItemFont::create("Change", CC_CALLBACK_1(Schedule01::doChange, this));
	item4->setColor(Color3B(0, 0, 0));

	auto item5 = MenuItemFont::create("Stop", CC_CALLBACK_1(Schedule01::doStop, this));
	item5->setColor(Color3B(0, 0, 0));

	auto pMenu = Menu::create(item1, item2, item3, item4, item5, nullptr);

	//세로로 정렬
	pMenu->alignItemsVertically();

	this->addChild(pMenu);

	nNum = 0;
	bChange = false;

	return true;
}

void Schedule01::doStart(Ref * pSender)
{
	this->schedule(schedule_selector(Schedule01::tick1), 1.0f);
	this->schedule(schedule_selector(Schedule01::tick1), 2.0f);

}

void Schedule01::doPause(Ref * pSender)
{
	Director::getInstance()->getScheduler()->pauseTarget(this);
}

void Schedule01::doResume(Ref * pSender)
{
	Director::getInstance()->getScheduler()->resumeTarget(this);
}

//2초 간격으로 호출되던 스케줄을 3초로 바꾼다.
//만약 3초간격으로 호출되고 있다면 2초 간격으로 호출되도록 변경한다.
//이 때 유심히 봐야 할 점은 변경이 아니라는 것이다.
//기존 스케줄을 unscheduled 라는 메서드를 통해 삭제하고 다시 만드는 것이다.
void Schedule01::doChange(Ref * pSender)
{
	if (bChange)
	{
		bChange = false;
		this->unschedule(schedule_selector(Schedule01::tick2));
		this->schedule(schedule_selector(Schedule01::tick2), 2.0f);
	}
	else
	{
		bChange = true;
		this->unschedule(schedule_selector(Schedule01::tick2));
		this->schedule(schedule_selector(Schedule01::tick2), 3.0f);
	}
}

void Schedule01::doStop(Ref * pSender)
{
	this->unschedule(schedule_selector(Schedule01::tick1));
	this->unschedule(schedule_selector(Schedule01::tick2));
}

void Schedule01::tick1(float f)
{
	log("tick1");
}

void Schedule01::tick2(float f)
{
	log("tick2");
}
