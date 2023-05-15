#include "StartScene.h"

USING_NS_CC;

//credit표시
//죽었을때 연결이나 목숨까지고 부활

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

    soundId = cocos2d::experimental::AudioEngine::play2d("sound/Title.mp3");
        
    credit = 0;
    isshown = false;

    auto wlayer = LayerColor::create(Color4B::WHITE);
    this->addChild(wlayer);

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


    auto opening = Sprite::create("opening/Opening_0.png");
    opening->setAnchorPoint(Vec2(0, 0));
    opening->setPosition(Vec2(0,0));
    opening->setScale(3.44f);
    opening->setZOrder(6);
    this->addChild(opening);

    auto openinganimation = Animation::create();
    openinganimation->setDelayPerUnit(0.05);
    for (int i = 0; i < 103; i++)
    {
        char filename[103];
        sprintf(filename, "opening/Opening_%d.png", i);
        openinganimation->addSpriteFrameWithFile(filename);
    }
    auto openinganimate = Animate::create(openinganimation);

    opening->runAction(openinganimate);

    this->scheduleUpdate();

    return true;
}

void StartScene::onEnter()
{
    Scene::onEnter();

    _listener = EventListenerKeyboard::create();

    //콜백함수 연결
    _listener->onKeyPressed = CC_CALLBACK_2(StartScene::onKeyPressed, this);
    _listener->onKeyReleased = CC_CALLBACK_2(StartScene::onKeyReleased, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void StartScene::onExit()
{
    _eventDispatcher->removeEventListener(_listener);

    Scene::onExit();
}

void StartScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
    switch (keycode)
    {

    case EventKeyboard::KeyCode::KEY_1:
        credit += 1;
        if (!isshown) {
            showmessage();
        }
        soundId = cocos2d::experimental::AudioEngine::play2d("sound/insertcoin.mp3");
        break;
    case EventKeyboard::KeyCode::KEY_A:
        
        cocos2d::experimental::AudioEngine::stop(soundId);

        _director->getTextureCache()->removeUnusedTextures();

        auto pScene = ChooseScene::createScene();
        Director::getInstance()->replaceScene(pScene);
        
        break;
    }
}

void StartScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
    switch (keycode)
    {

    case EventKeyboard::KeyCode::KEY_1:
        
        break;
    case EventKeyboard::KeyCode::KEY_A:
        
        break;
    }
}

void StartScene::update(float f)
{
    char creditstr[20];
    sprintf(creditstr, "%d", credit);
    char str1[20] = "CREDITS :";
    strcat(str1, creditstr);
        
    creditlabel->setString(str1);
}

void StartScene::showmessage()
{
    auto pressstartmessage = Sprite::create("opening/PRESSSTART_0.png");
    pressstartmessage->setAnchorPoint(Vec2(0, 0));
    pressstartmessage->setPosition(Vec2(350, 60));
    pressstartmessage->setScale(3);
    pressstartmessage->setZOrder(7);
    this->addChild(pressstartmessage);
    auto blinkAction = Blink::create(10, 20);
    pressstartmessage->runAction(blinkAction);

    isshown = true;
}
