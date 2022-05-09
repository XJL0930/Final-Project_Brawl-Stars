#include"BattleScene.h"
#include "HeroMove.h"

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
		return scene;
	}
	return nullptr;
}

BattleScene::BattleScene(std::string mapname/*还要继续加入人物类的data member的初始化*/) {
	battlemap=TMXTiledMap::create(mapname);

	this->meta_barrier = battlemap->getLayer("meta_barrier");
	this->meta_barrier->setVisible(false);
	this->meta_grass = battlemap->getLayer("meta_grass");
	this->meta_grass->setVisible(false);
	HeroMove::createHero();
};
