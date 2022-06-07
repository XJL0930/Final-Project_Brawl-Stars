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

void Role::setXY(int x, int y)
{
	this->offsetX = x;
	this->offsetY = y;
	this->originx = x;
	this->originy = y;
}

Point Role::tileCoordForPosition(Point pos) {
	Size mapTiledNum = m_map->getMapSize();
	Size tiledSize = m_map->getTileSize();

	int x = pos.x / tiledSize.width;
	int y = pos.y / tiledSize.height;
	return Point(x, y);
}

bool Role::collisionTest()
{
	int gid = 0;

	Size mapSize = m_map->getContentSize();
	Size tileSize = m_map->getTileSize();

	if (offsetX - 15 < 0 || offsetX + 10 >= mapSize.width ||
		offsetY - 15 < 0 || offsetY + 20 >= mapSize.height)
		return true;

	Point tiledGid = Point((int)(((this->offsetX) + 5) / tileSize.width),
		(int)(50 - (this->offsetY - 10) / tileSize.height));
	gid = meta_barrier->getTileGIDAt(tiledGid);
	if (gid != 0)
		return true;

	tiledGid = Point((int)(((this->offsetX) + 5) / tileSize.width),
		(int)(50 - ((this->offsetY) + 20) / tileSize.height));
	gid = meta_barrier->getTileGIDAt(tiledGid);
	if (gid != 0)
		return true;

	tiledGid = Point((int)(((this->offsetX) - 15) / tileSize.width),
		(int)(50 - (this->offsetY - 10) / tileSize.height));
	gid = meta_barrier->getTileGIDAt(tiledGid);
	if (gid != 0)
		return true;

	tiledGid = Point((int)(((this->offsetX) - 15) / tileSize.width),
		(int)(50 - ((this->offsetY) + 20) / tileSize.height));
	gid = meta_barrier->getTileGIDAt(tiledGid);
	if (gid != 0)
		return true;
	return false;
}

bool Role::grassTest()
{
	int gid = 0;

	Size mapSize = m_map->getContentSize();
	Size tileSize = m_map->getTileSize();

	if (offsetX - 15 < 0 || offsetX + 10 >= mapSize.width ||
		offsetY - 15 < 0 || offsetY + 20 >= mapSize.height)
		return true;

	Point tiledGid = Point((int)(((this->offsetX) + 5) / tileSize.width),
		(int)(50 - (this->offsetY - 10) / tileSize.height));
	gid = meta_grass->getTileGIDAt(tiledGid);
	if (gid != 0)
		return true;

	tiledGid = Point((int)(((this->offsetX) + 5) / tileSize.width),
		(int)(50 - ((this->offsetY) + 20) / tileSize.height));
	gid = meta_grass->getTileGIDAt(tiledGid);
	if (gid != 0)
		return true;

	tiledGid = Point((int)(((this->offsetX) - 15) / tileSize.width),
		(int)(50 - (this->offsetY - 10) / tileSize.height));
	gid = meta_grass->getTileGIDAt(tiledGid);
	if (gid != 0)
		return true;

	tiledGid = Point((int)(((this->offsetX) - 15) / tileSize.width),
		(int)(50 - ((this->offsetY) + 20) / tileSize.height));
	gid = meta_grass->getTileGIDAt(tiledGid);
	if (gid != 0)
		return true;
	return false;
}

void Role::bind_map(TMXTiledMap* battlemap,
	TMXLayer* _meta_barrier,
	TMXLayer* _meta_grass)
{
	this->m_map = battlemap;
	this->meta_barrier = _meta_barrier;
	this->meta_grass = _meta_grass;
}