#pragma once
//스크롤 뷰는 내부에 지정된 컨텐츠를 좌우로 스크롤할 수 있는 클래스이다.
//Cocos2d-x에서 스크롤뷰 클래스는 확장 클래스이다.

#include "cocos2d.h"
#include "ui/CocosGUI.h"


//UTF-8 : 전세계모든 문자표현할수있도록 만든 규약. 안하면 한글 깨짐
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class ScrollView00 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(ScrollView00);

	//스크롤뷰에 사용자의 입력에 따른 이벤트가 발생하면, 이벤트들을 처리하기위한 메서드를 선언한다.
	void scrollEvent(Ref* pSender, cocos2d::ui::ScrollView::EventType event);

};