#include "GameScene.h"
#include "GameManager.h"
#include "StartScene.h"

USING_NS_CC;
using namespace std;

Scene* GameScene::createScene()
{
    return GameScene::create();
}


// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto wlayer = LayerColor::create(Color4B::WHITE);
    this->addChild(wlayer);

    auto background1 = Sprite::create("mission1background.png");
    background1->setAnchorPoint(Vec2(0, 0));
    background1->setPosition(Vec2(0, 0));
	background1->setZOrder(0);
    this->addChild(background1);

	player = Sprite::create("Fio.png");
	player->setScale(3);
	player->setAnchorPoint(Vec2(0, 0));
	player->setPosition(Vec2(100, 100));
	player->setZOrder(5);
	this->addChild(player);



    return true;
}

