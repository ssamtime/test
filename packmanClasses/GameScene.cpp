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

    // 게임 매니저 인스턴스 불러오기
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
    // 종료 루틴을 넣어준다.
    _director->getTextureCache()->removeUnusedTextures();

    auto pScene = StartScene::createScene();
    Director::getInstance()->replaceScene(pScene);

    // 제거
    GameManager::getInstance().removeFromParent();
    GameManager::getInstance().releaseInstance();
}
