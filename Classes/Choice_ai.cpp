/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "Choice_ai.h"
USING_NS_CC;

#include "ui/CocosGUI.h"
using namespace ui;

#include"cocostudio/SimpleAudioEngine.h"
using namespace CocosDenshion;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init()
{

    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    auto closeItem = MenuItemImage::create(
                                           "start_0_begin.png",
                                           "start_0.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'start_0_begin.png' and 'start_0.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(origin.x + visibleSize.width / 2,y));
    }

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);


    auto label = Label::createWithTTF("ROOM", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));
        this->addChild(label,1);
    }

    auto sprite = Sprite::create("bg.png");
    if (sprite == nullptr)
    {
        problemLoading("'bg.png'");
    }
    else
    {
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        //改变尺寸
        sprite->setScale(0.5f);
        this->addChild(sprite, 0);
    }

    //添加人物
    auto player = Sprite::create("player.png");
    player->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(player);

    //添加音乐
    auto button_music_start = Button::create("music_1.png");
    button_music_start->setPosition(Vec2(visibleSize.width / 10 + origin.x, visibleSize.height));
    button_music_start->addClickEventListener([=](Ref* sender) {
        SimpleAudioEngine::getInstance()->playBackgroundMusic("beginMusic.mp3", true);
        });
    this->addChild(button_music_start);

    //添加按钮
    auto button_0 = Button::create("have.png", "end.png", "delete.png");
    this->addChild(button_0);
    button_0->setPosition(Vec2(visibleSize.width / 8 + origin.x, visibleSize.height / 4 + origin.y));
    button_0->addTouchEventListener([=](Ref* ref, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                auto ai_0 = Sprite::create("ai.png");
                ai_0->setPosition(Vec2(visibleSize.width / 8 + origin.x, visibleSize.height / 2 + origin.y));
                this->addChild(ai_0);
            }
        });

    auto button_1 = Button::create("have.png", "end.png", "delete.png");
    this->addChild(button_1);
    button_1->setPosition(Vec2(visibleSize.width / 3 + origin.x, visibleSize.height / 4 + origin.y));
    button_1->addTouchEventListener([=](Ref* ref, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                auto ai_1 = Sprite::create("ai.png");
                ai_1->setPosition(Vec2(visibleSize.width / 3 + origin.x, visibleSize.height / 2 + origin.y));
                this->addChild(ai_1, 0);
            }
        });

    auto button_2 = Button::create("have.png", "end.png", "delete.png");
    this->addChild(button_2);
    button_2->setPosition(Vec2(2*visibleSize.width / 3 + origin.x, visibleSize.height / 4 + origin.y));
    button_2->addTouchEventListener([=](Ref* ref, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                auto ai_2 = Sprite::create("ai.png");
                ai_2->setPosition(Vec2(2 * visibleSize.width / 3 + origin.x, visibleSize.height / 2 + origin.y));
                this->addChild(ai_2, 0);
            }
        });

    auto button_3 = Button::create("have.png", "end.png", "delete.png");
    this->addChild(button_3);
    button_3->setPosition(Vec2(7*visibleSize.width / 8 + origin.x, visibleSize.height / 4 + origin.y));
    button_3->addTouchEventListener([=](Ref* ref, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                auto ai_3 = Sprite::create("ai.png");
                ai_3->setPosition(Vec2(7 * visibleSize.width / 8 + origin.x, visibleSize.height / 2 + origin.y));
                this->addChild(ai_3, 0);
            }
        });
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
