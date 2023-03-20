#pragma once
//앱을 실행하다 보면 사용자에게 입력을 받아 캐릭터명을 만들거나 하는 경우도 있다.
//이때, 사용하는 클래스가 에디터박스 EditBox 클래스이다.
//에디트 박스는 cocos2d-x에서 제공하는 클래스로서, 해당라이브러리를 인클루드하고 사용해야한다.
#include "cocos2d.h"
#include "ui/UIEditBox/UIEditBox.h"

//UTF-8 : 전세계모든 문자표현할수있도록 만든 규약. 안하면 한글 깨짐
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

//에디트 박스의 델리게이트를 상속받는다.
//에디트 박스에 사용자의 입력에 따른 이벤트가 발생하면, 이런 이벤트들을 처리하는 메서드들이 정의되어있다.
class UserInput00 :public::cocos2d::Scene,public cocos2d::ui::EditBoxDelegate
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(UserInput00);

	void editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox)override;
	void editBoxEditingDidEnd(cocos2d::ui::EditBox* editBox)override;
	void editBoxTextChanged(cocos2d::ui::EditBox* editBox, const std::string& text)override;
	void editBoxReturn(cocos2d::ui::EditBox* editBox)override;

private:
	cocos2d::ui::EditBox* _editName;
	cocos2d::ui::EditBox* _editPassword;
	cocos2d::ui::EditBox* _editEmail;

};