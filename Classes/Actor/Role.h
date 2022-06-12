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

	

	//virtual void stand()=0;
	virtual void move()=0;//用于移动的函数
	
	


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
	
	

	

	bool collisionTest();//监测是否有障碍物
	bool grassTest();//监测是否走到草里了
	//使monster得到一个随机的坐标。
	//Point getRedomPos();
	void update_circle(float dt);
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
	bool if_out_circle();

	std::string TypeStr;
	void setTypeStr(std::string str);
protected:
	int gametime=180;
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
	
	const std::string str_1 = "hero/hero1_begin.png";
	const std::string str_2 = "hero/hero2_begin.png";
	const std::string str_3 = "hero/hero3_begin.png";
	const std::string str_4 = "hero/hero4_begin.png";


};
#endif