#include "Player.h"
#include"Hero\Shirley.h"
#include <ctime>

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

		srand((unsigned)time(NULL));
		player->pos = rand()%10;
		auto object = objGroup->getObject("playerPoint");
		switch (player->pos)
		{
		case 0:
			object = objGroup->getObject("playerPoint");
			break;
		case 1:
			object = objGroup->getObject("playerPoint1");
			break;
		case 2:
			object = objGroup->getObject("playerPoint2");
			break;
		case 3:
			object = objGroup->getObject("playerPoint3");
			break;
		case 4:
			object = objGroup->getObject("playerPoint4");
			break;
		case 5:	
			object = objGroup->getObject("playerPoint5");
			break;
		case 6:
			object = objGroup->getObject("playerPoint6");
			break;
		case 7:
			object = objGroup->getObject("playerPoint7");
			break;
		case 8:
			object = objGroup->getObject("playerPoint8");
			break;
		case 9:
			object = objGroup->getObject("playerPoint9");
			break;
		default:
			break;
		}

		int x = object["x"].asFloat();
		int y = object["y"].asFloat();
		//���ý�ɫ��ʼλ��
		player->setAnchorPoint(Vec2(0.5,0.5));
		player->setXY(x, y);
		//log("x:::%d  %d", offsetX,offsetY);
		player->setPosition(x,y);
		//��ǽ�ɫ
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
	//this->schedule(CC_SCHEDULE_SELECTOR(Player::update_route));
	this->schedule(CC_SCHEDULE_SELECTOR(Player::update_weapon),0.2f);
	this->schedule(CC_SCHEDULE_SELECTOR(Player::update_setViewPointByPlayer));
	//��ʼ�����̼����¼���
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		//rlog("key pressed");
		keys[keyCode] = true;
	};

	keyListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		//log("key pressed");
		keys[keyCode] = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
	
	auto _mouseListener = EventListenerMouse::create();
	_mouseListener->onMouseDown = [&](EventMouse* event)
	{
		//log("mouse down");
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

	 this->setCascadeOpacityEnabled(true);
	 if (grassTest())
		 this->setOpacity(100);
	 else
		 this->setOpacity(500);

	 if (keys[left])
	 {
		 offsetX -= 10;
		 if (!collisionTest())
		 {
			 auto moveBy = MoveBy::create(m_speed, Vec2(-10, 0));
			 //����
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
	 //Ц������򵥵ķ���������ķ�����
	 Point direction;
	 //ע��˴��õ���openGL����ϵ���������½�Ϊԭ��(0,0);
		 direction = tileCoordForPosition(m_facingPoint) ;
		
	 Point temp= tileCoordForPosition(Vec2(offsetX, offsetY));
		
	 if (direction.x - temp.x >= 0 && getFacingDistance(direction.x, temp.x) >= getFacingDistance(direction.y, temp.y))
		 currentFacing = FacingStatus::right;
	if (direction.x - temp.x < 0 && getFacingDistance(direction.x, temp.x) >= getFacingDistance(direction.y, temp.y))
		 currentFacing = FacingStatus::left;
	 if (direction.y - temp.y >= 0 && getFacingDistance(direction.x, temp.x) < getFacingDistance(direction.y, temp.y))
		 currentFacing = FacingStatus::up;
	if (direction.y - temp.y < 0 && getFacingDistance(direction.x, temp.x) < getFacingDistance(direction.y, temp.y))
		 currentFacing = FacingStatus::down;
	 if (lastFacing != currentFacing)
		 is_facingStatueChanged = true;
	 else
		 is_facingStatueChanged = false;
	 if (last_is_stand != current_is_stand)
		 is_standStatueChanged = true;
	 else
		 is_standStatueChanged = false;
	 /*log("temp::%f===========%f", temp.x,temp.y);
	
	 log("m_facingPoint:%f,%f", direction.x, direction.y);*/

 }

 void Player::onMouseMove(Event* event)
 {
	
	 EventMouse* e = (EventMouse*)event;
	 //m_facingPoint = tileCoordForPosition(Vec2(e->getCursorX(), e->getCursorY()));
	
	 m_facingPoint = Vec2(e->getCursorX() , e->getCursorY() )- viewPos;
	 
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
 //void Player::update_route(float delta)
 //{
	// // ����ʵʱ���������·�ߣ�������ʼλ�ã�Ŀ��λ��
	// m_currentPoint = m_hero->getPosition();
	// //log("m_currentPoint:%f,%f", m_currentPoint.x, m_currentPoint.y);
 //}
 void Player::update_weapon(float delta)
 {
	 if (isMousePressed)
	 {
		 //log("mouse pressed");
		 double nowlength = sqrt(pow(m_facingPoint.x -offsetX, 2) + pow(m_facingPoint.y - offsetY, 2));
		 double rate = 200 / nowlength;
		 const Vec2 route = Vec2((m_facingPoint.x - offsetX) * rate, (m_facingPoint.y - offsetY) * rate);
		 auto moveby = MoveBy::create(0.5f, route);
		 //log("offsetX:%f,offsetY:%f", offsetX, offsetY);
		 log("m_facingPoint.x:%f,m_facingPoint.y:%f", m_facingPoint.x, m_facingPoint.y);
		 Animate* animate = MyAnimate::creatWeaponAnimate("fire", "fire", 1);
		 auto cache = SpriteFrameCache::getInstance();
		 cache->addSpriteFramesWithFile("weapon/fire.plist", "weapon/fire.png");
		 //log("weaponcache is done!"); 

		 auto spriteframe =
			 SpriteFrameCache::getInstance()->getSpriteFrameByName("fire1.png");
		 auto bullet = Sprite::createWithSpriteFrame(spriteframe);
		 this->addChild(bullet);
		 auto arrived = [=]()
		 {
			 this->removeChild(bullet, true);
		 };
		 auto callfunc = CallFunc::create(arrived);
		 //log("%f,%f", heropos.x, heropos.y);
		 //bullet->setanchorpoint(point(0.5, 0.5));
		 
		 bullet->setPosition(
			 offsetX-originx,
			 offsetY-originy);
		 //this->schedule(CC_SCHEDULE_SELECTOR(Player::update_weaponOut));
		 // дһ�������������ڼ������������������ײ�����˶�������callfunc�����û����ײ����������callfunc
		 bullet->runAction(Sequence::create(moveby, animate, callfunc, NULL));
	 }
 }
 void Player::update_weaponOut(float delta)
 {
	 if (!collisionTest())
	 {
		 //bullet->runAction(Sequence::create(moveby, animate, callfunc, NULL));
	 }
	 else
	 {

	 }
 }
void Player::update_setViewPointByPlayer(float dt) {
	Layer* parent = (Layer*)getParent();
	//��ͼ��������
	Size mapTiledNum = m_map->getMapSize();

	//��ͼ�������Ӵ�С
	Size tiledSize = m_map->getTileSize();

	//��ͼ��С
	Size mapSize = Size::Size(mapTiledNum.width * tiledSize.width,
		mapTiledNum.height * tiledSize.height);

	//��Ļ��С
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//��������
	//log("%f   %f", , spritePos.y);
	//�����������С����Ļ��һ�룬��ȡ��Ļ�е����꣬����ȡ���ǵ�����
	float x = std::max(offsetX, visibleSize.width / 2);
	float y = std::max(offsetY, visibleSize.height / 2);

	x = std::min(x, mapSize.width - visibleSize.width / 2);
	y = std::min(y, mapSize.height - visibleSize.height / 2);

	//Ŀ���
	Point destPos = Point(x, y);
	
	//��Ļ�е�
	Point centerPos = Point(visibleSize.width / 2, visibleSize.height / 2);
	//������Ļ�е����Ҫһ����Ŀ�ĵ�֮��ľ���
	//Point viewPos = centerPos - destPos;
	viewPos =centerPos - destPos ;
	//log("%d  %d",offsetX,offsetY);
	parent->setPosition(viewPos);
	//log("desPositions%f======%f", tileCoordForPosition(destPos).x, tileCoordForPosition(destPos).y);
	//log("centPositions%f======%f", tileCoordForPosition(centerPos).x, tileCoordForPosition(centerPos).y);

	//m_facingPoint =(m_facingPoint) - 2 * viewPos;
	//log("map moved");
}
