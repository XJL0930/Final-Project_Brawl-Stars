
#include "Choice_ai.h"
#include "BattleScene.h"
USING_NS_CC;

#include "ui/CocosGUI.h"
using namespace ui;

#include"cocostudio/SimpleAudioEngine.h"
using namespace CocosDenshion;

Scene* ChoiceAI::createScene()
{
    return ChoiceAI::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s/n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in ChoiceAIScene.cpp/n");
}


bool ChoiceAI::init()
{

    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto bg = Sprite::create("Scene/Room_AI/brawlball.png");
    bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(bg);

    auto select1 = Label::createWithTTF("select", "fonts/arial.ttf", 34);
    select1->setTag(1);
    select1->setPosition(1.5f * visibleSize.width / 6, visibleSize.height / 7);
    auto hero1 = Sprite::create("Scene/Room_AI/8bit.png");
    hero1->setScale(0.05f);
    hero1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    hero1->setPosition(select1->getPosition().x, select1->getPosition().y + 30);
    this->addChild(select1);
    //touchlisten(select1);
    this->addChild(hero1);

    auto select2 = Label::createWithTTF("select", "fonts/arial.ttf", 34);
    select1->setTag(2);
    select2->setPosition(2.5f * visibleSize.width / 6, visibleSize.height / 7);
    auto hero2 = Sprite::create("Scene/Room_AI/GT_Max.png");
    hero2->setScale(0.05f);
    hero2->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    hero2->setPosition(select2->getPosition().x, select2->getPosition().y + 30);
    this->addChild(select2);
    //touchlisten(select2);
    this->addChild(hero2);

    auto select3 = Label::createWithTTF("select", "fonts/arial.ttf", 34);
    select1->setTag(3);
    select3->setPosition(3.5f * visibleSize.width / 6, visibleSize.height / 7);
    auto hero3 = Sprite::create("Scene/Room_AI/nita.png");
    hero3->setScale(0.05f);
    hero3->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    hero3->setPosition(select3->getPosition().x, select3->getPosition().y + 30);
    this->addChild(select3);
    //touchlisten(select3);
    this->addChild(hero3);

    auto select4 = Label::createWithTTF("select", "fonts/arial.ttf", 34);
    select1->setTag(4);
    select4->setPosition(4.5f * visibleSize.width / 6, visibleSize.height / 7);
    auto hero4 = Sprite::create("Scene/Room_AI/Shelly_2.png");
    hero4->setScale(0.05f);
    hero4->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    hero4->setPosition(select4->getPosition().x, select4->getPosition().y + 30);
    this->addChild(select4);
    //touchlisten(select4);
    this->addChild(hero4);

    auto humanPlayer = Label::createWithTTF("HumanPlayer", "fonts/arial.ttf", 34);
    humanPlayer->setColor(Color3B::RED);
    humanPlayer->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);

    std::vector<Label*> AIvec;
    for (int i = 1; i <= 9; i++) {
        auto AI = Label::createWithTTF("AI", "fonts/arial.ttf", 34);
        AI->setColor(Color3B::RED);
        AI->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
        AIvec.push_back(AI);
    }

    enter->setColor(Color3B::BLACK);
    float x = origin.x + visibleSize.width - enter->getContentSize().width / 2;
    float y = origin.y + enter->getContentSize().height / 2;
    enter->setPosition(Vec2(origin.x + visibleSize.width / 2, y));
    this->addChild(enter);

    for (int i = 1; i <= 10; i++)
    {
        auto player = Sprite::create("Scene/Room_AI/icon_rank_7.png");
        player->setTag(i);
        playervec.push_back(player);
    }
    nowButton = playervec[0];
    for (auto it = playervec.begin(); it != playervec.end(); it++)
    {
        static auto aiit = AIvec.begin();
        static int i = 2;
        if (i < 7)
        {

            (*it)->setPosition((float)(i - 0.5) * visibleSize.width / 7.f, 5 * visibleSize.height / 7 + 30);
            if (i == 2)
            {
                humanPlayer->setPosition(Vec2((*it)->getPosition().x, (*it)->getPosition().y + 50));
                this->addChild(humanPlayer, 10);
            }
            else
            {
                (*aiit)->setPosition(Vec2((*it)->getPosition().x, (*it)->getPosition().y + 50));
                this->addChild((*aiit), 10);
            }
            this->addChild((*it));
        }
        if (i >= 7)
        {
            (*it)->setPosition((float)(i - 5 - 0.5) * visibleSize.width / 7.f, 4 * visibleSize.height / 7);
            (*aiit)->setPosition((*it)->getPosition().x, (*it)->getPosition().y + 50);
            this->addChild((*aiit), 10);
            this->addChild((*it));
        }

        if (i != 2)
            aiit++;
        i++;
    }

    auto listenter = EventListenerTouchOneByOne::create();
    listenter->onTouchBegan = [=](Touch* t, Event* e) {
        return true;
    };
    listenter->onTouchEnded = [=](Touch* t, Event* e) {
        if (select1->getBoundingBox().containsPoint(t->getLocation()))
        {
            heroPath[nowButton->getTag()] = "hero/hero1_begin.png";

            // 将现在的player指针指向1号英雄
            // 将指针指向下一个player的选择
            auto selected = Sprite::create("Scene/Room_AI/icon_rank_6.png");
            selected->setPosition(nowButton->getPosition());
            this->addChild(selected);
            nextone();
        }
        else if (select2->getBoundingBox().containsPoint(t->getLocation()))
        {
            heroPath[nowButton->getTag()] = "hero/hero2_begin.png";
            auto selected = Sprite::create("Scene/Room_AI/icon_rank_6.png");
            selected->setPosition(nowButton->getPosition());
            this->addChild(selected);
            nextone();
        }
        else if (select3->getBoundingBox().containsPoint(t->getLocation()))
        {
            heroPath[nowButton->getTag()] = "hero/hero3_begin.png";
            auto selected = Sprite::create("Scene/Room_AI/icon_rank_6.png");
            selected->setPosition(nowButton->getPosition());
            this->addChild(selected);
            nextone();
        }
        else if (select4->getBoundingBox().containsPoint(t->getLocation()))
        {
            heroPath[nowButton->getTag()] = "hero/hero4_begin.png";
            auto selected = Sprite::create("Scene/Room_AI/icon_rank_6.png");
            selected->setPosition(nowButton->getPosition());
            this->addChild(selected);
            nextone();
        }
        if (enter->getBoundingBox().containsPoint(t->getLocation()))
        {
            if (nowButton->getTag() != 10)
            {
                auto tip = Label::createWithTTF("Please select ten heros", "fonts/arial.ttf", 30);
                tip->setColor(Color3B::RED);
                tip->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 20);
                //tip->setPosition(nowButton->getPosition());
                this->addChild(tip);
                auto out = [=]()
                {
                    this->removeChild(tip, true);
                };
                auto callfunc = CallFunc::create(out);
                tip->runAction(Sequence::create(DelayTime::create(2), callfunc, NULL));

            }
        }
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenter, this);
    return true;
}
void ChoiceAI::nextone()
{
    if (nowButton->getTag() == 1)
    {
        nowButton = playervec[1];
    }
    else if (nowButton->getTag() == 2)
    {
        nowButton = playervec[2];
    }
    else if (nowButton->getTag() == 3)
    {
        nowButton = playervec[3];
    }
    else if (nowButton->getTag() == 4)
    {
        nowButton = playervec[4];
    }
    else if (nowButton->getTag() == 5)
    {
        nowButton = playervec[5];
    }
    else if (nowButton->getTag() == 6)
    {
        nowButton = playervec[6];
    }
    else if (nowButton->getTag() == 7)
    {
        nowButton = playervec[7];
    }
    else if (nowButton->getTag() == 8)
    {
        nowButton = playervec[8];
    }
    else if (nowButton->getTag() == 9)
    {
        nowButton = playervec[9];
    }
    else if (nowButton->getTag() == 10)
    {
        auto listenter = EventListenerTouchOneByOne::create();
        listenter->onTouchBegan = [=](Touch* t, Event* e) {
            return true;
        };
        listenter->onTouchEnded = [=](Touch* t, Event* e) {
            if (enter->getBoundingBox().containsPoint(t->getLocation()))
            {
                menuEnterCallback();
            }
        };
        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenter, this);
    }
    else
    {
    }
}

void ChoiceAI::menuEnterCallback()
{
    //Close the cocos2d-x game scene and quit the application
    auto battleScene = BattleScene::create();
    Director::getInstance()->replaceScene(battleScene->createScene(heroPath));

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}
