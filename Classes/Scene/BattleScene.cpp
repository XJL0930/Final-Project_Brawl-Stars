#include"BattleScene.h"
#include "Actor\Player.h"
#include "Hero\Hero.h"
#include "Actor\Role.h"

BattleScene* BattleScene::create(int testIndex /* = 1 */)
{
	switch (testIndex){
	    case 1:{
		    auto scene = new(std::nothrow) BattleScene("Scene/desert_map/desert_map.tmx");
		    if (scene && scene->init())
		    {
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
		this->bindPlayer(Player::create("hero/hero1_begin.png"));
		my_player->move();

		return scene;
	}
	return nullptr;
}
 
void BattleScene::bindPlayer(Player* _player)
{
	if (_player != nullptr && my_player == nullptr)
	{
		_player->m_map = battlemap;
		_player->meta_barrier = meta_barrier;
		_player->meta_grass = meta_grass;

		this->my_player = _player;
		battlemap->addChild(my_player);
	}
}


BattleScene::BattleScene(std::string mapname/*还要继续加入人物类的data member的初始化*/) {
	battlemap=TMXTiledMap::create(mapname);

	this->meta_barrier = battlemap->getLayer("meta_barrier");
	this->meta_barrier->setVisible(false);
	this->meta_grass = battlemap->getLayer("meta_grass");
	this->meta_grass->setVisible(false);
};
