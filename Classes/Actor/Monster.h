#pragma once
#ifndef __MONSTER__H__
#define __MONSTER__H__

#include "cocos2d.h"
#include "Role.h"
// Actor������
// ������pos����ʯ������Ѫ��
// �������Ƿ񱻹������Ƿ񹥻���Ѫ���仯
class Monster : public Role {
public:
	//void update(float dt);
	//virtual bool init(const std::string& name);
	//Hero();//�ù��캯��ʵ�ּ������ļ���
	//static Hero* create(const std::string& name);
	static Monster* create(const std::string& name, int maxMonster,Point startPos,int ix);//�������ڹ����ʼλ��

	virtual void move();//�����Զ��ƶ��ĺ���
	virtual void update_attack(float delata);//�����Զ������ĺ���

	//virtual void skill();
	//virtual void die();//����չʾAI�����ĺ���
	void updateMove(float delta);
	//void update_animate(float dealt);
	enum Direction{up=0,down,left,right};
	bool bindPhysicsBody();
	bool bindMonsterBulletPhysicsBody(Sprite* bullet);
	double setSrand(int num) { return num * 4.23 / 1.265 + 5; }
private:
	int dir;
	Animate* currentAnimate = stand_left;
	
	bool is_attack = false;
};
#endif// !__MONSTER__H__