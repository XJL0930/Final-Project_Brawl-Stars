#include"Shirley.h"
#include "Actor\MyAnimate.h"

Shirley::Shirley() {
	set_speed(0.1f);//�������ʱ������ʾ�ٶȣ�0.1f����ʾ�ٶ���10����С
	set_attackDistance(100);
	set_hp(800);
	set_atk(100);
	set_defence(100);
	set_atkHateValue(atk);
	set_bulletImg("ShirleyBullet.png");
	set_bulletSpeed(500);
	set_id(10001);
	set_skillCD(10.0f);
	set_heroName("hero/Hero1_back.png");
	down_animate = MyAnimate::creatHeroAnimate(1, "down", 4);
	left_animate = MyAnimate::creatHeroAnimate(1, "left", 4);
	right_animate = MyAnimate::creatHeroAnimate(1, "right", 4);
	up_animate = MyAnimate::creatHeroAnimate(1, "up", 4);

	//�������ҡ�
	stand_right = MyAnimate::creatHeroAnimate(1, "stand1", 1);
	stand_up = MyAnimate::creatHeroAnimate(1, "stand2", 1);
	stand_down = MyAnimate::creatHeroAnimate(1, "stand3", 1);
	stand_left = MyAnimate::creatHeroAnimate(1, "stand4", 1);
}
