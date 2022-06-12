#pragma once
#ifndef __HERO_H_
#define __HERO_H_
#include "cocos2d.h"
#include "Actor\MyAnimate.h"
USING_NS_CC;
class Hero
{
public:

protected:
	CC_SYNTHESIZE(std::string, heroName, _heroName);
	CC_SYNTHESIZE(float, speed, _speed);
	CC_SYNTHESIZE(INT32, hp, _hp);
	CC_SYNTHESIZE(INT32, atk, _atk);

	/*用于代表动画的类*/
	Animate* left_animate;
	Animate* right_animate;
	Animate* up_animate;
	Animate* down_animate;
	Animate* stand_left;
	Animate* stand_right;
	Animate* stand_up;
	Animate* stand_down;
	Animate* getLeftAnimate()const { return left_animate; };
	Animate* getRightAnimate()const { return right_animate; };
	Animate* getUpAnimate()const { return up_animate; };
	Animate* getDownAnimate()const { return down_animate; };
	Animate* getStandUpAnimate()const { return stand_up; };
	Animate* getStandRightAnimate()const { return stand_right; };
	Animate* getStandLeftAnimate()const { return stand_left; };
	Animate* getStandDownAnimate()const { return stand_down; };
};
#endif // 
