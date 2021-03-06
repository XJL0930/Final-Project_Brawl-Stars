#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_
#define StartX 200
#define StartY 300
#include "cocos2d.h"
#include "Role.h"
#include"Hero\Hero.h"

// Actor类里有
// 变量：pos，宝石个数，血条
// 方法：是否被攻击，是否攻击，血条变化
class Player : public Role {
public:

	//virtual bool init(const std::string& name);
	//void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);//添加了键盘按下的事件
	//void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);//添加了键盘松开这个事件
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;//用于在将键盘连续的按下可以移动。
	
	//void onMouseLeftPressed(cocos2d::EventMouse::MouseButton keyCode, cocos2d::Event* event);
	//void onMouseLeftReleased(cocos2d::EventMouse::MouseButton keyCode, cocos2d::Event* event);
	//std::map<EventMouse::MouseEventType, bool> mouses;//用于在将鼠标左键按下时能够持续发射精灵
	bool isMousePressed;
	void onMouseMove(Event* event);
	bool onMouseDown(Event* event);
	//static Player* create(const std::string& name);
	static Player* create(const std::string& name, const Point pos);//重载用于构造初始位置
	
	//Point getPlayerPosition() { return Vec2(offsetX, offsetY); }
	//virtual void stand();
	virtual void move();//用于移动的函数
	bool bindPhysicsBody();
	bool bindMonsterBulletPhysicsBody(Sprite* bullet);
	
	//virtual void attack();


	//void exit();//用于注销所有注册过的事件；
	/*下面三个函数用于控制当人物静止时的操作*/
	void update(float delta);
	void update_mouse(float delta);//更新函数，用于检测当前mouse的位置。
	void update_move(float delta);
	void update_animate(float delta);//人物静止时，人物的朝向追随鼠标
	//void update_route(float delta);//更新武器的路线
	void update_weapon(float delta);
	void update_setViewPointByPlayer(float dt);//更新视角
	void update_weaponOut(float delta);
	float getFacingDistance(float point_x,float point_y);//得到当mouse的x,y与人物的距离
	Point getOffset() { return Point(offsetX, offsetY); }
	/*virtual void attack();//用于攻击的函数
	virtual void skill();
	//virtual void injured();//用于展示受伤的函数
	virtual void die();//用于展示死亡的函数

	void runStateEffect(int id);*/
private:
	float m_state_lastTime;
	Animate* currentAnimate = stand_left;
	//double maxLength=300;

};
#endif// !__HERO__H__
