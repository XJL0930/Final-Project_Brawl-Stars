#pragma once
#ifndef __STARTGAME_SCENE_H__
#define __STARTGAME_SCENE_H__

#include "cocos2d.h"
#include "BattleScene.h"
#include "Choice_ai.h"
#include "cocostudio\SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;
class StartGame : public Scene
{
public:
	CREATE_FUNC(StartGame);
	virtual bool init();
	/*void menuCloseCallback(Ref* pSender);*/
	void menuEnterCallback(Ref* pSender);
	void menuCloseCallback(Ref* pSender);
	void musicChangeCallBack(Ref* pSender);
	void soundUpCallBack(Ref* pSender);
	void soundDownCallBack(Ref* pSender);
};

#endif // __STARTGAME_SCENE_H__
