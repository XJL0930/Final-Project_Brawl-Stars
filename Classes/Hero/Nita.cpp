#include"Nita.h"
#include "Actor\MyAnimate.h"

Nita::Nita() {
	set_speed(0.2f);//用所需的时间来表示速度，0.1f即表示速度是10个大小
	set_hp(600);
	set_atk(200);
	down_animate = MyAnimate::creatHeroAnimate(2, "down", 4);
	left_animate = MyAnimate::creatHeroAnimate(2, "left", 4);
	right_animate = MyAnimate::creatHeroAnimate(2, "right", 4);
	up_animate = MyAnimate::creatHeroAnimate(2, "up", 4);

	//左上下右。
	stand_right = MyAnimate::creatHeroAnimate(2, "stand1", 1);
	stand_up = MyAnimate::creatHeroAnimate(2, "stand2", 1);
	stand_down = MyAnimate::creatHeroAnimate(2, "stand3", 1);
	stand_left = MyAnimate::creatHeroAnimate(2, "stand4", 1);
}
