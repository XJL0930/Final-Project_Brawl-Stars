#pragma once
#ifndef __HERO__H__
#define __HERO__H__

#include "cocos2d.h"
#include "Role.h"
// Actor������
// ������pos����ʯ������Ѫ��
// �������Ƿ񱻹������Ƿ񹥻���Ѫ���仯
class Hero : public Role {
public:
	Hero();//�ù��캯��ʵ�ּ������ļ���
	static Hero* create(const std::string& name);
	static Hero* create(const std::string& name, int offsetX, int offsetY);//�������ڹ����ʼλ��

	void auto_move();

	//���д��е�״̬
	void runStateEffect(int id);
	//�Ƿ���ʹ�ô���
	inline bool isCanSkill() { return canUseSkill; }
	//�ָ�״̬
	void recover();

private:
	virtual void update(float dt);
	void update_skill(float dt);//���ڸ��´���
private:
	bool canUseSkill;

	float m_state_lastTime;


	float skillCD;

	Sprite* m_Hero;

};
#endif// !__HERO__H__
