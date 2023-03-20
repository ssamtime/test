#include "UserInput00.h"

USING_NS_CC;

Scene* UserInput00::createScene()
{
	return UserInput00::create();
}

bool UserInput00::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	Size editBoxSize = Size(300, 60);

	//top
	std::string pNormalSprite = "green_edit.png";
	_editName = ui::EditBox::create(editBoxSize, ui::Scale9Sprite::create(pNormalSprite));
	_editName->setPosition(Vec2(512, 384));
	_editName->setFontSize(25);
	_editName->setFontColor(Color3B::RED);
	//에디트 박스에 아무것도 입력되지 않았을때 기본적으로 띄워져있는 텍스트
	_editName->setPlaceHolder("Name:");
	_editName->setPlaceholderFontColor(Color3B::WHITE);
	//최대로 입력받을 수 있는 글자수를 지정한다.
	_editName->setMaxLength(8);
	_editName->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
	//에디트 박스에 입력이 발생하면 어떤 객체가 이벤트를 감시 및 처리해줄 것인지 지정한다.
	_editName->setDelegate(this);
	_editName->setAnchorPoint(Vec2(0, 0));
	this->addChild(_editName);


	//middle 패스워드
	_editPassword = ui::EditBox::create(editBoxSize, "orange_edit.png");
	_editPassword->setPosition(Vec2(512, 284));
	_editPassword->setFontSize(25);
	_editPassword->setFontColor(Color3B::GREEN);
	_editPassword->setPlaceHolder("Password");
	_editPassword->setMaxLength(6);
	_editPassword->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
	//글 입력할 때 *표시로 바꾸어 사용자에게 표시되지 않게 해준다.
	_editPassword->setInputFlag(ui::EditBox::InputFlag::PASSWORD);
	//입력이 여러줄로 나뉘지 않고 한줄만 입력되게 한다.
	_editPassword->setInputMode(ui::EditBox::InputMode::SINGLE_LINE);
	_editPassword->setDelegate(this);
	_editPassword->setAnchorPoint(Vec2(0, 0));
	this->addChild(_editPassword);

	//bottom email
	_editEmail = ui::EditBox::create(Size(editBoxSize.width, editBoxSize.height), "yellow_edit.png");
	_editEmail->setPosition(Vec2(512, 184));
	_editEmail->setFontSize(25);
	_editEmail->setPlaceHolder("Email:");
	//일반 입력용 키보드가 아닌 이메일주소를 입력하기 편한 키보드 자판을 보여준다.
	_editEmail->setInputMode(ui::EditBox::InputMode::EMAIL_ADDRESS);
	_editEmail->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
	_editEmail->setDelegate(this);
	_editEmail->setAnchorPoint(Vec2(0, 0));
	this->addChild(_editEmail);

	return true;
}

void UserInput00::editBoxEditingDidBegin(cocos2d::ui::EditBox * editBox)
{
	log("editBox %p DidBegin!", editBox);
}

void UserInput00::editBoxEditingDidEnd(cocos2d::ui::EditBox * editBox)
{
	log("editBox %p DidEnd", editBox);
}

void UserInput00::editBoxTextChanged(cocos2d::ui::EditBox * editBox, const std::string & text)
{
	log("editBox %p DidChanged!, text %s !", editBox,text.c_str());
}

void UserInput00::editBoxReturn(cocos2d::ui::EditBox * editBox)
{
	log("editBox %p was returned!",editBox);
}
