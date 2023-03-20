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

	//위치 구분용 스프라이트
	auto sprite1 = Sprite::create("Character/cookie.png");
	auto sprite2 = Sprite::create("Character/cookie_woman.png");

	sprite1->setPosition(Vec2(0, 100));
	sprite1->setAnchorPoint(Vec2(0, 0));
	sprite2->setPosition(Vec2(2000, 100));
	sprite2->setAnchorPoint(Vec2(0, 0));

	//스크롤 뷰를 구분해서 보여주기 위한 레이어
	auto layer = LayerColor::create(Color4B::MAGENTA);
	layer->setAnchorPoint(Vec2::ZERO);
	layer->setPosition(Vec2::ZERO);
	layer->setContentSize(Size(2560, 360));

	layer->addChild(sprite1);
	layer->addChild(sprite2);

	auto scrollView = ScrollView::create();
	//화면에 보여질 크기를 지정한다.
	scrollView->setSize(Size(1280, 360));
	//스크롤 뷰 안에 들어올 내용의 크기를 지정한다.
	scrollView->setInnerContainerSize(layer->getContentSize());
	//스크롤이 가능한 방향을 지정한다.
	scrollView->setDirection(ScrollView::Direction::HORIZONTAL);
	//스크롤뷰에 스크롤이 될 대상을 추가한다.
	scrollView->addChild(layer);

	//스크롤시 끝에 도달하면 바운스를 할 것인지 정한다.
	scrollView->setBounceEnabled(true);
	//스크롤바가 자동으로 사라지게 할 것인지를 정한다.
	scrollView->setScrollBarAutoHideEnabled(false);
	//이벤트 발생시 처리할 메서드를 등록한다.
	scrollView->addEventListener(CC_CALLBACK_2(ScrollView00::scrollEvent, this));
	//스크롤이 될 대상의 스크롤 뷰 안에서의 현재 위치를 지정한다.
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
