#ifndef BattleScene_H_
#define BattleScene_H_

#include<cocos2d.h>
#include<string>
#include"Actor/Player.h"
#include"Actor/Monster.h"
#include "ui/CocosGUI.h"
#include "Const/const.h"
using namespace cocos2d;

class BattleScene : public Scene {
public:
	//���캯��
	BattleScene(std::string mapname);
	//init()����
	virtual bool init();
	virtual void initUI();
	//��������BattleScene��
	static BattleScene* create(int testIndx = 1);
	//������������ײ����Scene
	Scene* createScene(std::map<int, std::string> heroPath);
	void bindPlayer(Player* _player);
	void bindBullet(Player* _bullet);
	Monster* bindMonster(Monster* _monster,int num);
	void setcircle();//�������ö�Ȧ
		//��������������ĳ�ʼλ��
	std::map<int, Point> initPos;
	void initPosition();
	//��ʼ��monster
	bool onContactBegin(PhysicsContact& contact);
	void initMonster(float dealt);
	void monsterAttacked(Node* a,Node* b);
	void playerAttacked(Node* a, Node* b);
	bool isCurrentMonsterLive = true;
	bool isCurrentPlayerLive = true;

protected:
	TMXTiledMap* battlemap;
	TMXLayer* meta_barrier;
	TMXLayer* meta_grass;
	std::map<int, std::string> _heroPath;
private:
	Player* my_player = nullptr;
	Monster* my_monster[9] = {nullptr};
	ui::Button* _pauseButton;
	Player* my_bullet = nullptr;
	/*Monster* my_monster2 = nullptr;
	Monster* my_monster3 = nullptr;
	Monster* my_monster4 = nullptr;
	Monster* my_monster5 = nullptr;
	Monster* my_monster6 = nullptr;
	Monster* my_monster7 = nullptr;
	Monster* my_monster8 = nullptr;
	Monster* my_monster9 = nullptr;*/
	int maxMonsterNum = 1;
	int currentMonsterNum = 0;
	int redomPos[10] = { 0 };
};


#endif // !BattleScene_H_
