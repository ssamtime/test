#include "StartScene.h"

USING_NS_CC;

Scene* StartScene::createScene()
{
    return StartScene::create();
}

// on "init" you need to initialize your instance
bool StartScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto wlayer = LayerColor::create(Color4B::WHITE);
    this->addChild(wlayer);

    MenuItemFont::setFontSize(30);

    auto item1 = MenuItemFont::create(
        "MapTool",
        CC_CALLBACK_1(StartScene::doPushScene, this));
    item1->setColor(Color3B::BLACK);
    item1->setTag(1);

    auto item2 = MenuItemFont::create(
        "GameScene",
        CC_CALLBACK_1(StartScene::doPushScene, this));
    item2->setColor(Color3B::BLACK);
    item2->setTag(2);

    auto pMenu = Menu::create(item1, item2, nullptr);
    pMenu->alignItemsVertically();

    this->addChild(pMenu);

    return true;
}

void StartScene::doPushScene(Ref* pSender)
{
    auto tItem = (MenuItem*)pSender;
    int i = tItem->getTag();

    if (i == 1)
    {
        // ¸ÊÅø
    }
    else
    {
        _director->getTextureCache()->removeUnusedTextures();

        auto pScene = GameScene::createScene();
        Director::getInstance()->replaceScene(pScene);
    }
}
