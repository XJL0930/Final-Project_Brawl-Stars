#pragma once
#ifndef __HERO_MOVE_H__
#define __HERO_MOVE_H__

#include "cocos2d.h"
USING_NS_CC;


class HeroMove :public Sprite
{
public:
    static Sprite* createHero();
    bool initWithHero();
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);//添加了键盘按下的事件
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);//添加了键盘松开这个事件
    virtual void update(float delta);
    Sprite* Hero;//英雄
    std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
private:
    float StartPosX = 100.0f;
    float StartPosY = 300.0f;
    float MAX_distance = 58;
    
};

#endif // __HERO_MOVE_H__