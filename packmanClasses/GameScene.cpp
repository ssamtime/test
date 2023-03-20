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

    // ���� �Ŵ��� �ν��Ͻ� �ҷ�����
    GameManager::createInstance();
    GameManager* gameLayer = &GameManager::getInstance();

    gameLayer->create(this, callfunc_selector(GameScene::GameManagerCallback));
    gameLayer->setAnchorPoint(Vec2(0, 0));
    gameLayer->setZOrder(2);
    this->addChild(gameLayer);
   
    return true;
}

void GameScene::GameManagerCallback()
{
    // ���� ��ƾ�� �־��ش�.
    _director->getTextureCache()->removeUnusedTextures();

    auto pScene = StartScene::createScene();
    Director::getInstance()->replaceScene(pScene);

    // ����
    GameManager::getInstance().removeFromParent();
    GameManager::getInstance().releaseInstance();
}
