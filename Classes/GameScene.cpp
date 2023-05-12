#include "GameScene.h"


USING_NS_CC;
using namespace std;

bool _pressA;
bool _pressD;
//bool isMachinegun;

Scene* GameScene::createScene()
{
    return GameScene::create();
}
GameScene::GameScene() {
    score = 0;
    machinguncount=200;
    bombcount=10;
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

    background1 = Sprite::create("mission1background.png");
    background1->setAnchorPoint(Vec2(0, 0));
    background1->setPosition(Vec2(0, 0));
	background1->setZOrder(0);
    this->addChild(background1);

    Player* player = Player::create();
    addChild(player);

    Weapon* weapon = Weapon::create();
    addChild(weapon);

    Enemy* enemy = Enemy::create();
    addChild(enemy);

    auto fuelbar = Sprite::create("fuelbar.png");
    fuelbar->setScale(4);
    fuelbar->setAnchorPoint(Vec2(0, 0));
    fuelbar->setPosition(Vec2(50, 675));
    fuelbar->setZOrder(5);
    this->addChild(fuelbar);

    auto armsbombboundary = Sprite::create("armsbomb.png");
    armsbombboundary->setScale(4);
    armsbombboundary->setAnchorPoint(Vec2(0, 0));
    armsbombboundary->setPosition(Vec2(300, 670));
    armsbombboundary->setZOrder(5);
    this->addChild(armsbombboundary);

    char scorestr[20];
    sprintf(scorestr, "%d", score);
    scorelabel = Label::createWithTTF(scorestr, "fonts/metal-slug.ttf", 24);
    scorelabel->setPosition(Vec2(230, 730));
    scorelabel->setTextColor(Color4B(220, 228, 237, 255));
    scorelabel->enableShadow(Color4B::BLACK, Size(2, -2), 4);
    this->addChild(scorelabel);

    auto life1 = Sprite::create("life1.png");
    life1->setScale(3);
    life1->setAnchorPoint(Vec2(0, 0));
    life1->setPosition(Vec2(70, 650));
    life1->setZOrder(5);
    this->addChild(life1);

    auto lifeU = Sprite::create("lifeU.png");
    lifeU->setScale(3);
    lifeU->setAnchorPoint(Vec2(0, 0));
    lifeU->setPosition(Vec2(93, 650));
    lifeU->setZOrder(5);
    this->addChild(lifeU);

    auto lifeP = Sprite::create("lifeP.png");
    lifeP->setScale(3);
    lifeP->setAnchorPoint(Vec2(0, 0));
    lifeP->setPosition(Vec2(120, 650));
    lifeP->setZOrder(5);
    this->addChild(lifeP);

    auto lifeequal = Sprite::create("lifeequal.png");
    lifeequal->setScale(3);
    lifeequal->setAnchorPoint(Vec2(0, 0));
    lifeequal->setPosition(Vec2(149, 652));
    lifeequal->setZOrder(5);
    this->addChild(lifeequal);

    auto life = Sprite::create("life1.png");
    life->setScale(3);
    life->setAnchorPoint(Vec2(0, 0));
    life->setPosition(Vec2(175, 650));
    life->setZOrder(5);
    this->addChild(life);

    auto timesprite = Sprite::create("9.png");
    timesprite->setAnchorPoint(Vec2(0, 0));
    timesprite->setPosition(Vec2(615, 670));
    timesprite->setScale(3);
    timesprite->setZOrder(6);
    this->addChild(timesprite);

    auto timeanimation = Animation::create();
    timeanimation->setDelayPerUnit(9);
    timeanimation->addSpriteFrameWithFile("9.png");
    timeanimation->addSpriteFrameWithFile("8.png");
    timeanimation->addSpriteFrameWithFile("7.png");
    timeanimation->addSpriteFrameWithFile("6.png");
    timeanimation->addSpriteFrameWithFile("5.png");
    timeanimation->addSpriteFrameWithFile("4.png");
    timeanimation->addSpriteFrameWithFile("3.png");
    timeanimation->addSpriteFrameWithFile("2.png");
    timeanimation->addSpriteFrameWithFile("1.png");
    timeanimation->addSpriteFrameWithFile("0.png");
    auto timeanimate = Animate::create(timeanimation);
    timesprite->runAction(timeanimate);

    auto timesprite5 = Sprite::create("5.png");
    timesprite5->setAnchorPoint(Vec2(0, 0));
    timesprite5->setPosition(Vec2(560, 670));
    timesprite5->setScale(3);
    timesprite5->setZOrder(6);
    this->addChild(timesprite5);

    char bombcountstr[20];
    sprintf(bombcountstr, "%d", bombcount);
    auto bombcountlabel = Label::createWithTTF(bombcountstr, "fonts/metal-slug.ttf", 24);
    bombcountlabel->setPosition(Vec2(485, 700));
    //scorelabel->setTextColor(Color4B(255, 165, 0, 255));
    bombcountlabel->setTextColor(Color4B(255, 200, 50, 255));
    bombcountlabel->enableShadow(Color4B::BLACK, Size(2, -2), 6);
    this->addChild(bombcountlabel);

    infinitysprite = Sprite::create("infinity.png");
    infinitysprite->setAnchorPoint(Vec2(0, 0));
    infinitysprite->setPosition(Vec2(350, 677));
    infinitysprite->setScale(1.5f);
    infinitysprite->setZOrder(6);
    this->addChild(infinitysprite);
    
    guncountlabel = Label::createWithTTF("∞", "fonts/metal-slug.ttf", 24);
    guncountlabel->setPosition(Vec2(360, 700));
    guncountlabel->setTextColor(Color4B(255, 200, 50, 255));
    guncountlabel->enableShadow(Color4B::BLACK, Size(2, -2), 6);
    this->addChild(guncountlabel);



    this->scheduleUpdate();

    return true;
}

void GameScene::update(float f)
{
    char scorestr[20];
    sprintf(scorestr, "%d", score);
    scorelabel->setString(scorestr); // Label 객체의 내용 업데이트

    if (isMachinegun)
    {
        infinitysprite->runAction(Hide::create());
        char guncountstr[20];
        sprintf(guncountstr, "%d", machinguncount);
        guncountlabel->setString(guncountstr);
    }
    

}

