#include"Role.h"
#include"Const/const.h"

void Role::bind_hero(Hero &hero) {
	m_speed = hero.get_speed();
	m_hp = hero.get_hp();
	m_hp_max = hero.get_hp();
	m_atk = hero.get_atk();
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
void Role::setTypeStr(std::string str)
{
	TypeStr = str;
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
	if (m_hp <= 0)
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

void Role::setBlood() {
	auto sprite = Sprite::create("bar.png");   //创建进度框
	sprite->setScaleX(0.1);
	sprite->setScaleY(0.1);
	auto size = this->getContentSize();
	sprite->setPosition(Point(size.width / 2, size.height - 20)); //设置框的位置
	this->addChild(sprite);            //加到默认图层里面去
	auto sprBlood = Sprite::create("blood.png");  //创建血条
	sprBlood->setScaleX(0.1);
	sprBlood->setScaleY(0.1);
	ProgressTimer* progress = ProgressTimer::create(sprBlood); //创建progress对象
	progress->setType(ProgressTimer::Type::BAR);        //类型：条状
	progress->setPosition(Point(size.width / 2, size.height - 20));
	progress->setScale(0.1);
	//从右到左减少血量
	progress->setMidpoint(Point(0, 0.5));     //如果是从左到右的话，改成(1,0.5)即可
	progress->setBarChangeRate(Point(1, 0));
	progress->setTag(BLOOD_BAR);       //做一个标记
	this->addChild(progress);
	schedule(CC_SCHEDULE_SELECTOR(Role::scheduleBlood), 0.1f);  //刷新函数，每隔0.1秒
}

void Role::scheduleBlood(float delta) {
	auto progress = (ProgressTimer*)this->getChildByTag(BLOOD_BAR);
	progress->setPercentage((((float)m_hp) / m_hp_max) * 100);  //这里是百分制显示
	log("%d %d", m_hp, m_hp_max);
	if (progress->getPercentage() < 0) {
		this->unschedule(CC_SCHEDULE_SELECTOR(Role::scheduleBlood));
	}
}



bool Role::if_out_circle() {
	if (offsetX<4 * (180 - gametime) || offsetX>(1600 - 5 * (180 - gametime)) || offsetY<4 * (180 - gametime) || offsetY>(1600 - 5 * (180 - gametime)))
		return true;
	return false;
}

void Role::update_circle(float dt){
	gametime--;
	log("%d", gametime);
	if (if_out_circle())
		m_hp -= 5*(180-gametime);
}