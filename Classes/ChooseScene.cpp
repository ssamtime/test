#include "ChooseScene.h"

USING_NS_CC;

int credit;

//죽었을때 연결이나 목숨까지고 부활 

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

    soundId2 = cocos2d::experimental::AudioEngine::play2d("sound/CharacterSelect.mp3");
    cocos2d::experimental::AudioEngine::setVolume(soundId2, 0.3);

    auto wlayer = LayerColor::create(Color4B::BLACK);
    this->addChild(wlayer);

    auto selectboundary = Sprite::create("opening/SOLDIER_SELECT_0.png");
    selectboundary->setAnchorPoint(Vec2(0, 0));
    selectboundary->setPosition(Vec2(0,0));
    selectboundary->setScale(3.44f);
    selectboundary->setZOrder(3);
    this->addChild(selectboundary);
       
    player1picture = Sprite::create("opening/Marco_1.png");
    player1picture->setAnchorPoint(Vec2(0, 0));
    player1picture->setPosition(Vec2(62, 110));
    player1picture->setScale(3.44f);
    player1picture->setZOrder(1);
    this->addChild(player1picture);

    player2picture = Sprite::create("opening/Eri_0.png");
    player2picture->setAnchorPoint(Vec2(0, 0));
    player2picture->setPosition(Vec2(296, 110));
    player2picture->setScale(3.44f);
    player2picture->setZOrder(1);
    this->addChild(player2picture);

    player3picture = Sprite::create("opening/Tarma_0.png");
    player3picture->setAnchorPoint(Vec2(0, 0));
    player3picture->setPosition(Vec2(530, 110));
    player3picture->setScale(3.44f);
    player3picture->setZOrder(1);
    this->addChild(player3picture);

    player4picture = Sprite::create("opening/Fio_0.png");
    player4picture->setAnchorPoint(Vec2(0, 0));
    player4picture->setPosition(Vec2(764, 110));
    player4picture->setScale(3.44f);
    player4picture->setZOrder(1);
    this->addChild(player4picture);


    p1light1 = Sprite::create("opening/P1_Screen_0.png");
    p1light1->setAnchorPoint(Vec2(0, 0));
    p1light1->setPosition(Vec2(90, 530));
    p1light1->setScale(3.44f);
    p1light1->setZOrder(4);
    this->addChild(p1light1);

    p1light2 = Sprite::create("opening/P1_Screen_0.png");
    p1light2->setAnchorPoint(Vec2(0, 0));
    p1light2->setPosition(Vec2(324, 530));
    p1light2->setScale(3.44f);
    p1light2->setZOrder(4);
    this->addChild(p1light2);

    p1light3 = Sprite::create("opening/P1_Screen_0.png");
    p1light3->setAnchorPoint(Vec2(0, 0));
    p1light3->setPosition(Vec2(557, 530));
    p1light3->setScale(3.44f);
    p1light3->setZOrder(4);
    this->addChild(p1light3);

    p1light4 = Sprite::create("opening/P1_Screen_0.png");
    p1light4->setAnchorPoint(Vec2(0, 0));
    p1light4->setPosition(Vec2(791, 530));
    p1light4->setScale(3.44f);
    p1light4->setZOrder(4);
    this->addChild(p1light4);

    p1lightanimation = Animation::create();
    p1lightanimation->setDelayPerUnit(0.7);
    p1lightanimation->addSpriteFrameWithFile("opening/P1_Screen_0.png");
    p1lightanimation->addSpriteFrameWithFile("opening/P1_Screen_1.png");
    p1lightanimation->addSpriteFrameWithFile("opening/P1_Screen_0.png");
    p1lightanimation->addSpriteFrameWithFile("opening/P1_Screen_1.png");
    p1lightanimate = Animate::create(p1lightanimation);
    p1lightanimateRepFoever1 = RepeatForever::create(p1lightanimate);
    p1lightanimateRepFoever1->retain();

    p1light1->runAction(p1lightanimateRepFoever1);
    p1light2->runAction(Hide::create());
    p1light3->runAction(Hide::create());
    p1light4->runAction(Hide::create());
    
    number = 1;

    char creditstr[20];
    sprintf(creditstr, "%d", credit);
    char str1[20] = "CREDITS : ";
    strcat(str1, creditstr);

    creditlabel = Label::createWithTTF(str1, "fonts/metal-slug.ttf", 24);
    creditlabel->setPosition(Vec2(880, 60));
    creditlabel->setTextColor(Color4B(220, 228, 237, 255));
    creditlabel->setZOrder(9);
    creditlabel->enableShadow(Color4B::BLACK, Size(2, -2), 4);
    this->addChild(creditlabel);
    

    this->scheduleUpdate();

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
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        p1light1->stopAllActions();
        p1light2->stopAllActions();
        p1light3->stopAllActions();
        p1light4->stopAllActions();
        p1light1->runAction(Hide::create());
        p1light2->runAction(Hide::create());
        p1light3->runAction(Hide::create());
        p1light4->runAction(Hide::create());

        player1picture->setTexture("opening/Marco_0.png");
        player2picture->setTexture("opening/Eri_0.png");
        player3picture->setTexture("opening/Tarma_0.png");
        player4picture->setTexture("opening/Fio_0.png");

        if (number == 1)
            number = 4;
        else
            number -= 1;
        
        lightsprite();
        
        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        p1light1->stopAllActions();
        p1light2->stopAllActions();
        p1light3->stopAllActions();
        p1light4->stopAllActions();
        p1light1->runAction(Hide::create());
        p1light2->runAction(Hide::create());
        p1light3->runAction(Hide::create());
        p1light4->runAction(Hide::create());

        player1picture->setTexture("opening/Marco_0.png");
        player2picture->setTexture("opening/Eri_0.png");
        player3picture->setTexture("opening/Tarma_0.png");
        player4picture->setTexture("opening/Fio_0.png");

        if (number == 4)
            number = 1;
        else
            number += 1;
        
        lightsprite();
        
        break;
    
    case EventKeyboard::KeyCode::KEY_1:
        credit += 1;
        
        soundId12 = cocos2d::experimental::AudioEngine::play2d("sound/insertcoin.mp3");
        break;
    case EventKeyboard::KeyCode::KEY_A:
        characterlockin();
        
        
        break;
    }
}

void ChooseScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
    switch (keycode)
    {
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        
        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        
        break;
    case EventKeyboard::KeyCode::KEY_1:
        
        break;
    case EventKeyboard::KeyCode::KEY_A:
        
        break;
    }
}

void ChooseScene::lightsprite()
{
    int soundId3 = cocos2d::experimental::AudioEngine::play2d("sound/MenuSelection.mp3");

    if (number == 1)
    {
        p1light1->runAction(Show::create());
        p1light1->runAction(p1lightanimateRepFoever1);
        player1picture->setTexture("opening/Marco_1.png");
    }
    if (number == 2)
    {
        p1light2->runAction(Show::create());
        p1light2->runAction(p1lightanimateRepFoever1);
        player2picture->setTexture("opening/Eri_1.png");
    }
    if (number == 3)
    {
        p1light3->runAction(Show::create());
        p1light3->runAction(p1lightanimateRepFoever1);
        player3picture->setTexture("opening/Tarma_1.png");
    }
    if (number == 4)
    {
        p1light4->runAction(Show::create());
        p1light4->runAction(p1lightanimateRepFoever1);
        player4picture->setTexture("opening/Fio_1.png");
    }
}

void ChooseScene::characterlockin()
{
    int soundId4 = cocos2d::experimental::AudioEngine::play2d("sound/okay.mp3");

    player4picture->setTexture("opening/Fio_2.png");

    auto lockboundary = Sprite::create("opening/M2_0.png");
    lockboundary->setAnchorPoint(Vec2(0, 0));
    lockboundary->setPosition(Vec2(764, 690));
    lockboundary->setScale(3.44f);
    lockboundary->setZOrder(2);
    this->addChild(lockboundary);

    auto player = Sprite::create("Fio.png");
    player->setAnchorPoint(Vec2(0, 0));
    player->setPosition(Vec2(821, 820));
    player->setScale(3.44f);
    player->setZOrder(2);
    this->addChild(player);

    auto moveby1 = MoveBy::create(1, Vec2(0, -600));
    auto moveby2 = MoveBy::create(1, Vec2(0, -600));
    lockboundary->runAction(moveby1);
    
    auto seq = Sequence::create(moveby2, DelayTime::create(1.0f),
        CallFunc::create(CC_CALLBACK_0(ChooseScene::function2, this)), nullptr);
    player->runAction(seq);
}

void ChooseScene::function2()
{
    auto director = cocos2d::Director::getInstance();
    auto textureCache = director->getTextureCache();
    textureCache->removeUnusedTextures();

    auto gameScene = GameScene::createScene();
    director->replaceScene(gameScene);

    cocos2d::experimental::AudioEngine::stop(soundId2);
}

void ChooseScene::update(float f)
{
    char creditstr[20];
    sprintf(creditstr, "%d", credit);
    char str1[20] = "CREDITS :";
    strcat(str1, creditstr);

    creditlabel->setString(str1);
}



