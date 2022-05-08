#pragma once
#ifndef __ACTOR__H__
#define __ACTOR__H__
#include "cocos2d.h"
USING_NS_CC;
class Actor :public cocos2d::Sprite
{
	CC_SYNTHESIZE(INT32, gemeStones, _gemeStones);
	CC_SYNTHESIZE(INT32, pos, _pos);
	CC_SYNTHESIZE(INT32, bloodVol, _bloodVol);

public:
	static Actor* create();
	virtual bool init();
	virtual bool isAttacked();
	virtual bool isAttack();
	virtual void changeBlood();
	virtual void changeGeme();
};

#endif // !__ACTOR__H__
