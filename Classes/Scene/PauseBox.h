#pragma once
#ifndef __PAUSEBOX__
#define __PAUSEBOX__


#include "cocos2d.h"
USING_NS_CC;

class PauseBox :public Layer
{
protected:
	std::function<void()> _continueCallBack;
	std::function<void()> _endGameCALLbACK;
public:
	PauseBox();
	virtual ~PauseBox();
	CREATE_FUNC(PauseBox);
	virtual bool init();
	virtual void registerCallBack(std::function<void()>continueCallBack, 
		std::function<void()>endGameCALLbACK);
};
#endif // !__PAUSEBOX__
