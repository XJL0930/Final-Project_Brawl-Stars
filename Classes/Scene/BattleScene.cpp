#include"BattleScene.h"
#include "Actor\Player.h"
#include "Hero\Hero.h"
#include "Actor\Role.h"
#include"Const/const.h"
#define MAXMONSTER 10

BattleScene* BattleScene::create(int testIndex /* = 1 */)
{
	switch (testIndex){
	    case 1:{
		    auto scene = new(std::nothrow) BattleScene("Scene/desert_map/desert_map.tmx");
		    if (scene && scene->init())
		    {
				//scene->retain();
			    scene->autorelease();
			    return scene;
		    }
		    else
		    {
			    delete scene;
			    scene = nullptr;
			    return nullptr;
		    }
		    break;
	    }
	    default:
			break;
	}
	return nullptr;
}

bool BattleScene::init()
{
	if (!(this->Scene::init() && this->Scene::initWithPhysics()))
		return false;
	//this->setTag(0);
	this->setTag(BATTLE_SCENE);
	this->addChild(battlemap,0);
	return true;
}

Scene* BattleScene::createScene()
{
	auto scene = Scene::createWithPhysics();

	if (scene != nullptr)
	{
		scene->addChild(this, 0);
		scene->getPhysicsWorld()->setAutoStep(true);
		scene->getPhysicsWorld()->setGravity(cocos2d::Vec2::ZERO);
		scene->retain();
		
		this->setcircle();
		this->bindPlayer(Player::create("hero/hero1_begin.png"));
	
		my_player->move();
		BattleScene::initPosition();
		this->schedule(CC_SCHEDULE_SELECTOR(BattleScene::initMonster));
		auto contactListener = EventListenerPhysicsContact::create();
		contactListener->onContactBegin = CC_CALLBACK_1(BattleScene::onContactBegin, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
		return scene;
	}
	return nullptr;
}
 
void BattleScene::bindPlayer(Player* _player)
{
	if (_player != nullptr && my_player == nullptr)
	{
		_player->bind_map(battlemap, meta_barrier, meta_grass);

		this->my_player = _player;
		
		battlemap->addChild(my_player,3,PLAYER_TAG);
		
	}
}

Monster* BattleScene::bindMonster(Monster* _monster,int num)
{
	if (_monster != nullptr && my_monster[num] == nullptr)
	{
		_monster->bind_map(battlemap, meta_barrier, meta_grass);

		this->my_monster[num] =_monster ;
		battlemap->addChild(my_monster[num]);
		
	}
	return _monster;
}
BattleScene::BattleScene(std::string mapname/*还要继续加入人物类的data member的初始化*/) {
	battlemap=TMXTiledMap::create(mapname);

	this->meta_barrier = battlemap->getLayer("meta_barrier");
	this->meta_barrier->setVisible(false);
	this->meta_grass = battlemap->getLayer("meta_grass");
	this->meta_grass->setVisible(false);
	battlemap->setTag(MAP_TAG);
};

void BattleScene::setcircle()
{
	Sprite* line1 = Sprite::create("line1.png");
	Sprite* line2 = Sprite::create("line2.png");
	Sprite* line3 = Sprite::create("line1.png");
	Sprite* line4 = Sprite::create("line2.png");
	line1->setScaleY(3);
	line2->setScaleX(3);
	line3->setScaleY(3);
	line4->setScaleX(3);
	line1->setPosition(3, 800);
	line3->setPosition(1597, 800);
	line2->setPosition(800, 3);
	line4->setPosition(800, 1597);
	battlemap->addChild(line1, 4);
	battlemap->addChild(line2, 4);
	battlemap->addChild(line3, 4);
	battlemap->addChild(line4, 4);
	auto moveto1 = MoveTo::create(180, Vec2(700, 700));
	auto scaleto1 = ScaleTo::create(180, 0.0f, 0.0f);
	line1->runAction(Spawn::createWithTwoActions(moveto1, scaleto1));
	auto moveto2 = MoveTo::create(180, Vec2(700, 700));
	auto scaleto2 = ScaleTo::create(180, 0.0f, 0.0f);
	line2->runAction(Spawn::createWithTwoActions(moveto2, scaleto2));
	auto moveto3 = MoveTo::create(180, Vec2(700, 700));
	auto scaleto3 = ScaleTo::create(180, 0.0f, 0.0f);
	line3->runAction(Spawn::createWithTwoActions(moveto3, scaleto3));
	auto moveto4 = MoveTo::create(180, Vec2(700, 700));
	auto scaleto4 = ScaleTo::create(180, 0.0f, 0.0f);
	line4->runAction(Spawn::createWithTwoActions(moveto4, scaleto4));
	return;
}
void BattleScene::initPosition()
{
	initPos[1] = Point(1471, 1430);
	initPos[2] = Point(1458, 1006);
	initPos[3] = Point(1440, 654);
	initPos[4] = Point(1474, 110);
	initPos[5] = Point(957, 150);
	initPos[6] = Point(149, 92);
	initPos[7] = Point(166, 645);
	initPos[8] = Point(128, 1129);
	initPos[9] = Point(142, 1550);
	initPos[10] = Point(917, 1374);
	//产生那十个位置的随机值
	srand((unsigned)time(NULL));
	for (int i = 0; i < maxMonsterNum; ++i)
	{
		redomPos[i] = rand() % 10+1;
		for(int j=0;j<i;++j)
		{
			if (redomPos[j] == redomPos[i])
			{
				redomPos[i] = rand() % MAXMONSTER+1;
				continue;
			}
		}
		log("redomPos::%d", redomPos[i]);
	}
	return;
}
void BattleScene::initMonster(float dealt)
{
	//因为要生成最多10个monster，所以直接设置为更新函数，而不是用for循环
	if (currentMonsterNum < maxMonsterNum)
	{
		//log("has been going");
		Monster* _monster = nullptr;
		_monster=this->bindMonster(Monster::create("hero/hero1_begin.png", maxMonsterNum,
			initPos[redomPos[currentMonsterNum]], currentMonsterNum),currentMonsterNum);
		log("zhsooihawoefklsdfl");
		//此处应该是做一个switch的英雄选择函数
		if (_monster != nullptr)
		{
			
		    _monster->move();
			log("Point::%f,%f",_monster->getPosition().x, _monster->getPosition().y);
		}
		/*else
			return;*/
		++currentMonsterNum;
	}
}
bool BattleScene::onContactBegin(PhysicsContact& contact)
{
	int node = getTag();
	log(",,,,,,,,,,,,%d,%d", MONSTER_TAG,PLAYER_TAG);
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();
	if (nodeA && nodeB)
	{
		int tagA = nodeA->getTag();
		int tagB = nodeB->getTag();
		log("onContact!! tagA = %d, tagB = %d", tagA, tagB);
		if ((nodeA->getTag() == PLAYER_BULLET_TAG || nodeA->getTag() == MONSTER_BULLET_TAG)
			&& (nodeB->getTag() == PLAYER_BULLET_TAG || nodeB->getTag() == MONSTER_BULLET_TAG)) {
			nodeB->removeFromParentAndCleanup(true);
			nodeA->removeFromParentAndCleanup(true);
		}
		if ((tagA == MONSTER_TAG || tagB == MONSTER_TAG) )
		{
			
			monsterAttacked(nodeA, nodeB);
		}
		if (tagA == PLAYER_TAG || tagB == PLAYER_TAG)
		{
			
			playerAttacked(nodeA, nodeB);
		}
			

		// 当player的飞镖碰到敌人或者敌人的飞镖，将它们杀死
	   /* if ((nodeA->getTag() == PLAYER_TAG || nodeA->getTag() == MONSTER_TAG)
			&& (nodeB->getTag() == PLAYER_BULLET_TAG || nodeB->getTag() == MONSTER_BULLET_TAG)) {
			nodeA->removeFromParentAndCleanup(true);
			nodeB->removeFromParentAndCleanup(true);
		}*/
		//如果是二者的飞镖相遇，则两个直接都消失。
		
	}
	return true;
}
void BattleScene::monsterAttacked(Node* a, Node* b)
{
	
	isCurrentMonsterLive = false;
	--maxMonsterNum;
	a->removeFromParentAndCleanup(true);
	b->removeFromParentAndCleanup(true);
	log("ooooooooooooooooooo");
	if (maxMonsterNum == 0)
	{

		//Direction::结束画面。
	}
	isCurrentMonsterLive = true;
}
void BattleScene::playerAttacked(Node* a, Node* b)
{
	
	isCurrentPlayerLive = false;
	
		if (!isCurrentMonsterLive)
		{
			a->removeFromParentAndCleanup(true);
			b->removeFromParentAndCleanup(true);
			log("ooooooooooooooooooo");
			//Direction::结束画面。
		}
		
	isCurrentMonsterLive = true;
}