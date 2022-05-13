#pragma once
#ifndef _ROLE_H_
#define _ROLE_H_
#include "cocos2d.h"
#include "HeroMessage.h"
#include <string>
USING_NS_CC;
using namespace cocos2d;
class Role : public Sprite {
	
public:
	Role();
	
	virtual bool init(const std::string& name);
	void initWithMessage(const HeroMessage& msg);
protected:
	/*update相关的*/
	virtual void update(float delta);//默认的更新函数，可以不用，也可以具体按照需求搞
	virtual void update_akt();//更新攻击力
	virtual void update_pos();//更新位置
	virtual void update_hp();//更新血量

public:
	virtual void stand();
	virtual void move();
	virtual void attack();
	virtual void skill();
	virtual void injured();
	virtual void die();



public:
	/*外部调用接口*/
	virtual inline void setDesPoint(const Point& p) { m_desPoint = p; }

	//ID，可以增加函数来使英雄用id调用
	virtual inline int getId() { return m_id; }

	//发射子弹，可以与下方的函数，与data一起构成一个class，
	void sendBullet();

	//跑技能效果（常用于被击中效果）（击中后的爆炸效果）
	void runSkillEffect(int skill_id, int loop = 1);

public:
	//属性get/set

	//移动速度
	inline void setSpeed(int speed) { m_speed = speed; }//用于之后对其不断的update
	inline void setInitSpeed(int speed) { m_initSpeed = speed; }//可以用于第一次的初始化，下面同

	//生命值
	inline int getHp() { return m_hp; }//这个可以判断是否在die函数调用的参数
	inline void setHp(int hp) { m_hp = hp; }
	inline void setInitHp(int hp) { m_initHp = hp; }

	//攻击距离
	inline void setAttackDistance(int distance) { m_attackDistance = distance; }
	inline void setInitAttackDistance(int distance) { m_initAttackDistance = distance; }

	//攻击力
	inline void setAtk(int atk) { m_atk = atk; }
	inline void setInitAtk(int atk) { m_initAtk = atk; }

	//防御力
	inline void setDefence(int defence) { m_defence = defence; }
	inline void setInitDefence(int def) { m_initDefence = def; }


	//子弹图片
	std::string getBulletImg();
	void setBulletImg(std::string img);

	//子弹速度
	inline void setBulletSpeed(int speed) { m_bulletSpeed = speed; }
	inline void setInitBulletSpeed(int speed) { m_initBulletSpeed = speed; }


protected:
	/*与战斗相关的数据*/
	Point m_desPoint;//当前的坐标

	int m_id;	//id


	int m_speed;	//移动速度
	int m_initSpeed;

	int m_attackDistance;	//攻击距离
	int m_initAttackDistance;

	int m_hp;//生命值
	int m_initHp;

	int m_atk;//攻击力
	int m_initAtk;

	int m_defence;//防御力
	int m_initDefence;


	int m_atkHateValue;//攻击附带仇恨

	std::string m_bulletImg;//子弹//可以作为单独的class

	int m_bulletSpeed;//子弹速度
	int m_initBulletSpeed;

};
#endif