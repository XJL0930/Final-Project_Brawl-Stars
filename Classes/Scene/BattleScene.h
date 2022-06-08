#ifndef BattleScene_H_
#define BattleScene_H_

#include<cocos2d.h>
#include<string>
#include"Actor\Player.h"
#include"Component/GameTimer.h"
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
	void bindPlayer(Player* _player);
	void setcircle();//�������ö�Ȧ
protected:
	TMXTiledMap* battlemap;
	TMXLayer* meta_barrier;
	TMXLayer* meta_grass;
private:
	Player* my_player=nullptr;
};


#endif // !BattleScene_H_
