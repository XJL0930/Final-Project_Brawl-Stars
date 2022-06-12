#include "StartGameScene.h"

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool StartGame::init()
{
	if (!Scene::init())
		return false;
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// 创建背景
	auto startBackground = Sprite::create("Scene/StartGame_pic/BrawlStars-1.jpg");
	if (startBackground == nullptr)
	{
		problemLoading("Scene/StartGame_pic/BrawlStars-1.jpg");
	}
	else
	{
		startBackground->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
		this->addChild(startBackground, -1);
	}
	// 创建一个logo精灵在进入游戏的下方
	auto logoSpr = Sprite::create("Scene/StartGame_pic/BrawlStars-2.png");
	if (logoSpr == nullptr)
	{
		problemLoading("Scene/StartGame_pic/BrawlStars-2.png");
	}
	else
	{
		logoSpr->setScale(2.0f);
		logoSpr->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 + 60));
		this->addChild(logoSpr, 2);
	}
	// 设置进入游戏按钮
	auto startmenu = MenuItemImage::create("Scene/StartGame_pic/begin.png",
		"Scene/StartGame_pic/beginSelected.png",
		CC_CALLBACK_1(StartGame::menuEnterCallback, this)
	);
	if (startmenu == nullptr ||
		startmenu->getContentSize().width <= 0 ||
		startmenu->getContentSize().height <= 0)
	{
		problemLoading("'Scene/StartGame_pic/begin.png' and 'Scene/StartGame_pic/beginSelected.png'");
	}
	else
	{
		startmenu->setScale(0.6f);
		startmenu->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		float x = origin.x + visibleSize.width / 2 - startmenu->getContentSize().width / 2;
		float y = origin.y + startmenu->getContentSize().height / 2 + 40;
		startmenu->setPosition(Vec2(x, y));
	}
	auto menuBegin = Menu::create(startmenu, NULL);
	menuBegin->setPosition(Vec2::ZERO);
	this->addChild(menuBegin, 1);

	auto closetmenu = MenuItemImage::create("Scene/StartGame_pic/quitGame.png",
		"Scene/StartGame_pic/quitselected.png",
		CC_CALLBACK_1(StartGame::menuCloseCallback, this)
	);
	if (closetmenu == nullptr ||
		closetmenu->getContentSize().width <= 0 ||
		closetmenu->getContentSize().height <= 0)
	{
		problemLoading("'Scene/StartGame_pic/quitGame.png' and 'Scene/StartGame_pic/quitselected.png'");
	}
	else
	{
		closetmenu->setScale(0.6f);
		closetmenu->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		float x = origin.x + visibleSize.width / 2 + startmenu->getContentSize().width / 2;;
		float y = origin.y + startmenu->getContentSize().height / 2 + 40;
		closetmenu->setPosition(Vec2(x, y));
	}
	auto menuClose = Menu::create(closetmenu, NULL);
	menuClose->setPosition(Vec2::ZERO);
	this->addChild(menuClose, 1);
	// 播放背景音乐
	auto audio = SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("beginMusic.mp3", true);
	auto musicOffBtn = MenuItemImage::create("Scene/StartGame_pic/TurnOnMusic.png", "Scene/StartGame_pic/TurnOnMusic.png");
	musicOffBtn->setScale(1.5f);
	auto musicOnBtn = MenuItemImage::create("Scene/StartGame_pic/TurnOffMusic.png", "Scene/StartGame_pic/TurnOffMusic.png");
	musicOnBtn->setScale(1.5f);
	auto musicMenu = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(StartGame::musicChangeCallBack, this),
		musicOffBtn, musicOnBtn, NULL
	);
	float x = origin.x + musicOffBtn->getContentSize().width;
	float y = origin.y + visibleSize.height - musicOffBtn->getContentSize().height;
	auto toggleMenuBtn = Menu::create(musicMenu, NULL);
	toggleMenuBtn->setPosition(Vec2(x, y));
	this->addChild(toggleMenuBtn, 1);

	auto soundup = MenuItemImage::create("Scene/StartGame_pic/soundUp.png",
		"Scene/StartGame_pic/soundUp.png",
		CC_CALLBACK_1(StartGame::soundUpCallBack, this));
	if (soundup == nullptr ||
		soundup->getContentSize().width <= 0 ||
		soundup->getContentSize().height <= 0)
	{
		problemLoading("Scene/StartGame_pic/soundUp.png");
	}
	else
	{
		float x1 = x / 2;
		float y1 = y - musicOffBtn->getContentSize().height;
		soundup->setPosition(Vec2(x1, y1));
		soundup->setScale(0.1f);
	}
	auto upmenu = Menu::create(soundup, NULL);
	upmenu->setPosition(Vec2::ZERO);
	this->addChild(upmenu, 2);

	auto sounddown = MenuItemImage::create("Scene/StartGame_pic/soundDown.png",
		"Scene/StartGame_pic/soundDown.png",
		CC_CALLBACK_1(StartGame::soundDownCallBack, this));
	if (sounddown == nullptr ||
		sounddown->getContentSize().width <= 0 ||
		sounddown->getContentSize().height <= 0)
	{
		problemLoading("Scene/StartGame_pic/soundDown.png");
	}
	else
	{
		float x2 = 3 * x / 2;
		float y2 = y - musicOffBtn->getContentSize().height;
		sounddown->setPosition(Vec2(x2, y2));
		sounddown->setScale(0.1f);
	}
	auto downmenu = Menu::create(sounddown, NULL);
	downmenu->setPosition(Vec2::ZERO);
	this->addChild(downmenu, 2);


	return true;
}
void StartGame::menuEnterCallback(Ref* pSender)
{
	// 当按下“进入游戏“，会进入下一个场景，记得关闭当前场景的音乐
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	auto choiceAi = ChoiceAI::create();
	Director::getInstance()->replaceScene(choiceAi);
}
void StartGame::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}
void StartGame::musicChangeCallBack(Ref* pSender)
{
	static bool flag = true;
	if (flag)
	{
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	}
	else
	{
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	}
	flag = !flag;
}
void StartGame::soundUpCallBack(Ref* pSender)
{
	float nowvolume = SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(nowvolume + 0.1f);
}
void StartGame::soundDownCallBack(Ref* pSender)
{
	float nowvolume = SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(nowvolume - 0.1f);
}
