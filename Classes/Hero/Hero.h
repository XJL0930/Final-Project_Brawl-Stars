#pragma once
#ifndef __ACTOR__H__
#define __ACTOR__H__
#include "cocos2d.h"
USING_NS_CC;
class Hero
{
public:

protected:
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
	/*用于代表动画的类
	my_Animate* left;
	my_Animate* right;
	my_Animate* up;
	my_Animate*down;

	*/
};

#endif // !__ACTOR__H__
