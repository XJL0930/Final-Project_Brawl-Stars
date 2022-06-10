#pragma once
#include "cocos2d.h"

#include "cocostudio\SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;
class EndScene :public Scene
{
	EndScene();
	virtual ~EndScene();
	CREATE_FUNC(EndScene);
	virtual bool init();
	void menuQuitCallback(Ref* pSender);
};