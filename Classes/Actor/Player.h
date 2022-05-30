#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_
#define StartX 200
#define StartY 300
#include "cocos2d.h"
#include "Role.h"
#include"Hero\Hero.h"

// Actor������
// ������pos����ʯ������Ѫ��
// �������Ƿ񱻹������Ƿ񹥻���Ѫ���仯
class Player : public Role {
public:
	void update(float dt);
	//virtual bool init(const std::string& name);
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);//����˼��̰��µ��¼�
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);//����˼����ɿ�����¼�
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;//�����ڽ����������İ��¿����ƶ���
	void onMouseMove(Event* event);

	//static Player* create(const std::string& name);
	static Player* create(const std::string& name, float offsetX=StartX, float offsetY=StartY);//�������ڹ����ʼλ��

	void bind_Camera();//���ڰ������������ͷ�������ƶ�
	void update_move(float dt);
	
	//virtual void stand();
	virtual void move();//�����ƶ��ĺ���



	/*���������������ڿ��Ƶ����ﾲֹʱ�Ĳ���*/
	void Player::update_mouse(float delta);//���º��������ڼ�⵱ǰmouse��λ�á�
	float getFacingDistance(float point_x,float point_y);//�õ���mouse��x,y������ľ���
	void update_animate(float delta);//���ﾲֹʱ������ĳ���׷����ꡣ
	/*virtual void attack();//���ڹ����ĺ���
	virtual void skill();
	//virtual void injured();//����չʾ���˵ĺ���
	virtual void die();//����չʾ�����ĺ���

	void runStateEffect(int id);*/
private:
	float m_state_lastTime;
	float offsetX = 0;
	float offsetY = 0;
	bool is_facingStatueChanged = false;
	bool is_standStatueChanged = true;
	Animate* currentAnimate = nullptr;

};
#endif// !__HERO__H__
