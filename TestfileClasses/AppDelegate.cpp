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

//어플리케이션이 정상적으로 실행되면 호출되는 함수
//이 함수에서 어플리케이션을 시작하기 위한 기능들을 진행한다.
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
	// 화면에 FPS를 표시할건지 아닌지 (fps:frame per second)
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
	// 어플리케이션 실행속도를 결정하는 함수
	// 애니메이션이 수행되는 시간 간격을 설정한다고 보면 되는데
	// 현재는 1초를 60으로 나눈 값을 사용한다.
    director->setAnimationInterval(1.0f / 60);

    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
	// 다중해상도
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
	// 씬을 생성하는 코드
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
	// 이 부분부터 HelloWorldScene이 화면에 나타난다.
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
// 스마트폰에서 실행중인 앱을 홈 버튼을 클릭해서 닫을 경우,
// 실행중 전화가 오는 경우 호출되는 함수로 게임을 중지하는 등의 처리를 한다.
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
// 전화와서 실행중단 되거나 홈버튼 눌려서 중단된 앱을 다시 실행할때 호출되는 함수
// 기존에 게임이 중지되었다면, 여기서 게임을 재개하는 등의 처리를 할 수 있다.
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}
