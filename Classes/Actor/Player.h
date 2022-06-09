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

	//virtual bool init(const std::string& name);
	//void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);//����˼��̰��µ��¼�
	//void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);//����˼����ɿ�����¼�
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;//�����ڽ����������İ��¿����ƶ���
	
	//void onMouseLeftPressed(cocos2d::EventMouse::MouseButton keyCode, cocos2d::Event* event);
	//void onMouseLeftReleased(cocos2d::EventMouse::MouseButton keyCode, cocos2d::Event* event);
	//std::map<EventMouse::MouseEventType, bool> mouses;//�����ڽ�����������ʱ�ܹ��������侫��
	bool isMousePressed;
	void onMouseMove(Event* event);
	bool onMouseDown(Event* event);
	//static Player* create(const std::string& name);
	static Player* create(const std::string& name, float offsetX=StartX, float offsetY=StartY);//�������ڹ����ʼλ��
	
	//Point getPlayerPosition() { return Vec2(offsetX, offsetY); }
	//virtual void stand();
	virtual void move();//�����ƶ��ĺ���
	bool bindPhysicsBody();
	bool bindMonsterBulletPhysicsBody(Sprite* bullet);
	
	//virtual void attack();


	//void exit();//����ע������ע������¼���
	/*���������������ڿ��Ƶ����ﾲֹʱ�Ĳ���*/
	void update(float delta);
	void update_mouse(float delta);//���º��������ڼ�⵱ǰmouse��λ�á�
	void update_move(float delta);
	void update_animate(float delta);//���ﾲֹʱ������ĳ���׷�����
	//void update_route(float delta);//����������·��
	void update_weapon(float delta);
	void update_setViewPointByPlayer(float dt);//�����ӽ�
	void update_weaponOut(float delta);
	float getFacingDistance(float point_x,float point_y);//�õ���mouse��x,y������ľ���
	Point getOffset() { return Point(offsetX, offsetY); }
	/*virtual void attack();//���ڹ����ĺ���
	virtual void skill();
	//virtual void injured();//����չʾ���˵ĺ���
	virtual void die();//����չʾ�����ĺ���

	void runStateEffect(int id);*/
private:
	float m_state_lastTime;
	Animate* currentAnimate = stand_left;
	//double maxLength=300;

};
#endif// !__HERO__H__
