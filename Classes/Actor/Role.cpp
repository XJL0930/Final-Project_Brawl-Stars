#include"Role.h"
#include"Const/const.h"

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
	right_animate = hero.getRightAnimate();
	up_animate = hero.getUpAnimate();
	down_animate = hero.getDownAnimate();
	stand_left = hero.getStandLeftAnimate();
	stand_right = hero.getStandRightAnimate();
	stand_up = hero.getStandUpAnimate();
	stand_down = hero.getStandDownAnimate();
	return;

}
int Role::getHp()
{
	return m_hp;
}
void Role::setHp(int newHp)
{
	m_hp = newHp;
}
int Role::getAtk()
{
	return m_atk;
}
void Role::setAtk(int newAtk)
{
	m_atk = newAtk;
}
void Role::getAttack(int attack)
{
	m_hp -= attack;
}
bool Role::isDie()
{
	if (m_hp == 0)
		return true;
	else
		return false;
}
void Role::initHeroPicture(Sprite* _player)
{
	m_hero = _player;
	
	this->addChild(m_hero);
	return;
}
void Role::initMonsterPicture(Sprite* player)
{
	m_monster = player;
	this->addChild(m_monster);
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
Point Role::getRedomPos(int num)
{
	Point nowPosition = this->getPosition();
	/*Size mapSize = m_map->getContentSize();
	Size tileSize = m_map->getTileSize();*/
	Point mapSize = Vec2(1555, 1650);
	Point nextPosition;
	
	do {
		float redomXsize, redomYsize;
		srand((unsigned)time(NULL)+num);
		int i = rand() % 4;
		if (i == 0)
		{
			 redomXsize = (rand() % 10 + 1)*10;
			 redomYsize = (rand() % 10 + 1)*10;
		}
		else if(i==1)
		{
			redomXsize = ((-1) * (rand() % 10 + 1))*10;
			redomYsize = ((-1) * (rand() % 10 + 1))*10;
		}
		else if (i == 2)
		{
			redomXsize =  (rand() % 10 + 1) * 10;
			redomYsize = ((-1) * (rand() % 10 + 1)) * 10;
		}
		else if (i == 3)
		{
			redomXsize = ((-1) * (rand() % 10 + 1)) * 10;
			redomYsize =  (rand() % 10 + 1) * 10;
		}
		nextPosition = nowPosition + Point(redomXsize, redomYsize);
	} while (nextPosition > mapSize && !collisionTest());
	//log("newPosotion:%f,%f", nextPosition.x, nextPosition.y);
	return nextPosition;
}