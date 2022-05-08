#include "OptionScene.h"

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool OptionGame::init()
{
	if (!Scene::init())
		return false;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	// 创建背景
	auto startBackground = Sprite::create("BrawlStars-1.jpg");
	if (startBackground == nullptr)
	{
		problemLoading("BrawlStars-1.jpg");
	}
	else
	{
		startBackground->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
		this->addChild(startBackground, -1);
	}
	// 创建一个logo精灵在进入游戏的上方
	/*auto logoSpr = Sprite::create("BrawlStars-2.png");
	if (logoSpr == nullptr)
	{
		problemLoading("BrawlStars-2.png");
	}
	else
	{
		logoSpr->setScale(2.0f);
		logoSpr->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 + 60));
		this->addChild(logoSpr, 2);
	}*/
	// 设置进入游戏按钮
	auto startmenu = MenuItemImage::create("begin.png",
		"beginSelected.png",
		CC_CALLBACK_1(OptionGame::menuEnterCallback, this)
	);
	if (startmenu == nullptr ||
		startmenu->getContentSize().width <= 0 ||
		startmenu->getContentSize().height <= 0)
	{
		problemLoading("'begin.png' and 'beginSelected.png'");
	}
	else
	{
		startmenu->setScale(0.6);
		startmenu->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		float x = origin.x + visibleSize.width / 2 - startmenu->getContentSize().width / 2;
		float y = origin.y + startmenu->getContentSize().height / 2 + 40;
		startmenu->setPosition(Vec2(x, y));
	}
	auto menuBegin = Menu::create(startmenu, NULL);
	menuBegin->setPosition(Vec2::ZERO);
	this->addChild(menuBegin, 1);

	auto closetmenu = MenuItemImage::create("quitGame.png",
		"quitselected.png",
		CC_CALLBACK_1(OptionGame::menuCloseCallback, this)
	);
	if (closetmenu == nullptr ||
		closetmenu->getContentSize().width <= 0 ||
		closetmenu->getContentSize().height <= 0)
	{
		problemLoading("'quitGame.png' and 'quitselected.png'");
	}
	else
	{
		closetmenu->setScale(0.6);
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

	auto musicOffBtn = MenuItemImage::create("TurnOnMusic.png", "TurnOnMusic.png");
	musicOffBtn->setScale(1.5f);
	auto musicOnBtn = MenuItemImage::create("TurnOffMusic.png", "TurnOffMusic.png");
	musicOnBtn->setScale(1.5f);
	auto musicMenu = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(OptionGame::musicChangeCallBack, this),
		musicOffBtn, musicOnBtn, NULL
	);
	float x = origin.x + musicOffBtn->getContentSize().width;
	float y = origin.y + visibleSize.height - musicOffBtn->getContentSize().height;
	auto toggleMenuBtn = Menu::create(musicMenu, NULL);
	toggleMenuBtn->setPosition(Vec2(x, y));
	this->addChild(toggleMenuBtn, 1);

	auto soundup = MenuItemImage::create("soundUp.png",
		"soundUp.png",
		CC_CALLBACK_1(OptionGame::soundUpCallBack, this));
	if (soundup == nullptr||
		soundup->getContentSize().width <= 0 ||
		soundup->getContentSize().height <= 0)
	{
		problemLoading("soundUp.png");
	}
	else
	{
		float x1 = x / 2;
		float y1 = y - musicOffBtn->getContentSize().height;
		soundup->setPosition(Vec2(x1,y1));
		soundup->setScale(0.1f);
	}
	auto upmenu = Menu::create(soundup, NULL);
	upmenu->setPosition(Vec2::ZERO);
	this->addChild(upmenu, 2);
	
	auto sounddown = MenuItemImage::create("soundDown.png",
		"soundDown.png",
		CC_CALLBACK_1(OptionGame::soundDownCallBack, this));
	if (sounddown == nullptr ||
		sounddown->getContentSize().width <= 0 ||
		sounddown->getContentSize().height <= 0)
	{
		problemLoading("soundDown.png");
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
void OptionGame::menuEnterCallback(Ref* pSender)
{
	// 当按下“进入游戏“，会进入该函数执行function

	
	//auto optscene = OptionGame::create();
}
void OptionGame::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}
void OptionGame::musicChangeCallBack(Ref* pSender)
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
void OptionGame::soundUpCallBack(Ref* pSender)
{
	float nowvolume=SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(nowvolume + 0.1f);
}
void OptionGame::soundDownCallBack(Ref* pSender)
{
	float nowvolume = SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(nowvolume - 0.1f);
}