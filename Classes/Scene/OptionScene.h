/*
* 此optionscene是在点击进入游戏后进入的选项界面，里面有进入房间、设置、模式等选项，具体等到项目中后期再实现
*/
#pragma once
#ifndef __OPTIONSCENE__H__
#define __OPTIONSCENE__H__

#include "cocos2d.h"

#include "cocostudio\SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;
class OptionGame : public Scene
{
public:
	CREATE_FUNC(OptionGame);
	virtual bool init();
	void menuEnterCallback(Ref* pSender);
	void menuCloseCallback(Ref* pSender);
	void musicChangeCallBack(Ref* pSender);
	void soundUpCallBack(Ref* pSender);
	void soundDownCallBack(Ref* pSender);

};
#endif //__OPTIONSCENE__H__