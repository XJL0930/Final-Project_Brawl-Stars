#include"Bull.h"
#include "Actor\MyAnimate.h"

Bull::Bull() {
	set_speed(0.15f);//用所需的时间来表示速度，0.1f即表示速度是10个大小
	set_attackDistance(100);
	set_hp(800);
	set_atk(100);
	set_defence(100);
	set_atkHateValue(atk);
	set_bulletImg("ShirleyBullet.png");
	set_bulletSpeed(500);
	set_id(4);
	set_skillCD(10.0f);
	set_heroName("hero/Hero3_back.png");
	down_animate = MyAnimate::creatHeroAnimate(4, "down", 4);
	left_animate = MyAnimate::creatHeroAnimate(4, "left", 4);
	right_animate = MyAnimate::creatHeroAnimate(4, "right", 4);
	up_animate = MyAnimate::creatHeroAnimate(4, "up", 4);

	//左上下右。
	stand_right = MyAnimate::creatHeroAnimate(4, "stand1", 1);
	stand_up = MyAnimate::creatHeroAnimate(4, "stand2", 1);
	stand_down = MyAnimate::creatHeroAnimate(4, "stand3", 1);
	stand_left = MyAnimate::creatHeroAnimate(4, "stand4", 1);
}
