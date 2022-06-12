#include "Monster.h"
#include"Hero/Shirley.h"
#include"Hero/Bull.h"
#include"Hero/Jack.h"
#include"Hero/Nita.h"
#include"Player.h"
#include"Const/const.h"



Monster* Monster::create(const std::string& name, int maxMonster, Point startPos,int ix)
{
	
	auto monster = new(std::nothrow) Monster();
	if (!monster)
	{
		return nullptr;
	}
	monster->initMonsterPicture(Sprite::create(name));
	if (monster && monster->m_monster)
	{

		//���ý�ɫ��ʼλ��
		monster->setRedom(ix);
		monster->setPosition(startPos);
		monster->setXY(monster->getPosition().x, monster->getPosition().y);
		//monster->setTag((monster->redomNum + 1) * 10 + 100);
		//monster->setTag(MONSTER_TAG);
		monster->setTypeStr(name);
		//��ǽ�ɫ
		if (name == monster->str_1)
		{

			Shirley shirley;
			monster->bind_hero(shirley);
		}
		else if (name == monster->str_2)
		{
			Nita nita;
			monster->bind_hero(nita);

		}
		else if (name == monster->str_3)
		{
			Jack jack;
			monster->bind_hero(jack);
		}
		else if (name == monster->str_4)
		{
			Bull bull;
			monster->bind_hero(bull);
		}
		monster->bindPhysicsBody();
		monster->setBlood();
		monster->autorelease();
	
		return monster;
	}
	return nullptr;
}
bool Monster::bindPhysicsBody()
{
	auto physicsBody = cocos2d::PhysicsBody::createBox(m_monster->getContentSize(), cocos2d::PhysicsMaterial(0.0f, 1.0f, 0.0f));
	physicsBody->setDynamic(false);
	physicsBody->setGravityEnable(false);
	physicsBody->setRotationEnable(false);
	physicsBody->setContactTestBitmask(MONSTER_CONTACT_MASK);
	physicsBody->setCategoryBitmask(MONSTER_CATEGORY_MASK);
	this->setPhysicsBody(physicsBody);
	//log("555555555555");
	this->setTag(MONSTER_TAG);
	return true;
}
bool Monster::bindMonsterBulletPhysicsBody(Sprite* bullet)
{
	auto physicsBody = cocos2d::PhysicsBody::createBox(m_monster->getContentSize(), cocos2d::PhysicsMaterial(0.0f, 0.0f, 0.0f));
	physicsBody->setDynamic(false);
	physicsBody->setGravityEnable(false);
	physicsBody->setRotationEnable(false);
	physicsBody->setContactTestBitmask(MONSTER_BULLET_CONTACT_MASK);
	physicsBody->setCategoryBitmask(MOSNTER_BULLET_CATEGORY_MASK);
	bullet->setPhysicsBody(physicsBody);
	//log("6666666666666666");
	return true;
}
void Monster::move()
{
	if (m_monster == nullptr)
		this->unscheduleAllCallbacks();
	if (m_monster != nullptr)
	{
		this->schedule(CC_SCHEDULE_SELECTOR(Monster::updateMove), m_speed);
		this->schedule(CC_SCHEDULE_SELECTOR(Monster::update_circle), 1.0f);
		//this->schedule(CC_SCHEDULE_SELECTOR(Monster::update_animate));
		//runAction(currentAnimate);
		if (redomNum % 3 == 0)
			this->schedule(CC_SCHEDULE_SELECTOR(Monster::update_attack), 2.f);
		//this->schedule(CC_SCHEDULE_SELECTOR(Monster::update_weapon), 0.2f);
		//this->schedule(CC_SCHEDULE_SELECTOR(Monster::update_setViewPointByPlayer));
		//this->setCascadeOpacityEnabled(true);
	}
	else
		return;
}
	

