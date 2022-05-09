#ifndef BattleScene_H_
#define BattleScene_H_

#include<cocos2d.h>
#include<string>
using namespace cocos2d;

class BattleScene : public Scene {
public:
	//���캯��
	BattleScene(std::string mapname);
	//init()����
	virtual bool init();
	//��������BattleScene��
	static BattleScene* create(int testIndx = 1);
	//������������ײ����Scene
	Scene* createScene();
protected:
	TMXTiledMap* battlemap;
	TMXLayer* meta_barrier;
	TMXLayer* meta_grass;
};


#endif // !BattleScene_H_
