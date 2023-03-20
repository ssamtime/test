// UserDefault
/*
	싱글톤 클래스

	간단한 데이터를저장하기 위해 cocos2d-x에서 기본제공하는 데이터베이스
	UserDefault의 가장 큰 특징은 데이터를 이름 - 값 형태로 저장한다.
	key-value pair라고 불리는 이 방식은 std::map 에서 사용했었다.
	이클래스를 이용하여 데이터를 저장하면 xml파일이 생성된다.
	[데이터가 저장되는 xml파일의 위치 (Win10기준)]
	C:\Users\사용자명\AppData\Local\프로젝트명 폴더	
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
	//최초 실행시에는 지정된 값이 없으므로 기본 값이 리턴된다.
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

	//내가 지정한 키 값에ㅡ 대응하는 벨류에 값을 저장한다.
	UserDefault::getInstance()->setStringForKey("str_key", "value1");
	UserDefault::getInstance()->setIntegerForKey("int_key", 10);
	UserDefault::getInstance()->setFloatForKey("float_key", 100.000000);
	UserDefault::getInstance()->setDoubleForKey("double_key", 0.1f);
	UserDefault::getInstance()->setBoolForKey("bool_key", true);

	//print value2
	//앞에서 저장된 데이터가 키 값에 의해 구해져서 출력된다.
	
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
