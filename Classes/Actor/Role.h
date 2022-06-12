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
	virtual void move()=0;//�����ƶ��ĺ���
	
	


	//����Ӣ�����͵İ�
	void bind_hero(Hero &hero);

	enum class FacingStatus { up=1, down, left, right };//�����ж�Ӣ�۵ĳ���

	//�жϳ�����û�иı�
	FacingStatus lastFacing = FacingStatus::left;
	FacingStatus currentFacing = FacingStatus::left;

	//�ж�����״̬
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
	//ID���������Ӻ�����ʹӢ����id����
	//virtual inline int getId() { return m_id; }
	
	

	

	bool collisionTest();//����Ƿ����ϰ���
	bool grassTest();//����Ƿ��ߵ�������
	//ʹmonster�õ�һ����������ꡣ
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
	//��player�п���ֱ�ӷ���Role��   
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
	float originx;//��ʼ��λ��
	float originy;
	float offsetX = 0;//��ǰ��λ��
	float offsetY = 0;

	/*��ͼ���*/
	TMXTiledMap* m_map;
	TMXLayer* meta_barrier;
	TMXLayer* meta_grass;

	/*��ս����ص�����*/
	Vec2 m_facingPoint ;//Ŀ�������
	Vec2 m_currentPoint;//��ǰ������

	int m_id;	//id


	float m_speed;	//�ƶ��ٶ�

	int m_attackDistance;	//��������

	int m_hp;//����ֵ

	int m_hp_max;//����ֵ����

	int m_atk;//������

	/*���ڴ��������� */
	Animate* left_animate;
	Animate* right_animate;
	Animate* up_animate;
	Animate* down_animate;
	//��ֹʱ��֡����
	Animate* stand_left; 
	Animate* stand_right;
	Animate* stand_up;
	Animate* stand_down;
	//y��
	
	const std::string str_1 = "hero/hero1_begin.png";
	const std::string str_2 = "hero/hero2_begin.png";
	const std::string str_3 = "hero/hero3_begin.png";
	const std::string str_4 = "hero/hero4_begin.png";


};
#endif