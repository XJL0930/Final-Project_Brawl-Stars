#pragma once
#ifndef __HERO__H__
#define __HERO__H__

#include "cocos2d.h"
#include "Role.h"
// Actor类里有
// 变量：pos，宝石个数，血条
// 方法：是否被攻击，是否攻击，血条变化
class Hero : public Role {
public:
	void update(float dt);
	virtual bool init(const std::string& name);
	Hero();//用构造函数实现键盘鼠标的监听
	static Hero* create(const std::string& name);
	static Hero* create(const std::string& name, int offsetX, int offsetY);//重载用于构造初始位置

	virtual void move();//用于自动移动的函数
	virtual void attack();//用于自动攻击的函数
	virtual void skill();
	virtual void die();//用于展示AI死亡的函数

	//运行大招的状态
	void runStateEffect(int id);

private:

};
#endif// !__HERO__H__