void Monster::updateMove( float delta)
{
	if (m_monster == nullptr)
		return;
	this->setCascadeOpacityEnabled(true);
	if (grassTest())
		this->setOpacity(100);
	else
		this->setOpacity(500);	
	//srand((unsigned)time(NULL)+redomNum);
	if (m_monster != nullptr)
		m_monster->stopAction(currentAnimate);
	srand((unsigned int)setSrand(redomNum) + (unsigned)time(NULL));
	dir = rand() % 4;
	switch (dir)
	{
		case(Direction::left):
		{
			currentAnimate = left_animate;
			//runAction(left_animate);
			offsetX -= 10;

			if (!collisionTest())
			{
				//log("geiyedong");
				auto moveBy = MoveBy::create(m_speed, Vec2(-10, 0));
				//����
				//runAction(moveBy);
				//m_monster->runAction( left_animate);
				this->runAction(moveBy);
				//runAction(currentAnimate);
			}
			else
				offsetX += 10;
			break;
		}
		case(Direction::right):
		{
			currentAnimate = right_animate;
			offsetX += 10;
			//runAction(right_animate);
			if (!collisionTest())
			{
				//log("geiyedong");
				auto moveBy = MoveBy::create(m_speed, Vec2(10, 0));
				//runAction(moveBy);
				//m_monster->runAction(Spawn::create(moveBy,right_animate,NULL));
				//m_monster->runAction(right_animate);
				this->runAction(moveBy);
				//runAction(currentAnimate);
			}
			else
				offsetX -= 10;
			break;
		}
		case(Direction::up):
		{
			currentAnimate = up_animate;
			//runAction(up_animate);
			offsetY += 10;
			if (!collisionTest()) {
				//log("geiyedong");
				auto moveBy = MoveBy::create(m_speed, Vec2(0, 10));
				// runAction(moveBy);
				//m_monster->runAction(up_animate);
				this->runAction(moveBy);
				//m_monster->runAction(Spawn::create(moveBy,up_animate,NULL));
				//runAction(currentAnimate);
			}
			else
				offsetY -= 10;
			break;
		}
		case(Direction::down):
		{
			currentAnimate = down_animate;
			//runAction(down_animate);
			offsetY -= 10;

			if (!collisionTest()) {
				//log("geiyedong");
				auto moveBy = MoveBy::create(m_speed, Vec2(0, -10));
				//runAction(moveBy);
				//m_monster->runAction(up_animate);
				this->runAction(moveBy);
				//m_monster->runAction(Spawn::create(moveBy,down_animate,NULL));
				//runAction(currentAnimate);
			}
			else
				offsetY += 10;

			break;
		}
		default:break;
	}
	
	m_monster->runAction(currentAnimate);
	
}

void Monster::update_attack(float delata)
{
	//Player* player=nullptr;
	Point playerPos;
	////Scene* nowScene = nullptr;
	////////�ȵõ����ڵ㣬�ٴӸ��ڵ��player�ͳ��Լ�֮���monster������
	/*auto runningScene = cocos2d::Director::getInstance()->getRunningScene()->getChildByTag(BATTLE_SCENE);
	Node* playerOfNode = nullptr;
	playerOfNode = getChildByTag(PLAYER_TAG);
	playerOfNode=cocos2d::Director::getInstance()->getRunningScene()->getChildByTag(BATTLE_SCENE)->getChildByTag(MAP_TAG)->getChildByTag(PLAYER_TAG);
	//int num = runningScene->getChildrenCount();*/
	//log("sssssssssssssssss  %d", num);
	////if (playerOfNode != nullptr)
	//{
	//	player = dynamic_cast<Player*>(playerOfNode);
	//	log("ggggggggggggggggggg");
	//	
	//}
	//nowScene= dynamic_cast<Scene*>(runningScene);
	//nowScene->
	//��������Ѿ����ͷţ��Ҳ����ҷ�playerλ�ã�ֱ���˳�
	/*if (player == nullptr)
	{
		log("asfasdfasdf");
		return;
	}*/
	//playerPos = playerOfNode->getPosition();
	//playerPos = m_hero->getOffset();
	
	//log("playerPos::%d,%d", playerPos.x, playerPos.y);
	Point nowPos = this->getPosition();
	srand((unsigned int)setSrand(redomNum) + (unsigned)time(NULL));
	int i = rand() % 9;
	/*if (i % 3 != 0)
		return;*/
	//else
	//{
		playerPos = getRedomPos(redomNum);

		double nowlength = sqrt(pow(playerPos.x - offsetX, 2) + pow(playerPos.y - offsetY, 2));
		double rate = 200 / nowlength;
		const Vec2 route = Vec2((playerPos.x - offsetX) * rate, (playerPos.y - offsetY) * rate);
		auto cache = SpriteFrameCache::getInstance();
		SpriteFrame* spriteframe = nullptr;
		cache->addSpriteFramesWithFile("weapon/fire.plist", "weapon/fire.png");
		//log("weaponcache is done!");
		if (TypeStr == str_1)
		{
			spriteframe =
				SpriteFrameCache::getInstance()->getSpriteFrameByName("fire1.png");
		
		}
		else if (TypeStr == str_2)
		{
			spriteframe =
				SpriteFrameCache::getInstance()->getSpriteFrameByName("fire2.png");
		
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
			m_monster->getPosition());
		
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

	//}
}