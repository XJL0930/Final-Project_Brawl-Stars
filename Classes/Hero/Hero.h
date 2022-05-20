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
	CC_SYNTHESIZE(INT32, speed, _speed);
	CC_SYNTHESIZE(INT32,attackDistance, _attackDistance);
	CC_SYNTHESIZE(INT32, hp, _hp);
	CC_SYNTHESIZE(INT32, atk, _atk);
	CC_SYNTHESIZE(INT32, defence, _defence);
	CC_SYNTHESIZE(INT32,atkHateValue, _atkHateValue);
	CC_SYNTHESIZE(std::string,bulletImg, _bulletImg);
	CC_SYNTHESIZE(INT32, bulletSpeed, _bulletSpeed);
	CC_SYNTHESIZE(INT32, id, _id);
	CC_SYNTHESIZE(float,skillCD,_skillCD); 
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
};
#endif // 
