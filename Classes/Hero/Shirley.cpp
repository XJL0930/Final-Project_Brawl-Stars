#include"Shirley.h"

Shirley::Shirley() {
	set_speed(10);
	set_attackDistance(100);
	set_hp(800);
	set_atk(100);
	set_defence(100);
	set_atkHateValue(atk);
	set_bulletImg("ShirleyBullet.png");
	set_bulletSpeed(500);
	set_id(10001);
	set_skillCD(10.0f);
	/*用于代表动画的类
	my_Animate* left...;
	my_Animate* right...;
	my_Animate* up...;
	my_Animate*down...;

	*/
	return;
}