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
        "StartGame",
        CC_CALLBACK_1(StartScene::doPushScene, this));
    item1->setColor(Color3B::BLACK);
    item1->setTag(1);

    auto pMenu = Menu::create(item1, nullptr);
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
        _director->getTextureCache()->removeUnusedTextures();

        auto pScene = GameScene::createScene();
        Director::getInstance()->replaceScene(pScene);
    }
    
}
