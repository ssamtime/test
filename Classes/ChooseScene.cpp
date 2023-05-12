#include "ChooseScene.h"

USING_NS_CC;


//케릭터 선택화면
//죽었을때 연결이나 목숨까지고 부활
//폭탄 닿으면 터지는효과 
//돈넣으면소리 총쏘는소리 죽는소리 보스터지는소리

Scene* ChooseScene::createScene()
{
    return ChooseScene::create();
}

// on "init" you need to initialize your instance
bool ChooseScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto wlayer = LayerColor::create(Color4B::WHITE);
    this->addChild(wlayer);

    auto selectboundary = Sprite::create("opening/SOLDIER_SELECT_0.png");
    selectboundary->setAnchorPoint(Vec2(0, 0));
    selectboundary->setPosition(Vec2(0,0));
    selectboundary->setScale(3.44f);
    selectboundary->setZOrder(6);
    this->addChild(selectboundary);
       
    auto player1picture = Sprite::create("opening/Marco_0.png");
    player1picture->setAnchorPoint(Vec2(0, 0));
    player1picture->setPosition(Vec2(62, 110));
    player1picture->setScale(3.44f);
    player1picture->setZOrder(7);
    this->addChild(player1picture);

    auto player2picture = Sprite::create("opening/Eri_0.png");
    player2picture->setAnchorPoint(Vec2(0, 0));
    player2picture->setPosition(Vec2(296, 110));
    player2picture->setScale(3.44f);
    player2picture->setZOrder(7);
    this->addChild(player2picture);

    auto player3picture = Sprite::create("opening/Tarma_0.png");
    player3picture->setAnchorPoint(Vec2(0, 0));
    player3picture->setPosition(Vec2(530, 110));
    player3picture->setScale(3.44f);
    player3picture->setZOrder(7);
    this->addChild(player3picture);

    auto player4picture = Sprite::create("opening/Fio_0.png");
    player4picture->setAnchorPoint(Vec2(0, 0));
    player4picture->setPosition(Vec2(764, 110));
    player4picture->setScale(3.44f);
    player4picture->setZOrder(7);
    this->addChild(player4picture);

    auto p1lightanimation = Animation::create();
    p1lightanimation->setDelayPerUnit(0.15);
    p1lightanimation->addSpriteFrameWithFile("opening/P1_Screen_1.png");
    p1lightanimation->addSpriteFrameWithFile("opening/P1_Screen_0.png");
    p1lightanimation->addSpriteFrameWithFile("opening/P1_Screen_1.png");
    auto p1lightanimate = Animate::create(p1lightanimation);

    auto p1light1 = Sprite::create("opening/P1_Screen_0.png");
    p1light1->setAnchorPoint(Vec2(0, 0));
    p1light1->setPosition(Vec2(90, 530));
    p1light1->setScale(3.44f);
    p1light1->setZOrder(7);
    this->addChild(p1light1);
    p1light1->runAction(p1lightanimate);
    //repforever

    auto p1light2 = Sprite::create("opening/P1_Screen_0.png");
    p1light2->setAnchorPoint(Vec2(0, 0));
    p1light2->setPosition(Vec2(324, 530));
    p1light2->setScale(3.44f);
    p1light2->setZOrder(7);
    this->addChild(p1light2);

    auto p1light3 = Sprite::create("opening/P1_Screen_0.png");
    p1light3->setAnchorPoint(Vec2(0, 0));
    p1light3->setPosition(Vec2(557, 530));
    p1light3->setScale(3.44f);
    p1light3->setZOrder(7);
    this->addChild(p1light3);

    auto p1light4 = Sprite::create("opening/P1_Screen_0.png");
    p1light4->setAnchorPoint(Vec2(0, 0));
    p1light4->setPosition(Vec2(791, 530));
    p1light4->setScale(3.44f);
    p1light4->setZOrder(7);
    this->addChild(p1light4);

    




    // 4개짜리 배열만들어서 선택되면 애니메이션 실행되고 화살표로 움직이면 되려나
    return true;
}


void ChooseScene::onEnter()
{
    Scene::onEnter();

    _listener = EventListenerKeyboard::create();

    //콜백함수 연결
    _listener->onKeyPressed = CC_CALLBACK_2(ChooseScene::onKeyPressed, this);
    _listener->onKeyReleased = CC_CALLBACK_2(ChooseScene::onKeyReleased, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void ChooseScene::onExit()
{
    _eventDispatcher->removeEventListener(_listener);

    Scene::onExit();
}

void ChooseScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
    switch (keycode)
    {

    case EventKeyboard::KeyCode::KEY_1:
        
         
        break;
    case EventKeyboard::KeyCode::KEY_A:
        _director->getTextureCache()->removeUnusedTextures();

        auto pScene = GameScene::createScene();
        Director::getInstance()->replaceScene(pScene);
        
        break;
    }
}

void ChooseScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
    switch (keycode)
    {

    case EventKeyboard::KeyCode::KEY_1:
        
        break;
    case EventKeyboard::KeyCode::KEY_A:
        
        break;
    }
}

