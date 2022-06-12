#include "endScene.h"

EndScene::EndScene()
{

}

EndScene::~EndScene()
{

}
EndScene* EndScene::create(int ix)
{
    auto scene = new(std::nothrow) EndScene();
    scene->rank = ix;
    if (scene && scene->init())
    {
       
        //scene->retain();
        scene->autorelease();
        return scene;
    }
    else
    {
        delete scene;
        scene = nullptr;
        return nullptr;
    }
}

bool EndScene::init()
{
    if (!Scene::init())
    {
        return false;
    }


    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto sprite = Sprite::create("Scene/end/bg.png");

    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    //¸Ä±ä³ß´ç
    sprite->setScale(0.5f);
    this->addChild(sprite, 0);


    auto audio = SimpleAudioEngine::getInstance();
    audio->playBackgroundMusic("endmusic.mp3", true);

    auto closeItem = MenuItemImage::create(
        "Scene/end/game_0_end.png",
        "Scene/end/game_Over.png",
        CC_CALLBACK_1(EndScene::menuQuitCallback, this));

    auto label = Label::createWithSystemFont(" ", "fonts/arial.ttf", 70.0f);
    label->setPosition(500, 600);
    this->addChild(label);
    label->setScale(0.5);

    char* m = new char[50];
    sprintf(m, "Your Rank : %d !!!!!", rank + 1);
    label->setString(m);

    label = Label::createWithSystemFont(" ", "fonts/arial.ttf", 70.0f);
    label->setPosition(500, 500);
    this->addChild(label);
    label->setScale(0.5);

    m = new char[50];
    sprintf(m, "Your Reward : %d  !!!!!", (10-rank)*100);
    label->setString(m);
    int num = 10 - rank;
    for (int i = 0; i < num; i++)
    {
        Sprite* reward = Sprite::create("Scene/end/reward.png");
        if (i == 0)
            reward->setPosition(500, 400);
        else
        {
            if (i % 2 == 0)
                reward->setPosition(500 - i * 50, 400);
            else
                reward->setPosition(500 + i * 50, 400);
        }
        this->addChild(reward);
    }

    float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
    float y = origin.y + closeItem->getContentSize().height / 2;
    closeItem->setPosition(Vec2(origin.x + visibleSize.width / 2, y));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    return true;
}
void EndScene::menuQuitCallback(Ref* pSender)
{
    Director::getInstance()->end();
}