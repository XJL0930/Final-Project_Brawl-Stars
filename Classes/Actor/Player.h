#pragma once
#ifndef __HERO__H__
#define __HERO__H__

#include "cocos2d.h"
#include "Role.h"

// Actor������
// ������pos����ʯ������Ѫ��
// �������Ƿ񱻹������Ƿ񹥻���Ѫ���仯
class Player : public Role {
public:
	void update(float dt);
	virtual bool init(const std::string& name);
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);//����˼��̰��µ��¼�
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);//����˼����ɿ�����¼�
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;//�����ڽ����������İ��¿����ƶ���
	static Player* create(const std::string& name);
	static Player* create(const std::string& name, int offsetX, int offsetY);//�������ڹ����ʼλ��

	void bind_Camera();//���ڰ������������ͷ�������ƶ�

	virtual void stand();
	virtual void move();//�����ƶ��ĺ���
	virtual void attack();//���ڹ����ĺ���
	virtual void skill();
	//virtual void injured();//����չʾ���˵ĺ���
	virtual void die();//����չʾ�����ĺ���

	void runStateEffect(int id);
private:
	float m_state_lastTime;

};
#endif// !__HERO__H__
