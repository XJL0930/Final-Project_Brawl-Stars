#pragma once
#ifndef _ROLE_H_
#define _ROLE_H_
#include "cocos2d.h"
//#include "HeroMessage.h"
#include "Hero/Hero.h"
#include"Hero/Shirley.h"
#include <string>
USING_NS_CC;
using namespace cocos2d;
class Role : public Sprite {
	
public:
	//Role();
	
	void initHeroPicture(Sprite*_player);
	//void initWithMessage(const HeroMessage& msg);

	/*update相关的*/
	//virtual void update(float delta);//默认的更新函数，可以不用，也可以具体按照需求搞
	void update_akt();//更新攻击力
	void  update_pos();//更新位置
	void update_hp();//更新血量
	Vec2 getFacingPoint();
	Sprite* getPlayer();

	//virtual void stand();
	virtual void move()=0;//用于移动的函数
	/*
	virtual void attack();//用于攻击的函数
	virtual void skill();
	virtual void die();//用于展示死亡的函数
    void injured();//用于展示受伤的函数*/
	inline bool isCanSkill() { return canUseSkill; };//是否能使用大招
	void update_skill(float dt);//用于更新大招
	//恢复状态
	void recover();

	/*外部调用接口*/
    inline void setFacingPoint(const Point& p) { m_facingPoint = p; }

	//用于英雄类型的绑定
	void bind_hero(Hero hero);

	enum class FacingStatus { up=1, down, left, right };//用于判定英雄的朝向

	FacingStatus lastFacing = FacingStatus::left;
	FacingStatus currentFacing;

	//ID，可以增加函数来使英雄用id调用
	//virtual inline int getId() { return m_id; }
	
	//发射子弹，可以与下方的函数，与data一起构成一个class，
	void sendBullet();

	//跑技能效果（常用于被击中效果）（击中后的爆炸效果）
	void runSkillEffect(int skill_id, int loop = 1);

	//属性get/set

	//移动速度
	inline void setSpeed(int speed) { m_speed = speed; }//用于之后对其不断的update

	//防御力
	inline void setDefence(int defence) { m_defence = defence; }

	Sprite* m_hero = nullptr;

protected:
	/*与战斗相关的数据*/
	Vec2 m_facingPoint ;//当前的坐标


	int m_id;	//id


	int m_speed;	//移动速度

	int m_attackDistance;	//攻击距离

	int m_hp;//生命值

	int m_atk;//攻击力

	int m_defence;//防御力

	int m_atkHateValue;//攻击附带仇恨

	std::string m_bulletImg;//子弹//可以作为单独的class

	int m_bulletSpeed;//子弹速度

	bool canUseSkill;//是否能使用大招

	float skillCD;//大招CD
	/*用于代表动画的类 */
	Animate* left_animate;
	Animate* right_animate;
	Animate* forward_animate;
	Animate* back_animate;

	

};
#endif