#include "Player.h"
#include"Hero/Shirley.h"
#include"Hero/Bull.h"
#include"Hero/Jack.h"
#include"Hero/Nita.h"
#include"Const/const.h"

void Player::update(float delta) {

}
Player* Player::create(const std::string& name, const Point pos)
{
	auto player = new(std::nothrow) Player();
	if (!player)
	{
		return nullptr;
	}
	player->initHeroPicture(Sprite::create(name));
	
	if (player && player->m_hero)
	{
		
		//���ý�ɫ��ʼλ��
		player->setAnchorPoint(Vec2(0.5,0.5));
		player->bindPhysicsBody();
		player->setXY(pos.x, pos.y);
		//log("x:::%d  %d", offsetX,offsetY);
		player->setPosition(pos);
		player->setTypeStr(name);
		//player->setTag(PLAYER_TAG);
		//��ǽ�ɫ
		//Hero hero_;
		if (name == player->str_1)
		{

			Shirley shirley;
			player->bind_hero(shirley);
		}
		else if (name == player->str_2)
		{
			Nita nita;
			player->bind_hero(nita);
			
		}
		else if (name == player->str_3)
		{
			Jack jack;
			player->bind_hero(jack);
		}
		else if (name == player->str_4)
		{
			Bull bull;
			player->bind_hero(bull);
		}
		player->autorelease();
		player->setBlood();
		return player;
	}
	
	return nullptr;
}
bool Player::bindPhysicsBody()
{
	auto physicsBody = cocos2d::PhysicsBody::createBox(m_hero->getContentSize(), cocos2d::PhysicsMaterial(0.0f, 1.0f, 0.0f));
	physicsBody->setDynamic(false);
	physicsBody->setGravityEnable(false);
	physicsBody->setRotationEnable(false);
	physicsBody->setContactTestBitmask(PLAYER_CONTACT_MASK);
	physicsBody->setCategoryBitmask(PLAYER_CATEGORY_MASK);
	this->setPhysicsBody(physicsBody);
	this->setTag(PLAYER_TAG);
	return true;
}
bool Player::bindMonsterBulletPhysicsBody(Sprite* bullet)
{
	auto physicsBody = cocos2d::PhysicsBody::createBox(m_hero->getContentSize(), cocos2d::PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody->setDynamic(false);
	physicsBody->setGravityEnable(false);
	physicsBody->setRotationEnable(false);
	physicsBody->setContactTestBitmask(PLAYER_BULLET_CONTACT_MASK);
	physicsBody->setCategoryBitmask(PLAYER_BULLET_CATEGORY_MASK);
	bullet->setPhysicsBody(physicsBody);
	bullet->setTag(PLAYER_BULLET_TAG);
	return true;
}
void Player::move()
{
	if (m_hero == nullptr)
		this->unscheduleAllCallbacks();

	this->schedule(CC_SCHEDULE_SELECTOR(Player::update_move),m_speed);
	this->schedule(CC_SCHEDULE_SELECTOR(Player::update_mouse));
	this->schedule(CC_SCHEDULE_SELECTOR(Player::update_animate));
	this->schedule(CC_SCHEDULE_SELECTOR(Player::update_circle),1.0f);
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
			 this->runAction(moveBy);
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

			 this->runAction(moveBy);
		 }
		 else
			 offsetX -= 10;
		
	 }
	 else if (keys[down])
	 {
		 offsetY -= 10;
		 if (!collisionTest()) {

			 auto moveBy = MoveBy::create(m_speed, Vec2(0, -10));

			 this->runAction(moveBy);
		 }
		 else 
			 offsetY += 10;
		
	 }
	 else if (keys[up])
	 {
		 offsetY += 10;
		 if (!collisionTest()) {
			 auto moveBy = MoveBy::create(m_speed, Vec2(0,10));

			this->runAction(moveBy);
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
	 //log("henfana::%f,====%f",offsetX, offsetY);
	 //log("henfana::%f,====%f", m_facingPoint.x, m_facingPoint.y);
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
	 //��һ�Σ�������������ӵ���ÿһ���ӵ���4����ÿ�Ŷ���sprite����bulletvec��
	 // һ���ƶ�10�룬�ܹ�ѭ��20�Σ�ÿһ���ж��Ƿ��⵽��ײ
	 //if (isMousePressed)//��Ҫ�ĳ�ֻ��һ��
	 //{
		// double nowlength = sqrt(pow(m_facingPoint.x - offsetX, 2) + pow(m_facingPoint.y - offsetY, 2));
		// double rate = 200 / nowlength;
		// const Vec2 route = Vec2((m_facingPoint.x - offsetX) * rate, (m_facingPoint.y - offsetY) * rate);
		// const Vec2 route_1 = Vec2(route.x * (sqrt(3) / 2.0) + route.y * (0.5), route.x * (-0.5) + route.y*(sqrt(3) / 2.0));
		// const Vec2 route_2 = Vec2(route.x * (sqrt(3) / 2.0) - route.y * (0.5), route.x * (0.5) + route.y*(sqrt(3) / 2.0));

		// 
		// auto moveby1 = MoveBy::create(0.5f, route);
		// auto moveby2 = MoveBy::create(0.5f, route_1);
		// auto moveby3 = MoveBy::create(0.5f, route_2);
		// 

		// auto cache = SpriteFrameCache::getInstance();
		// cache->addSpriteFramesWithFile("weapon/fire.plist", "weapon/fire.png");
		// auto spriteframe =
		//	 	 SpriteFrameCache::getInstance()->getSpriteFrameByName("fire1.png");
		//	  auto bullet1 = Sprite::createWithSpriteFrame(spriteframe);
		//	  auto bullet2 = Sprite::createWithSpriteFrame(spriteframe);
		//	  auto bullet3 = Sprite::createWithSpriteFrame(spriteframe);

		//	  this->addChild(bullet1);
		//	  this->addChild(bullet2);
		//	  this->addChild(bullet3);
		//	  auto arrived = [=]()
		//	  {
		//	 	 this->removeChild(bullet1, true);
		//		 this->removeChild(bullet2, true);
		//		 this->removeChild(bullet3, true);
		//	  };
		//	  auto callfunc = CallFunc::create(arrived);
		//	  //log("%f,%f", heropos.x, heropos.y);
		//	  //bullet->setanchorpoint(point(0.5, 0.5));

		//	  bullet1->setPosition(
		//	 	 offsetX - originx,
		//	 	 offsetY - originy);
		//	  bullet2->setPosition(
		//		  offsetX - originx,
		//		  offsetY - originy);
		//	  bullet3->setPosition(
		//		  offsetX - originx,
		//		  offsetY - originy);
		//	  bullet1->runAction(moveby1);
		//	  bullet2->runAction(moveby2);
		//	  bullet3->runAction(moveby3);
	 //}

	 // ��һ�η�һ���ӵ� 





	 // һ������һֱ����

	 if (isMousePressed)
	 {
		 //log("mouse pressed");
		 double nowlength = sqrt(pow(m_facingPoint.x - offsetX, 2) + pow(m_facingPoint.y - offsetY, 2));
		 double rate = 200 / nowlength;
		 const Vec2 route = Vec2((m_facingPoint.x - offsetX) * rate, (m_facingPoint.y - offsetY) * rate);
		 //��һ���ƶ���moveby�ĳ���΢�֣�����ѭ��ʹ�䵽���յ�
		// log("m_facingPoint.x:%f,m_facingPoint.y:%f", m_facingPoint.x, m_facingPoint.y);
		 auto cache = SpriteFrameCache::getInstance();
		 SpriteFrame* spriteframe = nullptr;
		 cache->addSpriteFramesWithFile("weapon/fire.plist", "weapon/fire.png");
		 //log("weaponcache is done!");
		 if (TypeStr == str_1)
		 {
			 spriteframe =
				 SpriteFrameCache::getInstance()->getSpriteFrameByName("fire1.png");
			 log("fire1,fire1,fire1");
		 }
		 else if (TypeStr == str_2)
		 {
			 spriteframe =
				 SpriteFrameCache::getInstance()->getSpriteFrameByName("fire2.png");
			 log("fire2,fire2,fire2");
		 }
		 else if (TypeStr == str_3)
			 spriteframe =
			 SpriteFrameCache::getInstance()->getSpriteFrameByName("fire3.png");
		 else if (TypeStr == str_4)
			 spriteframe =
			 SpriteFrameCache::getInstance()->getSpriteFrameByName("fire4.png");
		 auto bullet = Sprite::createWithSpriteFrame(spriteframe);
		 bindMonsterBulletPhysicsBody(bullet);
		 this->addChild(bullet);
		 auto arrived = [=]()
		 {
			 this->removeChild(bullet, true);
		 };
		 auto callfunc = CallFunc::create(arrived);
		 //log("%f,%f", heropos.x, heropos.y);
		 //bullet->setanchorpoint(point(0.5, 0.5));

		 bullet->setPosition(
			 m_hero->getPosition());
		 // this->schedule(CC_SCHEDULE_SELECTOR(Player::update_weaponOut));
		  // дһ�������������ڼ������������������ײ�����˶�������callfunc�����û����ײ����������callfunc
		/* bullet->runAction(Sequence::create(moveby, animate, callfunc, NULL));
		 bullet->runAction(Sequence::create(moveby, animate, callfunc, NULL));
		 bullet->runAction(Sequence::create(moveby, animate, callfunc, NULL));*/
		 for (int i = 1; i <= 20; i++)
		 {
			 auto moveby = MoveBy::create(0.5f, route / 20);
			 if (i != 20 && !collisionTest())
			 {
				 bullet->runAction(moveby);
			 }
			 else
			 {
				 bullet->runAction(Sequence::create(moveby, callfunc, NULL));
			 }
		 }

		 /*bullet->runAction(moveby2);
		 */
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


