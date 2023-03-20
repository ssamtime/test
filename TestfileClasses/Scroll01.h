#include "cocos2d.h"


class Scroll01 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Scroll01);
	///////////////////////////
	cocos2d::Layer* layer1;
	cocos2d::Layer* layer2;

	cocos2d::Sprite* dragon;

	// ������ȭ ���� ��ư
	// ������ ���� ������ ���� ���� �ֵ���
	// �� ���⺰�� �ΰ��� �����.
	cocos2d::Sprite* rightSprite;
	cocos2d::Sprite* rightPressedSprite;
	cocos2d::Sprite* leftSprite;
	cocos2d::Sprite* leftPressedSprite;

	cocos2d::Size winSize;
	cocos2d::
		EventListenerTouchOneByOne*
		listener;

	bool isLeftPressed;
	bool isRightPressed;

	void createBackground();
	void createDragon();
	void createArrowButtons();

	void onEnter();
	void onExit();
	bool onTouchBegan
	(cocos2d::Touch* touch,
		cocos2d::Event* event);
	void onTouchMoved
	(cocos2d::Touch* touch,
		cocos2d::Event* event);
	void onTouchEnded
	(cocos2d::Touch* touch,
		cocos2d::Event* event);

	bool isTouchInside
	(cocos2d::Sprite* sprite,
		cocos2d::Touch* touch);
	void startMovingBackground();
	void stopMovingBackground();
	void moveBackground(float t);
};
