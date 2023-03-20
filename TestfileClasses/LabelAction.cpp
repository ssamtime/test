#include "LabelAction.h"

USING_NS_CC;

Scene* LabelAction::createScene()
{
	return LabelAction::create();
}

bool LabelAction::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	//auto pLabel = createWithTTF();
	pLabel = Label::createWithTTF("asdf", "fonts/CookieRun Black.ttf", 40);
	pLabel->setColor(Color3B::BLACK);
	pLabel->setPosition(Vec2(300, 300));
	this->addChild(pLabel);

	//auto wChar = (Sprite*)pLabel->getLetter(1);

	/*int i = 0;

	auto wChar1 = (Sprite*)pLabel->getLetter(i);
	wChar1->setColor(Color3B::RED);
	auto pMoveby = MoveBy::create(1, Vec2(0, 100));
	auto reverse = pMoveby->reverse();
	auto seq1 = Sequence::create(pMoveby, reverse, DelayTime::create(1.0f), nullptr);
	wChar1->runAction(seq1);

	i++;

	auto wChar2 = (Sprite*)pLabel->getLetter(i);
	wChar2->setColor(Color3B::RED);
	wChar2->runAction(seq1);*/

	doAction();

	//int j, n = pLabel->getStringLength();
	//for (j = 0; j < n; ++j)
	//{		
	//	auto wChar = (Sprite*)pLabel->getLetter(j);
	//	wChar->setColor(Color3B::RED);
	//	auto pMoveby = MoveBy::create(1,Vec2(0,100));
	//	auto reverse = pMoveby->reverse();
	//	auto seq1 = Sequence::create(pMoveby,reverse, nullptr);
	//	wChar->runAction(seq1);
	//}

	return true;
}

void LabelAction::doAction()
{
	MoveBy* pMoveBy[10];
	Sprite* wChar[10];
	Sequence* seq[10];
	
	int count = pLabel->getStringLength();
	for (int i = 0; i < count; i++)
	{
		wChar[i] = (Sprite*)pLabel->getLetter(i);
		wChar[i]->setColor(Color3B::RED);
		pMoveBy[i] = MoveBy::create(1, Vec2(0, 100));
		auto reverse = pMoveBy[i]->reverse();
		seq[i] = Sequence::create(pMoveBy[i], reverse, DelayTime::create(2.0f), nullptr);
		
	}

	for (int i = 0; i < count; i++)
	{
		wChar[i]->runAction(seq[i]);
	}
	
}
