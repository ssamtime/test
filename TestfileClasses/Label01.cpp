//���̺�

/*
���̺��� ����ϸ� �ؽ�Ʈ�� ȭ�鿡 �߰��ϰų�,
�߰��� �ؽ�Ʈ�� �����̳� ��ġ�� ���� Ȥ�� ������ �� �ִ�.
���� �ؽ�Ʈ�� �׼��̳� �ִϸ��̼ǵ� ������ �� �ִ�.

�ý�����Ʈ, ��Ʈ����Ʈ, ĳ���͸���Ʈ, Ʈ��Ÿ�� ��Ʈ�� �ִ�.

Label::createWithSystemFont
Label::createWithBMFont
Label::createWithCharFont
Label::createWithTTF
*/

//�ý��� ��Ʈ ����ϱ�
/*
�ý��ۿ� ����� ��Ʈ�� ����ϴ� ����ǥ�� ����̴�.
������ ��Ʈ�� �������� �ʰų� �ش� ��Ʈ�� ������ �ý�����Ʈ�� �ڵ����� �����
*/

//��Ʈ�� ��Ʈ
/*
��Ʈ����Ʈ������ �̹��������̹Ƿ� �⺻��Ʈ�� �̿��� �ؽ�Ʈ�� ����ϴ� �Ϳ� ����
�� ������ ����� �ξ� �� �پ��ϰ� ���� �� �ִٴ� �������ִ�.
���� �� ���ڸ� ������ ��������Ʈ�� ó���ϱ� ������ ���ڸ� �ϳ��� �����ϰų� �׼��� �ټ��ִ�.

��Ʈ�� ��Ʈ���� ����Ϸ��� ���� �̸��� fnt���ϰ� png������ �ʿ��ϴ�.
fnt �̸�.fnt :�ؽ�Ʈ ������ ���Ϸ� ��Ʈ�� �� ���ڿ� ���� �̹��� ������ ��� �ִ�.
�̸�.png :�̹��� �����̴�.

��Ʈ�������� ����� ������δ� ���伥�����̹��� �����⸦ ����� �������ڸ�� �������ϴ� ������ִ�.
*/
//ĳ���͸�
/*
��Ʈ����Ʈ���ϰ� ���������� ĳ���͸������� �̹��������̹Ƿ� �⺻��Ʈ�� �̿��� �ؽ�Ʈ�� ����ϴ°Ϳ����� 
�������� ����� �ξ� �پ��ϰ� ����� �ִٴ� �������ִ�
�����ڸ� ������ ��������Ʈ�� ó���ϱ� ������ ���ڸ� �ϳ��� �����ϰų� �׼��� �� �� �ִ�.

��Ʈ�� ��Ʈ�� ���ڿ� ���� ������ �ؽ�Ʈ ���Ͽ� �����ϴ� �Ͱ��� �޸� ĳ���͸��� �̹����θ� �Ǿ��ִ�.
ĳ���͸��� ����� �� ������ ���� �������� �ʴ� ������ ������ ���� �̸� ������ ��Ģ�� �ֱ� �����̴�.

-��������Ʈ ��Ʈ�� �ƽ�Ű�ڵ� ������ ���缭 ���ڸ� ��ġ���� �׸���.
-��� ������ �ʺ�� ���̰� ����.
-��������Ʈ ��Ʈ�� �׷��� ù ��° ������ �ƽ�Ű �ڵ尪�� �˷��ش�.
-����� ���� �ԷµȰ��� ù��° �ƽ�Ű �ڵ�κ��� �� ��°�� �׶������Ǵ��ϰ� ĳ���� �ʿ��� �о�´�.

ĳ���͸ʿ��� ���ڸ� �߶�ö� ��ǥ�� �������� ���� ����̴�.
*/
//Ʈ��Ÿ�� ��Ʈ ����ϱ�
/*
����̽��� ����� ��Ʈ�� �ƴ� ������ ���ϴ� ��Ʈ�� ����ϰ� ���� �� ������ ���� �޾Ƽ� ����� �� �ִ�.(ttf)

*/
#include "label01.h"

USING_NS_CC;

Scene* Label01::createScene()
{
	return Label01::create();
}

bool Label01::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	auto pLabel1 = Label::createWithSystemFont("Hello World!", "", 34);
	pLabel1->setPosition(640, 600);
	pLabel1->setTextColor(Color4B::RED);
	this->addChild(pLabel1);

	/*auto pLabel2 = Label::createWithSystemFont(
		"���ع��� ��λ��� ������ �⵵�� �ϴ����� �����ϻ� �츮���� ���� ����ȭ ��õ�� ȭ������", "", 34);
	pLabel2->setPosition(640, 360);
	pLabel2->setTextColor(Color4B::BLACK);
	this->addChild(pLabel2);*/

	//�ڵ�����
	//Size:��� �Էµȳ����� ��µ� ������ ũ�⸦ ����
	//TextHalignment:��������
	//TextVAlignment:��������
	auto pLabel2 = Label::createWithSystemFont(
		"���ع��� ��λ��� ������ �⵵�� �ϴ����� �����ϻ� �츮���󸸼�", "", 34, Size(300, 200), TextHAlignment::CENTER,
		TextVAlignment::CENTER);
	pLabel2->setPosition(640, 500);
	pLabel2->setTextColor(Color4B::BLACK);
	this->addChild(pLabel2);

	//��Ʈ�� ��Ʈ ���� �� ����ȭ
	auto pLabel3 = Label::createWithBMFont("fonts/bitmapFontTest.fnt", "Hello World");
	pLabel3->setPosition(Vec2(640, 400));
	this->addChild(pLabel3);

	//ĳ���͸� ��Ʈ ���� �� �ʱ�ȭ
	auto pLabel4 = Label::createWithCharMap("fonts/tuffy_bold_italic-charmap.png",48,64,' ');
	pLabel4->setPosition(Vec2(640, 300));
	pLabel4->setString("1234");
	//ĳ���͸��� �̹��� �����̶�setTextColor ������ �Ұ����ϴ�.
	pLabel4->setColor(Color3B::BLACK);
	this->addChild(pLabel4);

	//TTF ��Ʈ ����ϱ�
	TTFConfig ttfConfig("fonts/CookieRun Black.ttf", 40);
	auto pLabel5 = Label::createWithTTF(ttfConfig,"Normal");
	pLabel5->setPosition(Vec2(640, 200));
	pLabel5->setTextColor(Color4B::BLACK);
	this->addChild(pLabel5);
	
	auto pLabel6 = Label::createWithTTF(ttfConfig, "Glow");
	pLabel6->setPosition(Vec2(640, 100));
	pLabel6->setTextColor(Color4B::RED);
	pLabel6->enableShadow(Color4B::BLACK);
	pLabel6->enableOutline(Color4B(0, 255, 0, 255), 10);

	this->addChild(pLabel6);
	return true;
}