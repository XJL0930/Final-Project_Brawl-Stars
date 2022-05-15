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
	void update(float dt);
	virtual bool init(const std::string& name);
	Hero();//�ù��캯��ʵ�ּ������ļ���
	static Hero* create(const std::string& name);
	static Hero* create(const std::string& name, int offsetX, int offsetY);//�������ڹ����ʼλ��

	virtual void move();//�����Զ��ƶ��ĺ���
	virtual void attack();//�����Զ������ĺ���
	virtual void skill();
	virtual void die();//����չʾAI�����ĺ���

	//���д��е�״̬
	void runStateEffect(int id);

private:

};
#endif// !__HERO__H__
