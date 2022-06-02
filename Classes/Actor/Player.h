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
	Point viewPos;
	//void onMouseLeftPressed(cocos2d::EventMouse::MouseButton keyCode, cocos2d::Event* event);
	//void onMouseLeftReleased(cocos2d::EventMouse::MouseButton keyCode, cocos2d::Event* event);
	//std::map<EventMouse::MouseEventType, bool> mouses;//�����ڽ�����������ʱ�ܹ��������侫��
	bool isMousePressed;
	void onMouseMove(Event* event);
	bool onMouseDown(Event* event);
	//static Player* create(const std::string& name);
	static Player* create(const std::string& name, float offsetX=StartX, float offsetY=StartY);//�������ڹ����ʼλ��
	void setXY(int x, int y);
	Point tileCoordForPosition(Point pos);
	void bind_Camera();//���ڰ������������ͷ�������ƶ�
	
	
	//virtual void stand();
	virtual void move();//�����ƶ��ĺ���

	//virtual void attack();

	/*���������������ڿ��Ƶ����ﾲֹʱ�Ĳ���*/
	void update(float delta);
	void update_mouse(float delta);//���º��������ڼ�⵱ǰmouse��λ�á�
	void update_move(float delta);
	void update_animate(float delta);//���ﾲֹʱ������ĳ���׷�����
	//void update_route(float delta);//����������·��
	void update_weapon(float delta);
	void update_setViewPointByPlayer(float dt);//�����ӽ�
	float getFacingDistance(float point_x,float point_y);//�õ���mouse��x,y������ľ���
	bool Player::collisionTest();//����Ƿ����ϰ���
	/*virtual void attack();//���ڹ����ĺ���
	virtual void skill();
	//virtual void injured();//����չʾ���˵ĺ���
	virtual void die();//����չʾ�����ĺ���

	void runStateEffect(int id);*/
	TMXTiledMap* m_map;
	TMXLayer* meta_barrier;
	TMXLayer* meta_grass;
private:
	float originx;
	float originy;
	float m_state_lastTime;
	float offsetX =0;
	float offsetY =0;
	bool is_facingStatueChanged = false;
	bool is_standStatueChanged = true;
	//double maxLength=300;
	Animate* currentAnimate = nullptr;

};
#endif// !__HERO__H__
