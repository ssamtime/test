// UserDefault
/*
	�̱��� Ŭ����

	������ �����͸������ϱ� ���� cocos2d-x���� �⺻�����ϴ� �����ͺ��̽�
	UserDefault�� ���� ū Ư¡�� �����͸� �̸� - �� ���·� �����Ѵ�.
	key-value pair��� �Ҹ��� �� ����� std::map ���� ����߾���.
	��Ŭ������ �̿��Ͽ� �����͸� �����ϸ� xml������ �����ȴ�.
	[�����Ͱ� ����Ǵ� xml������ ��ġ (Win10����)]
	C:\Users\����ڸ�\AppData\Local\������Ʈ�� ����	
	*/

#include "UserDefault00.h"

USING_NS_CC;

Scene* UserDefault00::createScene()
{
	return UserDefault00::create();
}

bool UserDefault00::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	///////////////////
	//���� ����ÿ��� ������ ���� �����Ƿ� �⺻ ���� ���ϵȴ�.
	std::string ret = UserDefault::getInstance()->getStringForKey("str_key");
	log("string is %s", ret.c_str());

	int i = UserDefault::getInstance()->getIntegerForKey("int_key");
	log("integer is %d", i);

	float f = UserDefault::getInstance()->getFloatForKey("float_key");
	log("float is %f", f);

	double d = UserDefault::getInstance()->getDoubleForKey("double_key");
	log("double is %f", d);

	bool b = UserDefault::getInstance()->getBoolForKey("bool_key");
	if (b)
	{
		log("bool is true");
	}
	else
	{
		log("bool is false");
	}

	log("*************************init value*************************");

	//���� ������ Ű ������ �����ϴ� ������ ���� �����Ѵ�.
	UserDefault::getInstance()->setStringForKey("str_key", "value1");
	UserDefault::getInstance()->setIntegerForKey("int_key", 10);
	UserDefault::getInstance()->setFloatForKey("float_key", 100.000000);
	UserDefault::getInstance()->setDoubleForKey("double_key", 0.1f);
	UserDefault::getInstance()->setBoolForKey("bool_key", true);

	//print value2
	//�տ��� ����� �����Ͱ� Ű ���� ���� �������� ��µȴ�.
	
	ret = UserDefault::getInstance()->getStringForKey("str_key");
	log("string is %s", ret.c_str());

	i = UserDefault::getInstance()->getIntegerForKey("int_key");
	log("integer is %d", i);

	f = UserDefault::getInstance()->getFloatForKey("float_key");
	log("float is %f", f);

	d = UserDefault::getInstance()->getDoubleForKey("double_key");
	log("double is %f", d);

	b = UserDefault::getInstance()->getBoolForKey("bool_key");
	if (b)
	{
		log("bool is true");
	}
	else
	{
		log("bool is false");
	}

	return true;
}
