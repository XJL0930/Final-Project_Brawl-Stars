#pragma once
#ifndef __BULLET_H__
#define __BULLET_H__

#include "Role.h"

class Bullet :public Role
{
public:
	virtual void move();
	static Bullet* create(const std::string& name);
	void setXY(int x, int y);
	void changeOffset(Vec2 d_route);
};
#endif // !__BULLET_H__


