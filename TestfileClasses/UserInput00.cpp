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
	//����Ʈ �ڽ��� �ƹ��͵� �Էµ��� �ʾ����� �⺻������ ������ִ� �ؽ�Ʈ
	_editName->setPlaceHolder("Name:");
	_editName->setPlaceholderFontColor(Color3B::WHITE);
	//�ִ�� �Է¹��� �� �ִ� ���ڼ��� �����Ѵ�.
	_editName->setMaxLength(8);
	_editName->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
	//����Ʈ �ڽ��� �Է��� �߻��ϸ� � ��ü�� �̺�Ʈ�� ���� �� ó������ ������ �����Ѵ�.
	_editName->setDelegate(this);
	_editName->setAnchorPoint(Vec2(0, 0));
	this->addChild(_editName);


	//middle �н�����
	_editPassword = ui::EditBox::create(editBoxSize, "orange_edit.png");
	_editPassword->setPosition(Vec2(512, 284));
	_editPassword->setFontSize(25);
	_editPassword->setFontColor(Color3B::GREEN);
	_editPassword->setPlaceHolder("Password");
	_editPassword->setMaxLength(6);
	_editPassword->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
	//�� �Է��� �� *ǥ�÷� �ٲپ� ����ڿ��� ǥ�õ��� �ʰ� ���ش�.
	_editPassword->setInputFlag(ui::EditBox::InputFlag::PASSWORD);
	//�Է��� �����ٷ� ������ �ʰ� ���ٸ� �Էµǰ� �Ѵ�.
	_editPassword->setInputMode(ui::EditBox::InputMode::SINGLE_LINE);
	_editPassword->setDelegate(this);
	_editPassword->setAnchorPoint(Vec2(0, 0));
	this->addChild(_editPassword);

	//bottom email
	_editEmail = ui::EditBox::create(Size(editBoxSize.width, editBoxSize.height), "yellow_edit.png");
	_editEmail->setPosition(Vec2(512, 184));
	_editEmail->setFontSize(25);
	_editEmail->setPlaceHolder("Email:");
	//�Ϲ� �Է¿� Ű���尡 �ƴ� �̸����ּҸ� �Է��ϱ� ���� Ű���� ������ �����ش�.
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
