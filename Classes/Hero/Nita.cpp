#include"Nita.h"
#include "Actor\MyAnimate.h"

Nita::Nita() {
	set_speed(0.2f);//�������ʱ������ʾ�ٶȣ�0.1f����ʾ�ٶ���10����С
	set_hp(600);
	set_atk(200);
	down_animate = MyAnimate::creatHeroAnimate(2, "down", 4);
	left_animate = MyAnimate::creatHeroAnimate(2, "left", 4);
	right_animate = MyAnimate::creatHeroAnimate(2, "right", 4);
	up_animate = MyAnimate::creatHeroAnimate(2, "up", 4);

	//�������ҡ�
	stand_right = MyAnimate::creatHeroAnimate(2, "stand1", 1);
	stand_up = MyAnimate::creatHeroAnimate(2, "stand2", 1);
	stand_down = MyAnimate::creatHeroAnimate(2, "stand3", 1);
	stand_left = MyAnimate::creatHeroAnimate(2, "stand4", 1);
}
