#include "Player.h"
#include"Hero\Shirley.h"

void Player::update(float delta) {

}
Player* Player::create(const std::string& name, float offsetX, float offsetY)
{
	auto player = new(std::nothrow) Player();
	if (!player)
	{
		return nullptr;
	}
	player->initHeroPicture(Sprite::create(name));
	auto map = TMXTiledMap::create("Scene/desert_map/desert_map.tmx");
	if (player && player->m_hero)
	{
		TMXObjectGroup* objGroup = map->getObjectGroup("object");
		auto object = objGroup->getObject("playerPoint");

		int x = object["x"].asFloat();
		int y = object["y"].asFloat();
		//设置角色初始位置
		player->setAnchorPoint(Vec2(0.5,0.5));
		player->setXY(x, y);
		//log("x:::%d  %d", offsetX,offsetY);
		player->setPosition(x,y);
		//标记角色
		//Hero hero_;
		Shirley shirley;
		player->bind_hero(shirley);
		player->autorelease();
		return player;
	}
	
	return nullptr;
}
void Player::move()
{
	this->schedule(CC_SCHEDULE_SELECTOR(Player::update_move),m_speed);
	this->schedule(CC_SCHEDULE_SELECTOR(Player::update_mouse));
	this->schedule(CC_SCHEDULE_SELECTOR(Player::update_animate));
	this->schedule(CC_SCHEDULE_SELECTOR(Player::update_route));
	this->schedule(CC_SCHEDULE_SELECTOR(Player::update_weapon),0.2f);
	this->schedule(CC_SCHEDULE_SELECTOR(Player::update_setViewPointByPlayer), 0.05f);
	//初始化键盘监听事件。
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		log("key pressed");
		keys[keyCode] = true;
	};

	keyListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		log("key pressed");
		keys[keyCode] = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
	
	auto _mouseListener = EventListenerMouse::create();
	_mouseListener->onMouseDown = [&](EventMouse* event)
	{
		log("mouse down");
		isMousePressed = true;
	};
	_mouseListener->onMouseUp = [&](EventMouse* event)
	{
		//log("mouseLeft released");
		isMousePressed = false;
	};
	_mouseListener->onMouseMove = CC_CALLBACK_1(Player::onMouseMove, this);
	//_mouseListener->onMouseDown = CC_CALLBACK_1(Player::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);

	
	return;

}
 void Player::update_move(float delta)
 {

	 auto left = cocos2d::EventKeyboard::KeyCode::KEY_A;
	 auto right = cocos2d::EventKeyboard::KeyCode::KEY_D;
	 auto down = cocos2d::EventKeyboard::KeyCode::KEY_S;
	 auto up = cocos2d::EventKeyboard::KeyCode::KEY_W;


	 if (keys[left])
	 {
		 offsetX -= 10;
		 if (!collisionTest())
		 {
			 auto moveBy = MoveBy::create(m_speed, Vec2(-10, 0));
			 //测试
			 m_hero->runAction(moveBy);
		 }
		 else
			 offsetX += 10;
		 
	 }
	 else if (keys[right])
	 {
		 offsetX += 10;
		 if (!collisionTest())
		 {
			 auto moveBy = MoveBy::create(m_speed, Vec2(10,0));

			 m_hero->runAction(moveBy);
		 }
		 else
			 offsetX -= 10;
		
	 }
	 else if (keys[down])
	 {
		 offsetY -= 10;
		 if (!collisionTest()) {

			 auto moveBy = MoveBy::create(m_speed, Vec2(0, -10));

			 m_hero->runAction(moveBy);
		 }
		 else 
			 offsetY += 10;
		
	 }
	 else if (keys[up])
	 {
		 offsetY += 10;
		 if (!collisionTest()) {
			 auto moveBy = MoveBy::create(m_speed, Vec2(0,10));

			 m_hero->runAction(moveBy);
		 }
		 else
			 offsetY -= 10;
	 }
	 if (!keys[up] && !keys[down] && !keys[left] && !keys[right])
		 current_is_stand = true;
	 else
		 current_is_stand = false;
 }

 float Player::getFacingDistance(float point_x, float point_y)
 {
	 float res = point_x - point_y;
	 return res >= 0 ? res : -1 * res;
 }
 void Player::update_mouse(float delta)
 {
	 //注意此处用的是openGL坐标系，是在左下角为原点(0,0);
	 auto direction = m_facingPoint;

	 if (direction.x - offsetX >= 0 && getFacingDistance(direction.x, offsetX) >= getFacingDistance(direction.y, offsetY))
		 currentFacing = FacingStatus::right;
	 else if (direction.x - offsetX < 0 && getFacingDistance(direction.x, offsetX) >= getFacingDistance(direction.y, offsetY))
		 currentFacing = FacingStatus::left;
	 else if (direction.y - offsetY >= 0 && getFacingDistance(direction.x, offsetX) < getFacingDistance(direction.y, offsetY))
		 currentFacing = FacingStatus::up;
	 else if (direction.y - offsetY < 0 && getFacingDistance(direction.x, offsetX) < getFacingDistance(direction.y, offsetY))
		 currentFacing = FacingStatus::down;
	 if (lastFacing != currentFacing)
		 is_facingStatueChanged = true;
	 else
		 is_facingStatueChanged = false;
	 if (last_is_stand != current_is_stand)
		 is_standStatueChanged = true;
	 else
		 is_standStatueChanged = false;
	 //log("%d", is_facingStatue);
 }

 void Player::onMouseMove(Event* event)
 {
	 EventMouse* e = (EventMouse*)event;
	 m_facingPoint = Vec2(e->getCursorX() - 200, e->getCursorY() - 300);
	 log("m_facingPoint:%f,%f", m_facingPoint.x, m_facingPoint.y);
 }

 void Player::update_animate(float delta)
 {
	 //log("%d+++++++++%d",current_is_stand,last_is_stand );
	 if (is_facingStatueChanged || is_standStatueChanged)
	 {
		 m_hero->stopAction(currentAnimate);
		 switch (currentFacing)
		 {
		 case(FacingStatus::up):
		 {
			 if (current_is_stand)
				 currentAnimate = stand_up;
			 else
				 currentAnimate = up_animate;
			 break;
		 }
		 case(FacingStatus::down):
		 {
			 if (current_is_stand)
				 currentAnimate = stand_down;
			 else
				 currentAnimate = down_animate;
			 break;
		 }
		 case(FacingStatus::left):
		 {
			 if (current_is_stand)
				 currentAnimate = stand_left;
			 else
				 currentAnimate = left_animate;
			 break;
		 }
		 case(FacingStatus::right):
		 {
			 if (current_is_stand)
				 currentAnimate = stand_right;
			 else
				 currentAnimate = right_animate;
			 break;
		 }
		 default:break;

		 }
		 m_hero->runAction(currentAnimate);
		 last_is_stand = current_is_stand;
		 lastFacing = currentFacing;
	 }

 }
 void Player::update_route(float delta)
 {
	 // 用来实时监测武器的路线，包括起始位置，目标位置
	 m_currentPoint = m_hero->getPosition();
	 //log("m_currentPoint:%f,%f", m_currentPoint.x, m_currentPoint.y);
 }
 void Player::update_weapon(float delta)
 {
	 if (isMousePressed)
	 {
		 double nowLength = sqrt(pow(m_facingPoint.x - m_currentPoint.x, 2) + pow(m_facingPoint.y - m_currentPoint.y, 2));
		 double rate = 200 / nowLength;
		 const Vec2 route = Vec2((m_facingPoint.x - m_currentPoint.x) * rate, (m_facingPoint.y - m_currentPoint.y) * rate);
		 auto moveto = MoveBy::create(0.5, route);

		 Animate* animate = MyAnimate::creatWeaponAnimate("fire", "fire", 1);
		 auto cache = SpriteFrameCache::getInstance();
		 cache->addSpriteFramesWithFile("weapon/fire.plist", "weapon/fire.png");
		 //log("weaponCache is done!");

		 auto spriteFrame =
			 SpriteFrameCache::getInstance()->getSpriteFrameByName("fire1.png");
		 auto bullet = Sprite::createWithSpriteFrame(spriteFrame);
		 this->addChild(bullet);
		 auto arrived = [=]()
		 {
			 this->removeChild(bullet, true);
		 };
		 auto callfunc = CallFunc::create(arrived);
		 //log("%f,%f", heropos.x, heropos.y);
		 //bullet->setAnchorPoint(Point(0.5, 0.5));
		 bullet->setPosition(
			 m_currentPoint.x,
			 m_currentPoint.y);
		 bullet->runAction(Sequence::create(moveto, animate, callfunc, NULL));
		 //bullet->runAction(callfunc);
	 }
 }

