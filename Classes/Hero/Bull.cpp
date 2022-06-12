#include"Bull.h"
#include "Actor\MyAnimate.h"

Bull::Bull() {
	set_speed(0.15f);//�������ʱ������ʾ�ٶȣ�0.1f����ʾ�ٶ���10����С
	set_hp(800);
	set_atk(100);
	down_animate = MyAnimate::creatHeroAnimate(4, "down", 4);
	left_animate = MyAnimate::creatHeroAnimate(4, "left", 4);
	right_animate = MyAnimate::creatHeroAnimate(4, "right", 4);
	up_animate = MyAnimate::creatHeroAnimate(4, "up", 4);

	//�������ҡ�
	stand_right = MyAnimate::creatHeroAnimate(4, "stand1", 1);
	stand_up = MyAnimate::creatHeroAnimate(4, "stand2", 1);
	stand_down = MyAnimate::creatHeroAnimate(4, "stand3", 1);
	stand_left = MyAnimate::creatHeroAnimate(4, "stand4", 1);
}
