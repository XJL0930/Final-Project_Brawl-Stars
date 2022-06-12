#include"Jack.h"
#include "Actor\MyAnimate.h"

Jack::Jack() {
	set_speed(0.07f);//用所需的时间来表示速度，0.1f即表示速度是10个大小
	set_hp(1000);
	set_atk(100);
	down_animate = MyAnimate::creatHeroAnimate(3, "down", 4);
	left_animate = MyAnimate::creatHeroAnimate(3, "left", 4);
	right_animate = MyAnimate::creatHeroAnimate(3, "right", 4);
	up_animate = MyAnimate::creatHeroAnimate(3, "up", 4);

	//左上下右。
	stand_right = MyAnimate::creatHeroAnimate(3, "stand1", 1);
	stand_up = MyAnimate::creatHeroAnimate(3, "stand2", 1);
	stand_down = MyAnimate::creatHeroAnimate(3, "stand3", 1);
	stand_left = MyAnimate::creatHeroAnimate(3, "stand4", 1);
}