void Player::update_setViewPointByPlayer(float dt) {
	Layer* parent = (Layer*)getParent();
	//地图方块数量
	Size mapTiledNum = m_map->getMapSize();

	//地图单个格子大小
	Size tiledSize = m_map->getTileSize();

	//地图大小
	Size mapSize = Size::Size(mapTiledNum.width * tiledSize.width,
		mapTiledNum.height * tiledSize.height);

	//屏幕大小
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//主角坐标
	//log("%f   %f", , spritePos.y);
	//如果主角坐标小于屏幕的一半，则取屏幕中点坐标，否则取主角的坐标
	float x = std::max(offsetX, visibleSize.width / 2);
	float y = std::max(offsetY, visibleSize.height / 2);

	x = std::min(x, mapSize.width - visibleSize.width / 2);
	y = std::min(y, mapSize.height - visibleSize.height / 2);

	//目标点
	Point destPos = Point(x, y);
	
	//屏幕中点
	Point centerPos = Point(visibleSize.width / 2, visibleSize.height / 2);
	//计算屏幕中点和所要一定的目的点之间的距离
	Point viewPos = centerPos - destPos;
	log("%d  %d",offsetX,offsetY);
	parent->setPosition(viewPos);
	log("map moved");
}

bool Player::collisionTest()
{
	int gid = 0;
	
	Size mapSize =m_map->getContentSize();
	Size tileSize = m_map->getTileSize();

	if (offsetX-15 < 0 || offsetX+10 >= mapSize.width ||
		offsetY-15 < 0 || offsetY+20 >= mapSize.height)
		return true;
	
	Point tiledGid = Point((int)(((this->offsetX)+5)/ tileSize.width),
		(int)(50-(this->offsetY-10) / tileSize.height));
	gid = meta_barrier->getTileGIDAt(tiledGid);
	if (gid!=0)
		return true;

	tiledGid = Point((int)(((this->offsetX)+5) / tileSize.width),
		(int)(50 - ((this->offsetY)+20)/ tileSize.height));
	gid = meta_barrier->getTileGIDAt(tiledGid);
	if (gid != 0)
		return true;

	tiledGid = Point((int)(((this->offsetX)-15)/ tileSize.width),
		(int)(50 - (this->offsetY-10) / tileSize.height));
	gid = meta_barrier->getTileGIDAt(tiledGid);
	if (gid != 0)
		return true;

	tiledGid = Point((int)(((this->offsetX)-15)/ tileSize.width),
		(int)(50 - ((this->offsetY)+20)/ tileSize.height));
	gid = meta_barrier->getTileGIDAt(tiledGid);
	if (gid != 0)
		return true;
	return false;
}

void Player::setXY(int x, int y)
{
	this->offsetX = x;
	this->offsetY = y;
	this->originx = x;
	this->originy = y;
}

Point Player::tileCoordForPosition(Point pos) {
	Size mapTiledNum = m_map->getMapSize();
	Size tiledSize = m_map->getTileSize();

	int x = pos.x/tiledSize.width;
	int y = pos.y/tiledSize.height;
	return Point(x, y);
}