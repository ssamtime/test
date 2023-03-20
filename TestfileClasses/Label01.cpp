//레이블

/*
레이블을 사용하면 텍스트를 화면에 추가하거나,
추가한 텍스트의 내용이나 위치를 변경 혹은 조정할 수 있다.
또한 텍스트에 액션이나 애니메이션도 적용할 수 있다.

시스템폰트, 비트맵폰트, 캐릭터맵폰트, 트루타입 폰트가 있다.

Label::createWithSystemFont
Label::createWithBMFont
Label::createWithCharFont
Label::createWithTTF
*/

//시스템 폰트 사용하기
/*
시스템에 내장된 폰트를 사용하는 문자표현 방식이다.
별도의 폰트를 지정하지 않거나 해당 폰트가 없으면 시스템폰트가 자동으로 적용됨
*/

//비트맵 폰트
/*
비트맵폰트파일은 이미지파일이므로 기본폰트를 이용해 텍스트를 출력하는 것에 비해
각 글자의 모양을 훨씬 더 다양하게 만들 수 있다는 장점이있다.
또한 각 글자를 별개의 스프라이트로 처리하기 때문에 글자를 하나씩 변형하거나 액션을 줄수있다.

비트맵 폰트파일 사용하려면 같은 이름의 fnt파일과 png파일이 필요하다.
fnt 이름.fnt :텍스트 형태의 파일로 폰트의 각 글자에 대한 이미지 정보를 담고 있다.
이름.png :이미지 파일이다.

비트맵파일을 만드는 방법으로는 포토샵같은이미지 편집기를 사용해 직접글자모양 디자인하는 방법이있다.
*/
//캐릭터맵
/*
비트맵폰트파일과 마찬가지로 캐릭터맵파일은 이미지파일이므로 기본폰트를 이용해 텍스트를 출력하는것에비해 
각글자의 모양을 훨씬 다양하게 만들수 있다는 장점이있다
각글자를 별개의 스프라이트로 처리하기 때문에 글자를 하나씩 변형하거나 액션을 줄 수 있다.

비트맵 폰트가 글자에 대한 정보를 텍스트 파일에 저장하는 것과는 달리 캐릭터맵은 이미지로만 되어있다.
캐릭터맵을 사용할 때 정보를 따로 제공받지 않는 이유는 다음과 같이 미리 정해진 규칙이 있기 때문이다.

-스프라이트 시트에 아스키코드 순서에 맞춰서 글자를 위치시켜 그린다.
-모든 글자의 너비와 높이가 같다.
-스프라이트 시트에 그려진 첫 번째 글자의 아스키 코드값을 알려준다.
-출력을 위해 입력된값은 첫번째 아스키 코드로부터 몇 번째의 그랒인지판단하고 캐릭터 맵에서 읽어온다.

캐릭터맵에서 글자를 잘라올때 좌표의 시작점은 좌측 상단이다.
*/
//트루타입 폰트 사용하기
/*
디바이스에 저장된 폰트가 아닌 본인이 원하는 폰트를 사용하고 싶을 때 파일을 따로 받아서 사용할 수 있다.(ttf)

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
		"동해물과 백두산이 마르고 닳도록 하느님이 보우하사 우리나라 만세 무궁화 삼천리 화려강산", "", 34);
	pLabel2->setPosition(640, 360);
	pLabel2->setTextColor(Color4B::BLACK);
	this->addChild(pLabel2);*/

	//자동개행
	//Size:길게 입력된내용이 출력될 공간의 크기를 지정
	//TextHalignment:가로정렬
	//TextVAlignment:세로정렬
	auto pLabel2 = Label::createWithSystemFont(
		"동해물과 백두산이 마르고 닳도록 하느님이 보우하사 우리나라만세", "", 34, Size(300, 200), TextHAlignment::CENTER,
		TextVAlignment::CENTER);
	pLabel2->setPosition(640, 500);
	pLabel2->setTextColor(Color4B::BLACK);
	this->addChild(pLabel2);

	//비트맵 폰트 생성 및 포기화
	auto pLabel3 = Label::createWithBMFont("fonts/bitmapFontTest.fnt", "Hello World");
	pLabel3->setPosition(Vec2(640, 400));
	this->addChild(pLabel3);

	//캐릭터맵 폰트 생성 및 초기화
	auto pLabel4 = Label::createWithCharMap("fonts/tuffy_bold_italic-charmap.png",48,64,' ');
	pLabel4->setPosition(Vec2(640, 300));
	pLabel4->setString("1234");
	//캐릭터맵은 이미지 파일이라setTextColor 적용이 불가능하다.
	pLabel4->setColor(Color3B::BLACK);
	this->addChild(pLabel4);

	//TTF 폰트 사용하기
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