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
	void initMonsterPicture(Sprite* player);
	//void initWithMessage(const HeroMessage& msg);

	/*update相关的*/
	//virtual void update(float delta);//默认的更新函数，可以不用，也可以具体按照需求搞
	void update_akt();//更新攻击力
	void  update_pos();//更新位置
	void update_hp();//更新血量
	Vec2 getFacingPoint();
	Sprite* getPlayer();

	//virtual void stand()=0;
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


	//用于英雄类型的绑定
	void bind_hero(Hero &hero);

	enum class FacingStatus { up=1, down, left, right };//用于判定英雄的朝向

	//判断朝向有没有改变
	FacingStatus lastFacing = FacingStatus::left;
	FacingStatus currentFacing = FacingStatus::left;

	//判断行走状态
	bool current_is_stand = true;
	bool last_is_stand = true;

	int getHp();
	void setHp(int newHp);
	int getAtk();
	void setAtk(int newAtk);
	void getAttack(int attack);
	bool isDie();
	void scheduleBlood(float delta);
	void setBlood();
	//ID，可以增加函数来使英雄用id调用
	//virtual inline int getId() { return m_id; }
	
	//发射子弹，可以与下方的函数，与data一起构成一个class，
	void sendBullet();

	//跑技能效果（常用于被击中效果）（击中后的爆炸效果）
	void runSkillEffect(int skill_id, int loop = 1);

	//属性get/set

	//移动速度
	inline void setSpeed(float speed) { m_speed = speed; }//用于之后对其不断的update

	//防御力
	inline void setDefence(int defence) { m_defence = defence; }

	bool collisionTest();//监测是否有障碍物
	bool grassTest();//监测是否走到草里了
	//使monster得到一个随机的坐标。
	//Point getRedomPos();
	void update_animate(float delta);
	void setXY(int x, int y);
	Point tileCoordForPosition(Point pos);
	Animate* currentAnimate = stand_left;
	void bind_map(TMXTiledMap* battlemap,
		TMXLayer* meta_barrier,
		TMXLayer* meta_grass);
	Point viewPos;
	Sprite* m_hero = nullptr;
	Sprite* m_monster = nullptr;
	//从player中可以直接放在Role中   
	Point getRedomPos(int num);
	void setRedom(int ix) { redomNum = ix; }
	int redomNum;
	bool is_facingStatueChanged = false;
	bool is_standStatueChanged = true;
protected:
	float originx;//初始的位置
	float originy;
	float offsetX = 0;//当前的位置
	float offsetY = 0;

	/*地图相关*/
	TMXTiledMap* m_map;
	TMXLayer* meta_barrier;
	TMXLayer* meta_grass;

	/*与战斗相关的数据*/
	Vec2 m_facingPoint ;//目标的坐标
	Vec2 m_currentPoint;//当前的坐标

	int m_id;	//id


	float m_speed;	//移动速度

	int m_attackDistance;	//攻击距离

	int m_hp;//生命值

	int m_hp_max;//生命值上限

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
	Animate* up_animate;
	Animate* down_animate;
	//静止时的帧动画
	Animate* stand_left; 
	Animate* stand_right;
	Animate* stand_up;
	Animate* stand_down;
	//y用
	

};
#endif