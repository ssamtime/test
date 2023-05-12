#include "StartScene.h"

USING_NS_CC;


//������ 
//���ְ� ���� 
//�ɸ��� ����ȭ��
//�׾����� �����̳� ��������� ��Ȱ
//��ź ������ ������ȿ�� 
//��������Ҹ� �ѽ�¼Ҹ� �״¼Ҹ� ���������¼Ҹ�

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

    coin = 0;
    isshown = false;

    auto wlayer = LayerColor::create(Color4B::WHITE);
    this->addChild(wlayer);

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

   
   

    return true;
}

void StartScene::onEnter()
{
    Scene::onEnter();

    _listener = EventListenerKeyboard::create();

    //�ݹ��Լ� ����
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
        coin += 1;
        if (!isshown) {
            showmessage();
        }
         
        break;
    case EventKeyboard::KeyCode::KEY_A:
        /*_director->getTextureCache()->removeUnusedTextures();

        auto pScene = GameScene::createScene();
        Director::getInstance()->replaceScene(pScene);*/
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
