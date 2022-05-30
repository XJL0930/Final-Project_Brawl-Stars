#include"Role.h"

void Role::bind_hero(Hero &hero) {
	m_speed = hero.get_speed();
	m_attackDistance = hero.get_attackDistance();
	m_hp = hero.get_hp();
	m_atk = hero.get_atk();
	m_defence = hero.get_defence();
	m_atkHateValue = hero.get_atkHateValue();
	m_bulletImg = hero.get_bulletImg();
	m_bulletSpeed = hero.get_bulletSpeed();
	m_id = hero.get_id();
	skillCD = hero.get_skillCD();
	left_animate = hero.getLeftAnimate();
	cocos2d::log("zhixing l ");
	right_animate = hero.getRightAnimate();
	cocos2d::log("zhixing l ");
	up_animate = hero.getUpAnimate();
	cocos2d::log("zhixing l ");
	down_animate = hero.getDownAnimate();
	cocos2d::log("zhixing l ");
	stand_left = hero.getStandLeftAnimate();
	stand_right = hero.getStandRightAnimate();
	stand_up = hero.getStandUpAnimate();
	stand_down = hero.getStandDownAnimate();
	return;

}
void Role::initHeroPicture(Sprite* _player)
{
	m_hero = _player;
	this->addChild(m_hero);
	return;
}
Sprite* Role::getPlayer()
{
	return m_hero;
}

