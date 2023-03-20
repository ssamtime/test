#include "Action03.h"

USING_NS_CC;

Scene* Action03::createScene()
{
	return Action03::create();
}

bool Action03::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	auto pMenuItem = MenuItemFont::create("Action",
		CC_CALLBACK_1(Action03::doAction, this));
	pMenuItem->setColor(Color3B::BLACK);

	//�޴�����
	auto pMenu = Menu::create(pMenuItem, nullptr);

	//�޴�
	pMenu->setPosition(Vec2(640, 100));

	this->addChild(pMenu);

	//���׶� ��ư ��������Ʈ �߰�
	pBall = Sprite::create("Character/pet.png");
	pBall->setPosition(Vec2(100, 200));
	pBall->setScale(0.7f);
	this->addChild(pBall);

	//cookie1 sprite �߰�
	pCookie = Sprite::create("Character/cookie.png");
	pCookie->setPosition(Vec2(100, 350));
	pCookie->setScale(0.5);
	this->addChild(pCookie);

	//cookiewoman 1,2 sprite�߰�
	pCookiewoman1 = Sprite::create("Character/cookie_woman.png");
	pCookiewoman1->setPosition(Vec2(100, 500));
	pCookiewoman1->setScale(0.5);
	this->addChild(pCookiewoman1);

	pCookiewoman2 = Sprite::create("Character/cookie_woman2.png");
	pCookiewoman2->setPosition(Vec2(100, 650));
	pCookiewoman2->setScale(0.5);
	this->addChild(pCookiewoman2);


	return true;
}

void Action03::doAction(Ref * pSender)
{
	//Reset
	pBall->setPosition(Vec2(100, 200));
	pCookie->setPosition(Vec2(100, 350));
	pCookiewoman1->setPosition(Vec2(100, 500));
	pCookiewoman2->setPosition(Vec2(100, 650));

	//doActionEase();
	//doActionElastic();
	//doActionBounce();
	doActionSpeed();
}

//����׼� ����ϱ�
/*
���� �׼��� �׼� ������ �׼ǱⰣ�� �����ϴ� Ư���� ���� �׼��̴�.
�Ϲ����� �׼��� ��� �ð��� �帧�� ���� �׼��� ���෮�� �����ϴ�.
����׼��� �������� �׼��� ���� �Ⱓ�� �����Ѵ�.
���� ��� ���� �׼��� ����ȭ�ϰų� ����ȭ�Ѵ�.
- EaseIn : �׼��� ó���� ���ȴٰ� ������ ��������.
- EaseOut : ÷ �����ٰ� ������
- EaseInOut : ó���� ���ȴٰ� �߰��� �������� �ٽ� ������

*/
void Action03::doActionEase()
{
	//����ӵ�
	auto move = MoveBy::create(3.0f, Vec2(400, 0));
	//ó���� ���ȴٰ� ��������
	auto ease_in = EaseIn::create(move->clone(), 3.0f);
	//�������� : �����ٰ� ��������
	auto ease_out = EaseOut::create(move->clone(), 3.0f);
	//�������ٰ� ��������: ���� �������� �߰� ����
	auto ease_inout = EaseInOut::create(move->clone(), 3.0f);

	pBall->runAction(move);
	pCookie->runAction(ease_in);
	pCookiewoman1->runAction(ease_out);
	pCookiewoman2->runAction(ease_inout);
}

//ź��
/*
 �� �׼��� ź�� �ùķ��̼� �Ⱓ�� �����Ѵ�.
 ź�� �׼��� 0���� ũ�� 1���� ���� time ���� ����ϸ� ���ξ׼��� Ư���������� ������ �޴´�.
  
  -�ι�° �Ķ������ 'period'�Ķ���Ϳ��� �󸶸�ŭ ź�����ΰ��� ����
  - �⺻��: 0.3
  - �ǰ�: 0.3���� 0.45
*/
void Action03::doActionElastic()
{
	//����ӵ�
	auto move = MoveBy::create(3.0f, Vec2(400, 0));

	//ź��--------------------------------------------------
	auto ease_in = EaseElasticIn::create(move->clone(), 0.4f);
	auto ease_out = EaseElasticOut::create(move->clone(), 0.4f);
	auto ease_inout = EaseElasticInOut::create(move->clone(), 0.4f);

	pBall->runAction(move);
	pCookie->runAction(ease_in);
	pCookiewoman1->runAction(ease_out);
	pCookiewoman2->runAction(ease_inout);
	
}

//���� �ٿ �׼��� ���� Ƣ��� ȿ���� �ùķ��̼� �Ѵ�.
/*
������ : MoveBy, ScaleBy, RotateBy �� ���� ������ �׼��� ���� �ٿ�׼ǿ� �����ص� ����������
sequence �Ǵ� Spawn �׼��� ����ġ ���� ����� ���� �� �ִ�.
*/
void Action03::doActionBounce()
{
	//���� �ӵ�
	auto move = MoveBy::create(3.0f, Vec2(480, 0));
	//�ٿ -------------
	auto ease_in = EaseBounceIn::create(move->clone());
	auto ease_out = EaseBounceOut::create(move->clone());
	auto ease_inout = EaseBounceInOut::create(move->clone());

	pBall->runAction(move);
	pCookie->runAction(ease_in);
	pCookiewoman1->runAction(ease_out);
	pCookiewoman2->runAction(ease_inout);
}

//���ǵ� �׼��� ���� �׼��� �ӵ��� ���δ�,
/*
 ��� ��) ĳ���Ͱ� �������� ������ �ӵ��� �����ð����� �������ų� �������°�
*/
void Action03::doActionSpeed()
{
	//����ӵ�
	auto move = MoveBy::create(3.0f, Vec2(480, 0));

	//���ǵ�
	auto ease_in = Speed::create(move->clone(), 1.0f);
	auto ease_out = Speed::create(move->clone(), 2.0f);
	auto ease_inout = Speed::create(move->clone(), 3.0f);

	pBall->runAction(move);
	pCookie->runAction(ease_in);
	pCookiewoman1->runAction(ease_out);
	pCookiewoman2->runAction(ease_inout);
}

