#pragma once
#ifndef __HERO__H__
#define __HERO__H__

#include "cocos2d.h"
#include "Actor.h"
// Actor������
// ������pos����ʯ������Ѫ��
// �������Ƿ񱻹������Ƿ񹥻���Ѫ���仯
class Hero :public Actor
{
	// Ӣ����������������ͨ��������һ�񣬴��м�������
	// ��������ʱ�����������ָ����������˾Ͳ��ٻָ���
	CC_SYNTHESIZE(INT32, EnergyNum, _EnergyNum);
	CC_SYNTHESIZE(bool, isEnergyFull, _isEnergyFull);

public:
	static Hero* create();
	virtual void WeaponCharge();
	virtual void move();
	virtual void attack();
};
#endif // !__HERO__H__
