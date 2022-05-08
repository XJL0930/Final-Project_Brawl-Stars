#pragma once
#ifndef _MY_ANIMATION_H_
#define _MY_ANIMATION_H_
#include "cocos2d.h"
using namespace cocos2d;

class MyAnimation {
public:
	
	static Animate* creatHeroWalkAnimation(int hero_type, const char* direction, int num,int loop= -1);


};
#endif