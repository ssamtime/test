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

	//�޴� �����ۻ��� �� �ʱ�ȭ
	//�޴��� ��ġ�� ������ this ,���⼭�� Menu1���� doClick1 �޼��带 ȣ���ش޶�� ��û�Ѵ�.
	//doClick �޼��带 ȣ���� ��, ���� �޼��带 ȣ���ߴ��� �ڱ��ڽ� (���⼭�� MenuItem1,2,3�� �����Ѵ�.)
	auto pMenuItem1 = MenuItemFont::create("Menu-1", 
		CC_CALLBACK_1(Menu02::doClick, this));
	pMenuItem1->setColor(Color3B::BLACK);

	auto pMenuItem2 = MenuItemFont::create("menu-2",
		CC_CALLBACK_1(Menu02::doClick, this));
	pMenuItem2->setColor(Color3B::RED);

	auto pMenuItem3 = MenuItemImage::create(
		"Button/btn-play-normal.png", "Button/btn-play-selected.png",
		CC_CALLBACK_1(Menu02::doClick, this));
	
	//������ �޴������ۿ� �±׸� �ο��Ѵ�.
	//�� �±װ��� �̿��ؼ� doClick�޼��忡�� ���õ� �޴��������� ������ �α׸� ����� �� �ִ�.
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
	//���ڷ� ���� pSender MenuItemFont �ϼ��� MenuItemImage �ϼ����ִ�
	//�׷��� ���� �θ�Ŭ������ MenuItem���� �����ؼ� ó���Ѵ�.
	auto tItem = (MenuItem*)pSender;
	//getTag�޼���� pSender�� ������ ��ü�� �±� ��ȣ�� ���Ѵ�
	int i = tItem->getTag();

	//log�� ���� ����� ����Ѵ�. ������ c��� printf�� ����
	log("%d ���� �޴��� ���õǾ����ϴ�.", i);


}