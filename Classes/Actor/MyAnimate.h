#pragma once
#ifndef _MY_ANIMATE_H_
#define _MY_ANIMATE_H_
#include "cocos2d.h"
using namespace cocos2d;

class MyAnimate {
public:
	
	static Animate* creatHeroAnimate(int hero_type, const char* direction, int num,int loop= -1);
	static Animate* creatWeaponAnimate(const char* plistName, const char* pngName, int loop);
};
#endif