#include"Role.h"

void Role::bind_hero(Hero* hero) {

	m_speed = hero->get_speed();
	m_attackDistance = hero->get_attackDistance();
	m_hp = hero->get_hp();
	m_atk = hero->get_atk();
	m_defence = hero->get_defence();
	m_atkHateValue = hero->get_atkHateValue();
	m_bulletImg = hero->get_bulletImg();
	m_bulletSpeed = hero->get_bulletSpeed();
	m_id = hero->get_id();
	skillCD = hero->get_skillCD();
	return;

}