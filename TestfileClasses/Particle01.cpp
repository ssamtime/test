#include "Particle01.h"

USING_NS_CC;

Scene* Particle01::createScene()
{
    return Particle01::create();
}

// on "init" you need to initialize your instance
bool Particle01::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

	auto wlayer = 
		LayerColor::create(Color4B::BLACK);
	this->addChild(wlayer);


	//////////////////////////
	// 메뉴 생성
	auto item1 = MenuItemFont::create(
		"Particle Change",
		CC_CALLBACK_1
		(Particle01::ShowParticle, this));
	
	auto pMenu = Menu::create(item1, nullptr);
	pMenu->setPosition(Vec2(640, 100));
	this->addChild(pMenu);

    return true;
}

void Particle01::ShowParticle(Ref* pSender)
{
	this->removeChildByTag(10);
	this->removeChildByTag(11);

	static int nIndex = 0;

	auto dir = Director::getInstance();
	ParticleSystem* particle;
	Texture2D* texture;
	Label* name;

	switch (nIndex)
	{
	case eName::FIRE:
		particle = ParticleFire::create();
		texture = dir->
			getTextureCache()->
			addImage("Images/fire.png");
		name = Label::
			createWithSystemFont("Fire", "", 30);
		break;
	case eName::SUN:
		particle = ParticleSun::create();
		texture = dir->
			getTextureCache()->
			addImage("Images/fire.png");
		name = Label::
			createWithSystemFont("Sun", "", 30);
		break;
	case eName::GALAXY:
		particle = ParticleGalaxy::create();
		texture = dir->getTextureCache()
			->addImage("Images/fire.png");
		name = Label::
			createWithSystemFont("Galaxy", "", 30);
		break;
	case eName::SPIRAL:
		particle = ParticleSpiral::create();
		texture = dir->getTextureCache()
			->addImage("Images/fire.png");
		name = Label::
			createWithSystemFont("Spiral", "", 30);
		break;
	case eName::SMOKE:
		particle = ParticleSmoke::create();
		texture = dir->getTextureCache()
			->addImage("Images/fire.png");
		name = Label::
			createWithSystemFont("Smoke", "", 30);
		break;
	case eName::METEOR:
		particle = ParticleMeteor::create();
		texture = dir->getTextureCache()
			->addImage("Images/fire.png");
		name = Label::
			createWithSystemFont("Meteor", "", 30);
		break;
	case eName::FLOWER:
		particle = ParticleFlower::create();
		texture = dir->getTextureCache()
			->addImage("Images/stars.png");
		name = Label::
			createWithSystemFont("Flower", "", 30);
		break;
	case eName::FIREWORKS:
		particle = ParticleFireworks::create();
		texture = dir->getTextureCache()
			->addImage("Images/stars.png");
		name = Label::
			createWithSystemFont("FireWorks", "", 30);
		break;
	case eName::EXPLOSION:
		particle = ParticleExplosion::create();
		texture = dir->getTextureCache()
			->addImage("Images/stars.png");
		name = Label::
			createWithSystemFont("Explosion", "", 30);
		break;
	default: break;
	}

	nIndex++;
	if (nIndex > 8)
	{
		nIndex = 0;
	}

	particle->setTexture(texture);

	if (particle != nullptr)
	{
		// 파티클의 크기 조정
		particle->setScale(1);

		// 파티클의 지속시간 조정 : -1 'forever'
		particle->setDuration(1);

		particle->setPosition(Vec2(640, 360));
		particle->setTag(10);

		// 파티클의 스피드 조정
		//particle->setSpeed(500);
		this->addChild(particle);

		name->setPosition(Vec2(640, 480));
		name->setTag(11);
		this->addChild(name);
	}
}