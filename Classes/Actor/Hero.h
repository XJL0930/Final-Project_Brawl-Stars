#pragma once
#ifndef __HERO__H__
#define __HERO__H__

#include "cocos2d.h"
#include "Actor.h"
// Actor类里有
// 变量：pos，宝石个数，血条
// 方法：是否被攻击，是否攻击，血条变化
class Hero :public Actor
{
	// 英雄有能量格，三格，普通攻击减少一格，大招减少两格
	// 不按技能时能量格慢慢恢复，格子满了就不再恢复了
	CC_SYNTHESIZE(INT32, EnergyNum, _EnergyNum);
	CC_SYNTHESIZE(bool, isEnergyFull, _isEnergyFull);

public:
	static Hero* create();
	virtual void WeaponCharge();
	virtual void move();
	virtual void attack();
};
#endif // !__HERO__H__
