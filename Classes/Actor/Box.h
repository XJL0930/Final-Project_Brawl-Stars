#pragma once
#ifndef __BOX__H__
#define __BOX__H__
#include "cocos2d.h"
#include "Role.h"
USING_NS_CC;
class Box :public Role
{
public :
	void playAnimation();
	static Box* creat();
	virtual bool init();
};
#endif // !__BOX__H__
