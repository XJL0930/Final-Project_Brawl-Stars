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
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);//添加了键盘按下的事件
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);//添加了键盘松开这个事件
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;//用于在将键盘连续的按下可以移动。
	static Hero* create(const std::string& name);
	static Hero* create(const std::string& name, int offsetX, int offsetY);//重载用于构造初始位置

	virtual void skill();
	Sprite* getHero() { return m_Hero; };
	void runStateEffect(int id);
	//是否能使用大招
	inline bool isCanSkill() { return canUseSkill; };
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
