#include "Bullet.h"

Bullet* Bullet::create(const std::string& name)
{
	auto bullet = new(std::nothrow) Bullet();
	if (!bullet)
	{
		return nullptr;
	}
	bullet->initHeroPicture(Sprite::create(name));
	return bullet;
}
void Bullet::move()
{

}
void Bullet::setXY(int x,int y)
{
	this->offsetX = x;
	this->offsetY = y;
}
void Bullet::changeOffset(Vec2 d_route)
{
	//offsetX += d_route.x;
	//offsetY += d_route.y;
	//log("d_route.x=%f,d_route.y=%f", d_route.x, d_route.y);
	//log("bulletPos.x=%f,bulletPos.y=%f", offsetX, offsetY);
}