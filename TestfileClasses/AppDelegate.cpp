#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "image01.h"
#include "Image02.h"
#include "Image03.h"
#include "label01.h"
#include "Menu01.h"
#include "Menu02.h"
#include "Action01.h"
#include "Action02.h"
#include "Action03.h"
#include "ActionScroll.h"
#include "Animation00.h"
#include "Animation01.h"
#include "Animation02.h"
#include "Schedule00.h"
#include "Schedule01.h"
#include "Schedule02.h"
#include "LabelAction.h"
#include "touch00.h"
#include "touch01.h"
#include "touch02.h"
#include "Collision00.h"
#include "Homework02.h"
#include "Homework02Answer.h"

#include "Scroll00.h"
#include "Scroll01.h"
#include "Particle01.h"
#include "Sound00.h"
#include "Keyboard00.h"
#include "Tile00.h"
#include "Json00.h"
#include "Xml00.h"
#include "UserDefault00.h"
#include "physics00.h"
#include "Physics01.h"
#include "ScrollView00.h"
#include "UserInput00.h"
#include "RayCast00.h"

// #define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(1280, 720);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil,multisamplesCount
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8, 0};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

//���ø����̼��� ���������� ����Ǹ� ȣ��Ǵ� �Լ�
//�� �Լ����� ���ø����̼��� �����ϱ� ���� ��ɵ��� �����Ѵ�.
bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("testFile", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("testFile");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
	// ȭ�鿡 FPS�� ǥ���Ұ��� �ƴ��� (fps:frame per second)
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
	// ���ø����̼� ����ӵ��� �����ϴ� �Լ�
	// �ִϸ��̼��� ����Ǵ� �ð� ������ �����Ѵٰ� ���� �Ǵµ�
	// ����� 1�ʸ� 60���� ���� ���� ����Ѵ�.
    director->setAnimationInterval(1.0f / 60);

    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
	// �����ػ�
    //auto frameSize = glview->getFrameSize();
    //// if the frame's height is larger than the height of medium size.
    //if (frameSize.height > mediumResolutionSize.height)
    //{        
    //    director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    //}
    //// if the frame's height is larger than the height of small size.
    //else if (frameSize.height > smallResolutionSize.height)
    //{        
    //    director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    //}
    //// if the frame's height is smaller than the height of medium size.
    //else
    //{        
    //    director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    //}

    register_all_packages();

    // create a scene. it's an autorelease object
	// ���� �����ϴ� �ڵ�
   // auto scene = HelloWorld::createScene();
	//auto scene = Image01::createScene();
	//to scene = Image02::createScene();
	//auto scene = Image03::createScene();
	//auto scene = Label01::createScene();

	//auto scene = Menu01::createScene();
	//auto scene = Menu02::createScene();
	//auto scene = Action01::createScene();
	//auto scene = Action02::createScene();
	//auto scene = Action03::createScene();
	//auto scene = ActionScroll::createScene();
	//auto scene = Animation00::createScene();
	//auto scene = Animation01::createScene();
	//auto scene = Animation02::createScene();

	//auto scene = Schedule00::createScene();
	//auto scene = Schedule01::createScene();
	//auto scene = Schedule02::createScene();
	
	//auto scene = LabelAction::createScene();
	//auto scene = touch00::createScene();
	//auto scene = touch01::createScene();
	//auto scene = touch02::createScene();
	//auto scene = Collision00::createScene();
	//auto scene = Homework02::createScene();
	//auto scene = Homework02Answer::createScene();
	//auto scene = SceneChange00::createScene();
	//auto scene = SceneChange01::createScene();
	//auto scene = SceneChange02::createScene();
	//auto scene = scroll00::createScene();
	//auto scene = Scroll01::createScene();
	//auto scene = Particle01::createScene();
	//auto scene = Sound00::createScene();
	//auto scene = Keyboard00::createScene();
	//auto scene = Tile00::createScene();
	//auto scene = Json00::createScene();
	//auto scene = Xml00::createScene();
	//auto scene = physics00::createScene();
	//auto scene = UserDefault00::createScene();
	//auto scene = Physics01::createScene();
	//auto scene = UserInput00::createScene();
	//auto scene = ScrollView00::createScene();
	auto scene = RayCast00::createScene();


	// run
	// �� �κк��� HelloWorldScene�� ȭ�鿡 ��Ÿ����.
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
// ����Ʈ������ �������� ���� Ȩ ��ư�� Ŭ���ؼ� ���� ���,
// ������ ��ȭ�� ���� ��� ȣ��Ǵ� �Լ��� ������ �����ϴ� ���� ó���� �Ѵ�.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

// this function will be called when the app is active again
// ��ȭ�ͼ� �����ߴ� �ǰų� Ȩ��ư ������ �ߴܵ� ���� �ٽ� �����Ҷ� ȣ��Ǵ� �Լ�
// ������ ������ �����Ǿ��ٸ�, ���⼭ ������ �簳�ϴ� ���� ó���� �� �� �ִ�.
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}
