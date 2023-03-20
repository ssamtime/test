#include "cocos2d.h"

enum eName {FIRE = 0, SUN, GALAXY, SPIRAL, 
SMOKE, METEOR, FLOWER, FIREWORKS, EXPLOSION};

class Particle01 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Particle01);
	///////////////////////////

	void ShowParticle(Ref* pSender);
};
