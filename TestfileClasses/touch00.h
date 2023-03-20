#pragma once
#include "cocos2d.h"

//UTF-8 : �������� ����ǥ���Ҽ��ֵ��� ���� �Ծ�. ���ϸ� �ѱ� ����
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class touch00 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(touch00);

	//�浹 üũ�� �� ��������Ʈ�� Ŭ���� ��������� ����Ѵ�.
	cocos2d::Sprite* pCookie;
	//�̱���ġ �̺�Ʈ �����ʸ� ������ ����Ѵ�.
	cocos2d::EventListenerTouchOneByOne* listener;

	//ȭ���� ���϶����� ȣ��Ǵ� �޼��带 �����Ѵ�.
	void onEnter(); //ȭ���� ������ ȣ��Ǵ� �Լ�
	//ȭ���� ����������� ȣ��Ǵ� �޼��带 �����Ѵ�.
	void onExit();

	//��ġ �̺�Ʈ�� ��ġ�� ���۵Ǿ����� �߻��ϴ� �̺�Ʈ�� ó���ϴ� �޼��� �����Ѵ�
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	//��ġ �̺�Ʈ�� ��ġ�� �̵��Ҷ� �߻��ϴ� �̺�Ʈ�� ó���ϴ� �޼��� ����
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	//��ġ �̺�Ʈ�� ��ġ�� �������� �߻��ϴ� �̺�Ʈ�� ó���ϴ� �޼��� ����
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	//��ġ �̺�Ʈ�� ��ġ�� ��ҵǾ�����
	void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

	//��ġ�� ���õ� �޼���� ����ó�� �װ԰� �ִµ�, ������ �����ϰ� �ݹ��Լ��� ������ص��ǰ�
	//�ʿ��� �͸� ����,���� ����ϸ�ȴ�




};