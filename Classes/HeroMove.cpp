#include "HeroMove.h"
#include "Actor\MyAnimate.h"

#define MaxFileName 100
#define PerLength 30
USING_NS_CC;



static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
Sprite*HeroMove::createHero()
{
    Sprite* creat = Sprite::create("Scene/hero/Hero1.png");
   
    if (creat == nullptr)
    {
        problemLoading("'Scene/hero/Hero1.png'");
    }
   
   return creat;
}
bool HeroMove::initWithHero()
{

    //每0.1妙调用一下，
    this->schedule(CC_SCHEDULE_SELECTOR(HeroMove::update),0.1f);


    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();//获得可视区域出发点的坐标

   

    Hero = createHero();
    Hero->addChild(Hero);
    Hero->setPosition(100, 300);
    
    auto keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        log("key pressed");
        keys[keyCode] = true;
    };

    
   keyListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        log("key pressed");
        keys[keyCode] = false;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
    
   
   

    return true;
}

/*void HeroMove::update(float delta)
{
    Animate* walk_back = MyAnimation::creatHeroWalkAnimation(1, "back", 4);
    Animate* walk_left = MyAnimation::creatHeroWalkAnimation(1, "left", 4);
    Animate* walk_right = MyAnimation::creatHeroWalkAnimation(1, "right", 4);

    Animate* walk_forward = MyAnimation::creatHeroWalkAnimation(1, "forward", 4);

    auto left = cocos2d::EventKeyboard::KeyCode::KEY_A;
    auto right = cocos2d::EventKeyboard::KeyCode::KEY_D;
    auto back = cocos2d::EventKeyboard::KeyCode::KEY_S;
    auto forward = cocos2d::EventKeyboard::KeyCode::KEY_W;
   
 
    if (keys[left])
    {
        auto moveBy = MoveBy::create(0.1f, Vec2(-10, 0));
        Hero->runAction(Spawn::createWithTwoActions(moveBy, walk_left));
       
    }
    else if (keys[right])
    {
        MoveBy* moveBy = MoveBy::create(0.1f, Vec2(10, 0));
        Hero->runAction(Spawn::createWithTwoActions(moveBy, walk_right));
      
    }
    else if (keys[back])
    {
        auto moveBy = MoveBy::create(0.1f, Vec2(0, -10));
        Hero->runAction(Spawn::createWithTwoActions(moveBy, walk_back));
      
    }
    else if (keys[forward])
    {
        auto moveBy = MoveBy::create(0.1f, Vec2(0, 10));
        Hero->runAction(Spawn::createWithTwoActions(moveBy, walk_forward));
    }
}*/
