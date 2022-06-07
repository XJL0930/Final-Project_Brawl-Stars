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
		this->setcircle();
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
		battlemap->addChild(my_player,3);
	}
}

BattleScene::BattleScene(std::string mapname/*还要继续加入人物类的data member的初始化*/) {
	battlemap=TMXTiledMap::create(mapname);

	this->meta_barrier = battlemap->getLayer("meta_barrier");
	this->meta_barrier->setVisible(false);
	this->meta_grass = battlemap->getLayer("meta_grass");
	this->meta_grass->setVisible(false);
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
