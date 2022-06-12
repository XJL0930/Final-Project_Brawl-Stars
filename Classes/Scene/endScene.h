#pragma once
#ifndef __ENDSCENE_H__
#define __ENDSCENE_H__
#include "cocos2d.h"

#include "cocostudio\SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;
class EndScene :public Scene
{
public:
	EndScene();
	virtual ~EndScene();
	//CREATE_FUNC(EndScene);
	static EndScene* create(int ix);
	virtual bool init();
	void menuQuitCallback(Ref* pSender);
private:
	int rank;
	//Sprite* Reward;
};
#endif // __CHOICE_AI_H__
