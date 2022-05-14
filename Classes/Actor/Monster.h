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
	Hero();//用构造函数实现键盘鼠标的监听
	static Hero* create(const std::string& name);
	static Hero* create(const std::string& name, int offsetX, int offsetY);//重载用于构造初始位置

	void auto_move();

	//运行大招的状态
	void runStateEffect(int id);
	//是否能使用大招
	inline bool isCanSkill() { return canUseSkill; }
	//恢复状态
	void recover();

private:
	virtual void update(float dt);
	void update_skill(float dt);//用于更新大招
private:
	bool canUseSkill;

	float m_state_lastTime;


	float skillCD;

	Sprite* m_Hero;

};
#endif// !__HERO__H__
