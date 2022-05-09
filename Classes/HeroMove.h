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
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);//����˼��̰��µ��¼�
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);//����˼����ɿ�����¼�
    virtual void update(float delta);
    Sprite* Hero;//Ӣ��
    std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
private:
    float StartPosX = 100.0f;
    float StartPosY = 300.0f;
    float MAX_distance = 58;
    
};

#endif // __HERO_MOVE_H__