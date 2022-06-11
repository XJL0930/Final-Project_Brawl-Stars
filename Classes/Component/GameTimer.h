#pragma once
#ifndef _GAME_TIMER_H_
#define _GAME_TIMER_H_

#include "cocos2d.h"

USING_NS_CC;

class GameTimer : public cocos2d::Node
{
public:
	GameTimer();

	virtual ~GameTimer();

	static GameTimer* createTimer(float time);

	void update(float delta);

	bool init(float time);

private:
	Label* label;
	float					pTime;
};

#endif
