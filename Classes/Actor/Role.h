#pragma once
#ifndef _ROLE_H_
#define _ROLE_H_
#include "cocos2d.h"
#include "HeroMessage.h"
#include "Hero/Hero.h"
#include <string>
USING_NS_CC;
using namespace cocos2d;
class Role : public Sprite {
	
public:
	Role();
	
	virtual bool init(const std::string& name);
	void initWithMessage(const HeroMessage& msg);

	/*update��ص�*/
	//virtual void update(float delta);//Ĭ�ϵĸ��º��������Բ��ã�Ҳ���Ծ��尴�������
	void update_akt();//���¹�����
	void update_pos();//����λ��
	void update_hp();//����Ѫ��

	//virtual void stand();
	virtual void move();//�����ƶ��ĺ���
	virtual void attack();//���ڹ����ĺ���
	virtual void skill();
	virtual void die();//����չʾ�����ĺ���
    void injured();//����չʾ���˵ĺ���
	inline bool isCanSkill() { return canUseSkill; };//�Ƿ���ʹ�ô���
	void update_skill(float dt);//���ڸ��´���
	//�ָ�״̬
	void recover();

	/*�ⲿ���ýӿ�*/
    inline void setDesPoint(const Point& p) { m_desPoint = p; }

	//����Ӣ�����͵İ�
	void bind_hero(Hero*);

	//ID���������Ӻ�����ʹӢ����id����
	//virtual inline int getId() { return m_id; }

	//�����ӵ����������·��ĺ�������dataһ�𹹳�һ��class��
	void sendBullet();

	//�ܼ���Ч���������ڱ�����Ч���������к�ı�ըЧ����
	void runSkillEffect(int skill_id, int loop = 1);

	//����get/set

	//�ƶ��ٶ�
	inline void setSpeed(int speed) { m_speed = speed; }//����֮����䲻�ϵ�update

	//������
	inline void setDefence(int defence) { m_defence = defence; }

protected:
	/*��ս����ص�����*/
	Point m_desPoint;//��ǰ������

	int m_id;	//id


	int m_speed;	//�ƶ��ٶ�

	int m_attackDistance;	//��������

	int m_hp;//����ֵ

	int m_atk;//������

	int m_defence;//������

	int m_atkHateValue;//�����������

	std::string m_bulletImg;//�ӵ�//������Ϊ������class

	int m_bulletSpeed;//�ӵ��ٶ�

	bool canUseSkill;//�Ƿ���ʹ�ô���

	float skillCD;//����CD
	/*���ڴ��������� 
	my_Animate* left;
	my_Animate* right;
	my_Animate* up;
	my_Animate*down;
	.
	.
	.
	*/

};
#endif