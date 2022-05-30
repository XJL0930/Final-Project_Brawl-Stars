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

	Sprite* m_hero = nullptr;

protected:
	/*��ս����ص�����*/
	Vec2 m_facingPoint ;//��ǰ������


	int m_id;	//id


	float m_speed;	//�ƶ��ٶ�

	int m_attackDistance;	//��������

	int m_hp;//����ֵ

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