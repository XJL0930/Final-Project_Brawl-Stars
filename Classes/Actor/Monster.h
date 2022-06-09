#pragma once
#ifndef __MONSTER__H__
#define __MONSTER__H__

#include "cocos2d.h"
#include "Role.h"
// Actor类里有
// 变量：pos，宝石个数，血条
// 方法：是否被攻击，是否攻击，血条变化
class Monster : public Role {
public:
	//void update(float dt);
	//virtual bool init(const std::string& name);
	//Hero();//用构造函数实现键盘鼠标的监听
	//static Hero* create(const std::string& name);
	static Monster* create(const std::string& name, int maxMonster,Point startPos,int ix);//重载用于构造初始位置

	virtual void move();//用于自动移动的函数
	virtual void update_attack(float delata);//用于自动攻击的函数

	//virtual void skill();
	//virtual void die();//用于展示AI死亡的函数
	void updateMove(float delta);
	//void update_animate(float dealt);
	enum Direction{up=0,down,left,right};
	bool bindPhysicsBody();
	bool bindMonsterBulletPhysicsBody(Sprite* bullet);
	double setSrand(int num) { return num * 4.23 / 1.265 + 5; }
private:
	int dir;
	Animate* currentAnimate = stand_left;
	
	bool is_attack = false;
};
#endif// !__MONSTER__H__