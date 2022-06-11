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

	/*update��ص�*/
	//virtual void update(float delta);//Ĭ�ϵĸ��º��������Բ��ã�Ҳ���Ծ��尴�������
	void update_akt();//���¹�����
	void  update_pos();//����λ��
	void update_hp();//����Ѫ��
	Vec2 getFacingPoint();
	Sprite* getPlayer();

	//virtual void stand()=0;
	virtual void move()=0;//�����ƶ��ĺ���
	/*
	virtual void attack();//���ڹ����ĺ���
	virtual void skill();
	virtual void die();//����չʾ�����ĺ���
    void injured();//����չʾ���˵ĺ���*/
	inline bool isCanSkill() { return canUseSkill; };//�Ƿ���ʹ�ô���
	void update_skill(float dt);//���ڸ��´���
	//�ָ�״̬
	void recover();


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
	
	//�����ӵ����������·��ĺ�������dataһ�𹹳�һ��class��
	void sendBullet();

	//�ܼ���Ч���������ڱ�����Ч���������к�ı�ըЧ����
	void runSkillEffect(int skill_id, int loop = 1);

	//����get/set

	//�ƶ��ٶ�
	inline void setSpeed(float speed) { m_speed = speed; }//����֮����䲻�ϵ�update

	//������
	inline void setDefence(int defence) { m_defence = defence; }

	bool collisionTest();//����Ƿ����ϰ���
	bool grassTest();//����Ƿ��ߵ�������
	//ʹmonster�õ�һ����������ꡣ
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
	//��player�п���ֱ�ӷ���Role��   
	Point getRedomPos(int num);
	void setRedom(int ix) { redomNum = ix; }
	int redomNum;
	bool is_facingStatueChanged = false;
	bool is_standStatueChanged = true;
protected:
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

	int m_defence;//������

	int m_atkHateValue;//�����������

	std::string m_bulletImg;//�ӵ�//������Ϊ������class

	int m_bulletSpeed;//�ӵ��ٶ�

	bool canUseSkill;//�Ƿ���ʹ�ô���

	float skillCD;//����CD
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
	

};
#endif