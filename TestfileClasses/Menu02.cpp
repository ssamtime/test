#include "Menu02.h"

USING_NS_CC;

Scene* Menu02::createScene()
{
	return Menu02::create();
}

bool Menu02::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	//메뉴 아이템생성 및 초기화
	//메뉴가 터치될 때마다 this ,여기서는 Menu1에게 doClick1 메서드를 호출해달라고 요청한다.
	//doClick 메서드를 호출할 때, 누가 메서드를 호출했는지 자기자신 (여기서는 MenuItem1,2,3을 전달한다.)
	auto pMenuItem1 = MenuItemFont::create("Menu-1", 
		CC_CALLBACK_1(Menu02::doClick, this));
	pMenuItem1->setColor(Color3B::BLACK);

	auto pMenuItem2 = MenuItemFont::create("menu-2",
		CC_CALLBACK_1(Menu02::doClick, this));
	pMenuItem2->setColor(Color3B::RED);

	auto pMenuItem3 = MenuItemImage::create(
		"Button/btn-play-normal.png", "Button/btn-play-selected.png",
		CC_CALLBACK_1(Menu02::doClick, this));
	
	//각각의 메뉴아이템에 태그를 부여한다.
	//이 태그값을 이용해서 doClick메서드에서 선택된 메뉴아이템을 구분해 로그를 출력할 수 있다.
	pMenuItem1->setTag(1);
	pMenuItem2->setTag(2);
	pMenuItem3->setTag(3);

	auto pMenu = Menu::create(pMenuItem1, pMenuItem2, pMenuItem3, nullptr);

	pMenu->alignItemsHorizontally();

	this->addChild(pMenu);


	return true;
}

void Menu02::doClick(Ref* pSender)
{
	//인자로 들어온 pSender MenuItemFont 일수도 MenuItemImage 일수도있다
	//그래서 보통 부모클래스인 MenuItem으로 참조해서 처리한다.
	auto tItem = (MenuItem*)pSender;
	//getTag메서드로 pSender로 전달한 객체의 태그 번호를 구한다
	int i = tItem->getTag();

	//log를 통해 결과를 출력한다. 사용법은 c언어 printf와 유사
	log("%d 번재 메뉴가 선택되었습니다.", i);


}