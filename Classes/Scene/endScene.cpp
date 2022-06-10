#include "endScene.h"

EndScene::EndScene()
{

}

EndScene::~EndScene()
{

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
        "Scene/Room_AI/start_0_begin.png",
        "Scene/Room_AI/start_0.png",
        CC_CALLBACK_1(EndScene::menuQuitCallback, this));


    float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
    float y = origin.y + closeItem->getContentSize().height / 2;
    closeItem->setPosition(Vec2(origin.x + visibleSize.width / 2, y));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    return false;
}
void EndScene::menuQuitCallback(Ref* pSender)
{
    Director::getInstance()->end();
}