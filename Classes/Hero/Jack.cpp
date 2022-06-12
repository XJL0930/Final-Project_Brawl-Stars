#include"Jack.h"
#include "Actor\MyAnimate.h"

Jack::Jack() {
	set_speed(0.07f);//�������ʱ������ʾ�ٶȣ�0.1f����ʾ�ٶ���10����С
	set_hp(1000);
	set_atk(100);
	down_animate = MyAnimate::creatHeroAnimate(3, "down", 4);
	left_animate = MyAnimate::creatHeroAnimate(3, "left", 4);
	right_animate = MyAnimate::creatHeroAnimate(3, "right", 4);
	up_animate = MyAnimate::creatHeroAnimate(3, "up", 4);

	//�������ҡ�
	stand_right = MyAnimate::creatHeroAnimate(3, "stand1", 1);
	stand_up = MyAnimate::creatHeroAnimate(3, "stand2", 1);
	stand_down = MyAnimate::creatHeroAnimate(3, "stand3", 1);
	stand_left = MyAnimate::creatHeroAnimate(3, "stand4", 1);
}
