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
	//�� �����Ӹ��� �����ϱ�
	//ù��° �������� ������ �ð��� ������ ���� �ʾұ� ������ �⺻������ �� �����Ӹ��� ȣ��ȴ�.
	//1�ʴ� �ִ� �������� 60�������̴�.
	//60�̶�� ���� �Ź� 60�������� �Ҹ��°��� �ƴϰ� �����̳� ���¿����� �ٸ��� �ִ�.
	this->schedule(schedule_selector(Schedule00::callEveryFrame));

	// ������ �ð����� �����ϱ�
	// �̹����� 1�ʸ��� ȣ��ȴ�. ���� ��Ȯ�� 1�ʸ��� �Ҹ��� ���� �ƴҼ� �ִ�.
	this->schedule(schedule_selector(Schedule00::myTick), 1.0f);

	//������ Ÿ�� �� �ѹ� �����ϱ�
	//3�ʿ� �� �ѹ� ����ǰ� �ڵ����� ����
	this->scheduleOnce(schedule_selector(Schedule00::myTickOnce), 3.0f);

	//�������Ӹ���
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
