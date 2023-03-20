#include "Sound00.h"
//����� ������ ����ϱ� ���� ���̺귯���� ��Ŭ����Ѵ�.
#include "AudioEngine.h"
USING_NS_CC;

//������ ����� ���� ���ӽ����̽��� �������ش�.
using namespace experimental;

const std::string BGM_1_PATH = "Sounds/background.mp3";
const std::string BGM_2_PATH = "Sounds/backgrdoun-music-acc.mp3";

Scene* Sound00::createScene()
{
	return Sound00::create();
}

bool Sound00::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::BLACK);
	this->addChild(wlayer);

	_soundVolume = 1.0f;
	audioId1 = -1;
	audioId2 = -1;

	MenuItemFont::setFontSize(25);

	auto pMenuItem1A = MenuItemFont::create("preload All", CC_CALLBACK_1(Sound00::preloadAll, this));
	auto pMenuItem1B = MenuItemFont::create("uncache All", CC_CALLBACK_1(Sound00::uncacheAll, this));
	auto pMenuItem1C = MenuItemFont::create("Volume Up", CC_CALLBACK_1(Sound00::upVolume, this));
	auto pMenuItem1D = MenuItemFont::create("Volume Down", CC_CALLBACK_1(Sound00::downVolume, this));

	auto pMenu1 = Menu::create(pMenuItem1A, pMenuItem1B, pMenuItem1C, pMenuItem1D, nullptr);
	pMenu1->alignItemsHorizontallyWithPadding(20);
	pMenu1->setPosition(640, 550);
	this->addChild(pMenu1);

	//-----------------------------------------------------------------------
	MenuItemFont::setFontSize(35);

	auto pMenuItem2A = MenuItemFont::create("PlaySound1", CC_CALLBACK_1(Sound00::playSound1, this));
	auto pMenuItem2B = MenuItemFont::create("PauseSound1", CC_CALLBACK_1(Sound00::pauseSound1, this));
	auto pMenuItem2C = MenuItemFont::create("ResumeSound1", CC_CALLBACK_1(Sound00::resumeSound1, this));
	auto pMenuItem2D = MenuItemFont::create("StopSound1", CC_CALLBACK_1(Sound00::stopSound1, this));
	
	auto pMenu2 = Menu::create(pMenuItem2A, pMenuItem2B, pMenuItem2C, pMenuItem2D, nullptr);
	pMenu2->alignItemsVerticallyWithPadding(30);
	pMenu2->setPosition(Vec2(350, 300));
	this->addChild(pMenu2);

	//-----------------------------------------------------------------------
	auto pMenuItem3A = MenuItemFont::create("PlaySound2", CC_CALLBACK_1(Sound00::playSound2, this));
	auto pMenuItem3B = MenuItemFont::create("PauseSound2", CC_CALLBACK_1(Sound00::pauseSound2, this));
	auto pMenuItem3C = MenuItemFont::create("ResumeSound2", CC_CALLBACK_1(Sound00::resumeSound2, this));
	auto pMenuItem3D = MenuItemFont::create("StopSound2", CC_CALLBACK_1(Sound00::stopSound2, this));

	auto pMenu3 = Menu::create(pMenuItem3A, pMenuItem3B, pMenuItem3C, pMenuItem3D, nullptr);
	pMenu3->alignItemsVerticallyWithPadding(30);
	pMenu3->setPosition(Vec2(900, 300));
	this->addChild(pMenu3);

	return true;
}

void Sound00::preloadAll(Ref * pSender)
{
	AudioEngine::preload(BGM_1_PATH);
	AudioEngine::preload(BGM_2_PATH);
}

void Sound00::uncacheAll(Ref * pSender)
{
	AudioEngine::stop(audioId1);
	AudioEngine::stop(audioId2);

	AudioEngine::uncache(BGM_1_PATH);
	AudioEngine::uncache(BGM_2_PATH);
}

void Sound00::upVolume(Ref * pSender)
{
	//������ 0���� 1������ ������ ���Ѵ�.
	if (_soundVolume < 1.0f)
		_soundVolume += 0.1f; //10%�� ����

	AudioEngine::setVolume(audioId1, _soundVolume);
	AudioEngine::setVolume(audioId2, _soundVolume);

}

void Sound00::downVolume(Ref * pSender)
{
	if (_soundVolume > 0.0f)
	{
		_soundVolume -= 0.1f;
		AudioEngine::setVolume(audioId1, _soundVolume);
		AudioEngine::setVolume(audioId2, _soundVolume);
	}
}

void Sound00::playSound1(Ref * pSender)
{
	// ������ ���� ���¸� üũ�� �� �ִ�.
	if (AudioEngine::getState(audioId1) != AudioEngine::AudioState::PLAYING)
	{
		audioId1 = AudioEngine::play2d(BGM_1_PATH, true, _soundVolume);
	}
}

void Sound00::playSound2(Ref * pSender)
{
	if (AudioEngine::getState(audioId2) != AudioEngine::AudioState::PLAYING)
	{
		audioId1 = AudioEngine::play2d(BGM_2_PATH, false, _soundVolume);

		if (audioId2 != AudioEngine::INVALID_AUDIO_ID)
		{
			//ID2�� ���� ������ ����� ������ bgmPlayFinishedCallback�޼��带 ȣ���Ѵ�.
			AudioEngine::setFinishCallback(audioId2, CC_CALLBACK_2(Sound00::bgmPlayFinishedCallback,this));
		}
	}
}

void Sound00::pauseSound1(Ref * pSender)
{
	if (AudioEngine::getState(audioId1) == AudioEngine::AudioState::PLAYING)
	{
		AudioEngine::pause(audioId1);
	}
}

void Sound00::pauseSound2(Ref * pSender)
{
	if (AudioEngine::getState(audioId2) == AudioEngine::AudioState::PLAYING)
	{
		AudioEngine::pause(audioId2);
	}
}


void Sound00::resumeSound1(Ref * pSender)
{
	if (AudioEngine::getState(audioId1) == AudioEngine::AudioState::PAUSED)
	{
		AudioEngine::resume(audioId1);
	}
}

void Sound00::resumeSound2(Ref * pSender)
{
	if (AudioEngine::getState(audioId2) == AudioEngine::AudioState::PAUSED)
	{
		AudioEngine::resume(audioId2);
	}
}

void Sound00::stopSound1(Ref * pSender)
{
	if (AudioEngine::getState(audioId1) == AudioEngine::AudioState::PLAYING)
	{
		AudioEngine::stop(audioId1);
	}
}

void Sound00::stopSound2(Ref * pSender)
{
	if (AudioEngine::getState(audioId1) == AudioEngine::AudioState::PLAYING)
	{
		AudioEngine::stop(audioId1);
	}
}

void Sound00::bgmPlayFinishedCallback(int audioId, const std::string & fliepath)
{
	//log("[%s]", filepath.c_str() );
}

Sound00::~Sound00()
{
	//���� ����� ���̻� ������� ������ �� �޼��带 ȣ���Ͽ� ���ҽ��� �����Ѵ�.
	AudioEngine::end();
}
