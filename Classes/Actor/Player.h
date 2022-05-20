#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "cocos2d.h"
#include "Role.h"
#include"Hero\Hero.h"

// Actor类里有
// 变量：pos，宝石个数，血条
// 方法：是否被攻击，是否攻击，血条变化
class Player : public Role {
public:
	void update(float dt);
	//virtual bool init(const std::string& name);
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);//添加了键盘按下的事件
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);//添加了键盘松开这个事件
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;//用于在将键盘连续的按下可以移动。
	void onMouseMove(Event* event);

	static Player* create(const std::string& name);
	static Player* create(const std::string& name, int offsetX, int offsetY);//重载用于构造初始位置

	void bind_Camera();//用于绑定摄像机，将镜头随人物移动
	void update_move(float dt);
	
	/*virtual void stand();*/
	virtual void move();//用于移动的函数



	/*下面三个函数用于控制当人物静止时的操作*/
	void Player::update_mouse(float delta);//更新函数，用于检测当前mouse的位置。
	float getFacingDistance(float point_x,float point_y);//得到当mouse的x,y与人物的距离
	void setDirestionPicture();//人物静止时，人物的朝向追随鼠标。
	/*virtual void attack();//用于攻击的函数
	virtual void skill();
	//virtual void injured();//用于展示受伤的函数
	virtual void die();//用于展示死亡的函数

	void runStateEffect(int id);*/
private:
	float m_state_lastTime;
	float offsetX = 200;
	float offsetY = 300;
	bool is_facingStatue = false;

};
#endif// !__HERO__H__
