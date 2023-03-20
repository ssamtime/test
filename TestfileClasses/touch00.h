#pragma once
#include "cocos2d.h"

//UTF-8 : 전세계모든 문자표현할수있도록 만든 규약. 안하면 한글 깨짐
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class touch00 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(touch00);

	//충돌 체크를 할 스프라이트를 클래스 멤버변수로 등록한다.
	cocos2d::Sprite* pCookie;
	//싱글터치 이벤트 리스너를 변수로 등록한다.
	cocos2d::EventListenerTouchOneByOne* listener;

	//화면이 보일때마다 호출되는 메서드를 선언한다.
	void onEnter(); //화면이 켜질때 호출되는 함수
	//화면이 사라질때마다 호출되는 메서드를 선언한다.
	void onExit();

	//터치 이벤트중 터치가 시작되었을때 발생하는 이벤트를 처리하는 메서드 선언한다
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	//터치 이벤트중 터치가 이동할때 발생하는 이벤트를 처리하는 메서드 선언
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	//터치 이벤트중 터치가 끝났을때 발생하는 이벤트를 처리하는 메서드 선언
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	//터치 이벤트중 터치가 취소되었을때
	void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

	//터치와 관련된 메서드는 예제처럼 네게가 있는데, 무조건 구현하고 콜백함수로 연결안해도되고
	//필요한 것만 선언,정의 사용하면된다




};