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
		my_player->setPosition(200, 300);
		this->addChild(my_player);
		my_player->move();
		return scene;
	}
	return nullptr;
}
 
void BattleScene::bindPlayer(Player* _player)
{
	my_player = _player;
	if (_player == nullptr && my_player == nullptr)
	{
		my_player = _player;
		my_player->setPosition(200, 300);
		//this->addChild(my_player);
	}
}


BattleScene::BattleScene(std::string mapname/*��Ҫ���������������data member�ĳ�ʼ��*/) {
	battlemap=TMXTiledMap::create(mapname);

	this->meta_barrier = battlemap->getLayer("meta_barrier");
	this->meta_barrier->setVisible(false);
	this->meta_grass = battlemap->getLayer("meta_grass");
	this->meta_grass->setVisible(false);
	//HeroMove::createHero();
	//my_player->bind_hero();
	my_player = my_player->create("hero/Hero1_left.png");
	//bindPlayer(my_player->create("Scene/hero/Hero1.png"));
};
