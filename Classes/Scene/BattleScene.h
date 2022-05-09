#ifndef BattleScene_H_
#define BattleScene_H_

#include<cocos2d.h>
#include<string>
using namespace cocos2d;

class BattleScene : public Scene {
public:
	//构造函数
	BattleScene(std::string mapname);
	//init()函数
	virtual bool init();
	//用来创建BattleScene类
	static BattleScene* create(int testIndx = 1);
	//用来将物理碰撞引入Scene
	Scene* createScene();
protected:
	TMXTiledMap* battlemap;
	TMXLayer* meta_barrier;
	TMXLayer* meta_grass;
};


#endif // !BattleScene_H_
