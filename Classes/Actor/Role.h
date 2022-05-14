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
	/*update��ص�*/
	virtual void update(float delta);//Ĭ�ϵĸ��º��������Բ��ã�Ҳ���Ծ��尴�������
	virtual void update_akt();//���¹�����
	virtual void update_pos();//����λ��
	virtual void update_hp();//����Ѫ��

public:
	virtual void stand();
	virtual void move();
	virtual void attack();
	virtual void skill();
	virtual void injured();
	virtual void die();



public:
	/*�ⲿ���ýӿ�*/
	virtual inline void setDesPoint(const Point& p) { m_desPoint = p; }

	//ID���������Ӻ�����ʹӢ����id����
	virtual inline int getId() { return m_id; }

	//�����ӵ����������·��ĺ�������dataһ�𹹳�һ��class��
	void sendBullet();

	//�ܼ���Ч���������ڱ�����Ч���������к�ı�ըЧ����
	void runSkillEffect(int skill_id, int loop = 1);

public:
	//����get/set

	//�ƶ��ٶ�
	inline void setSpeed(int speed) { m_speed = speed; }//����֮����䲻�ϵ�update
	inline void setInitSpeed(int speed) { m_initSpeed = speed; }//�������ڵ�һ�εĳ�ʼ��������ͬ

	//����ֵ
	inline int getHp() { return m_hp; }//��������ж��Ƿ���die�������õĲ���
	inline void setHp(int hp) { m_hp = hp; }
	inline void setInitHp(int hp) { m_initHp = hp; }

	//��������
	inline void setAttackDistance(int distance) { m_attackDistance = distance; }
	inline void setInitAttackDistance(int distance) { m_initAttackDistance = distance; }

	//������
	inline void setAtk(int atk) { m_atk = atk; }
	inline void setInitAtk(int atk) { m_initAtk = atk; }

	//������
	inline void setDefence(int defence) { m_defence = defence; }
	inline void setInitDefence(int def) { m_initDefence = def; }


	//�ӵ�ͼƬ
	std::string getBulletImg();
	void setBulletImg(std::string img);

	//�ӵ��ٶ�
	inline void setBulletSpeed(int speed) { m_bulletSpeed = speed; }
	inline void setInitBulletSpeed(int speed) { m_initBulletSpeed = speed; }


protected:
	/*��ս����ص�����*/
	Point m_desPoint;//��ǰ������

	int m_id;	//id


	int m_speed;	//�ƶ��ٶ�
	int m_initSpeed;

	int m_attackDistance;	//��������
	int m_initAttackDistance;

	int m_hp;//����ֵ
	int m_initHp;

	int m_atk;//������
	int m_initAtk;

	int m_defence;//������
	int m_initDefence;


	int m_atkHateValue;//�����������

	std::string m_bulletImg;//�ӵ�//������Ϊ������class

	int m_bulletSpeed;//�ӵ��ٶ�
	int m_initBulletSpeed;

};
#endif