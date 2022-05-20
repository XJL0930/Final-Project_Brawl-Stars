#include "Player.h"
#include"Hero\Shirley.h"

void Player::update(float delta) {

}
Player* Player::create(const std::string& name)
{
	auto player = new(std::nothrow) Player();
	if (!player)
	{
		return nullptr;
	}
	player->initHeroPicture(Sprite::create(name));

	if (player && player->m_hero)
	{
		//设置角色初始位置
		player->setPosition(200,300);
		//标记角色
		//Hero hero_;
		Shirley shirley;
		player->bind_hero(shirley);
		return player;
	}
	player->autorelease();
	return nullptr;
}
 void Player::move()
{
	this->schedule(CC_SCHEDULE_SELECTOR(Player::update_move),0.05f);
	this->schedule(CC_SCHEDULE_SELECTOR(Player::update_mouse));
	//初始化键盘监听事件。
	//m_hero->runAction(RepeatForever::create(left_animate));
	//auto moveBy = MoveBy::create(0.1f, Vec2(-10, 0));
	//m_hero->runAction(moveBy);
	cocos2d::log("zhixing l ");
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
	_mouseListener->onMouseMove = CC_CALLBACK_1(Player::onMouseMove, this);
	//_mouseListener->onMouseUp = CC_CALLBACK_1(MouseTest::onMouseUp, this);//可以用于后续的子弹的发射
	//_mouseListener->onMouseDown = CC_CALLBACK_1(MouseTest::onMouseDown, this);
	//_mouseListener->onMouseScroll = CC_CALLBACK_1(MouseTest::onMouseScroll, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);


	return;

}

void Player::update_move(float delta)
{
   
    auto left = cocos2d::EventKeyboard::KeyCode::KEY_A;
    auto right = cocos2d::EventKeyboard::KeyCode::KEY_D;
    auto back = cocos2d::EventKeyboard::KeyCode::KEY_S;
    auto forward = cocos2d::EventKeyboard::KeyCode::KEY_W;


    if (keys[left])
    {
        auto moveBy = MoveBy::create(m_speed, Vec2(-10, 0));
		
		m_hero->runAction(moveBy);
		offsetX -= 10;
    }
    else if (keys[right])
    {
        MoveBy* moveBy = MoveBy::create(m_speed, Vec2(10, 0));
	
		m_hero->runAction(moveBy);
		offsetX += 10;
    }
    else if (keys[back])
    {
        auto moveBy = MoveBy::create(m_speed, Vec2(0, -10));
	
		m_hero->runAction(moveBy);
		offsetY += 10;
    }
    else if (keys[forward])
    {
        auto moveBy = MoveBy::create(m_speed, Vec2(0, 10));
	
		m_hero->runAction(moveBy);
		offsetY -= 10;
	}
}

//void Player::onMouseDown(Event* event)
//{
//	// to illustrate the event....
//	EventMouse* e = (EventMouse*)event;
//	string str = "Mouse Down detected, Key: ";
//	str += tostr(e->getMouseButton());
//}
//
//void Player::onMouseUp(Event* event)
//{
//	// to illustrate the event....
//	EventMouse* e = (EventMouse*)event;
//	string str = "Mouse Up detected, Key: ";
//	str += tostr(e->getMouseButton());
//}

float Player::getFacingDistance(float point_x, float point_y)
{
	float res = point_x - point_y;
	return res > 0 ? res : -1 * res;
}
void Player::update_mouse(float delta)
{
	auto direction = m_facingPoint;
	if (direction.x - offsetX >= 0 && getFacingDistance(direction.x, offsetX) >= getFacingDistance(direction.y, offsetY))
		currentFacing = FacingStatus::right;
	else if (direction.x - offsetX < 0 && getFacingDistance(direction.x, offsetX) >= getFacingDistance(direction.y, offsetY))
		currentFacing = FacingStatus::left;
	else if (direction.y - offsetY < 0 && getFacingDistance(direction.x, offsetX) < getFacingDistance(direction.y, offsetY))
		currentFacing = FacingStatus::up;
	else if (direction.y - offsetY >= 0 && getFacingDistance(direction.x, offsetX) < getFacingDistance(direction.y, offsetY))
		currentFacing = FacingStatus::down;
	if (lastFacing != currentFacing)
		is_facingStatue = true;
	else
		is_facingStatue = false;
}
void Player::onMouseMove(Event* event)
{
	EventMouse* e = (EventMouse*)event;
	setFacingPoint(e->getLocation());
}
//void Player::setDirestionPicture()
//{
//	if (is_facingStatue)
//	{
//		switch (currentFacing)
//		{
//			case(FacingStatus::up):
//
//		}
//		//m_hero=Sprite::create("hero/Hero_%d")
//	}
//}