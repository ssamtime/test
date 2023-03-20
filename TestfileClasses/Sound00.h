#pragma once
#include "cocos2d.h"

//UTF-8 : 전세계모든 문자표현할수있도록 만든 규약. 안하면 한글 깨짐
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Sound00 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Sound00);

	float _soundVolume;

	int audioId1;
	int audioId2;

	void preloadAll(Ref* pSender);
	void uncacheAll(Ref* pSender);

	void upVolume(Ref* pSender);
	void downVolume(Ref* pSender);

	void playSound1(Ref* pSender);
	void playSound2(Ref* pSender);
	void pauseSound1(Ref* pSender);
	void pauseSound2(Ref* pSender);
	void resumeSound1(Ref* pSender);
	void resumeSound2(Ref* pSender);
	void stopSound1(Ref* pSender);
	void stopSound2(Ref* pSender);

	void bgmPlayFinishedCallback(int audioId, const std::string&fliepath);

	//소멸자
	~Sound00();

	



};