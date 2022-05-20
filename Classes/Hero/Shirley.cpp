#include"Shirley.h"
#include "Actor\MyAnimate.h"

Shirley::Shirley() {
	set_speed(0.1f);//用所需的时间来表示速度，0.1f即表示速度是10个大小
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
	left_animate = MyAnimate::creatHeroAnimate(1, "left", 4);
	right_animate = MyAnimate::creatHeroAnimate(1, "right", 4);
	up_animate = MyAnimate::creatHeroAnimate(1, "up", 4);
	down_animate = MyAnimate::creatHeroAnimate(1, "down", 4);
	/*stand_left= MyAnimate::creatHeroAnimate(1, "left", 4);
	stand_right
	stand_up
	stand_down*/
}