#include "ScrollView00.h"

USING_NS_CC;
using namespace ui;

Scene* ScrollView00::createScene()
{
	return ScrollView00::create();
}

bool ScrollView00::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	//��ġ ���п� ��������Ʈ
	auto sprite1 = Sprite::create("Character/cookie.png");
	auto sprite2 = Sprite::create("Character/cookie_woman.png");

	sprite1->setPosition(Vec2(0, 100));
	sprite1->setAnchorPoint(Vec2(0, 0));
	sprite2->setPosition(Vec2(2000, 100));
	sprite2->setAnchorPoint(Vec2(0, 0));

	//��ũ�� �並 �����ؼ� �����ֱ� ���� ���̾�
	auto layer = LayerColor::create(Color4B::MAGENTA);
	layer->setAnchorPoint(Vec2::ZERO);
	layer->setPosition(Vec2::ZERO);
	layer->setContentSize(Size(2560, 360));

	layer->addChild(sprite1);
	layer->addChild(sprite2);

	auto scrollView = ScrollView::create();
	//ȭ�鿡 ������ ũ�⸦ �����Ѵ�.
	scrollView->setSize(Size(1280, 360));
	//��ũ�� �� �ȿ� ���� ������ ũ�⸦ �����Ѵ�.
	scrollView->setInnerContainerSize(layer->getContentSize());
	//��ũ���� ������ ������ �����Ѵ�.
	scrollView->setDirection(ScrollView::Direction::HORIZONTAL);
	//��ũ�Ѻ信 ��ũ���� �� ����� �߰��Ѵ�.
	scrollView->addChild(layer);

	//��ũ�ѽ� ���� �����ϸ� �ٿ�� �� ������ ���Ѵ�.
	scrollView->setBounceEnabled(true);
	//��ũ�ѹٰ� �ڵ����� ������� �� �������� ���Ѵ�.
	scrollView->setScrollBarAutoHideEnabled(false);
	//�̺�Ʈ �߻��� ó���� �޼��带 ����Ѵ�.
	scrollView->addEventListener(CC_CALLBACK_2(ScrollView00::scrollEvent, this));
	//��ũ���� �� ����� ��ũ�� �� �ȿ����� ���� ��ġ�� �����Ѵ�.
	scrollView->jumpToPercentHorizontal(50);
	scrollView->setPosition(Vec2(0, 0));
	this->addChild(scrollView);

	return true;
}

void ScrollView00::scrollEvent(Ref * pSender, cocos2d::ui::ScrollView::EventType event)
{
	switch (event)
	{
	case ScrollView::EventType::SCROLLING:
		log("Scrolling..");
		break;
	}
}
