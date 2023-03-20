#pragma once
//���� �����ϴ� ���� ����ڿ��� �Է��� �޾� ĳ���͸��� ����ų� �ϴ� ��쵵 �ִ�.
//�̶�, ����ϴ� Ŭ������ �����͹ڽ� EditBox Ŭ�����̴�.
//����Ʈ �ڽ��� cocos2d-x���� �����ϴ� Ŭ�����μ�, �ش���̺귯���� ��Ŭ����ϰ� ����ؾ��Ѵ�.
#include "cocos2d.h"
#include "ui/UIEditBox/UIEditBox.h"

//UTF-8 : �������� ����ǥ���Ҽ��ֵ��� ���� �Ծ�. ���ϸ� �ѱ� ����
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

//����Ʈ �ڽ��� ��������Ʈ�� ��ӹ޴´�.
//����Ʈ �ڽ��� ������� �Է¿� ���� �̺�Ʈ�� �߻��ϸ�, �̷� �̺�Ʈ���� ó���ϴ� �޼������ ���ǵǾ��ִ�.
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