/*
* ��optionscene���ڵ��������Ϸ������ѡ����棬�����н��뷿�䡢���á�ģʽ��ѡ�����ȵ���Ŀ�к�����ʵ��
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