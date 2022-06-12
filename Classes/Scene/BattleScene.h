#ifndef BattleScene_H_
#define BattleScene_H_

#include<cocos2d.h>
#include<string>
#include"Actor/Player.h"
#include"Actor/Monster.h"
#include "ui/CocosGUI.h"
#include "Const/const.h"
#include "cocostudio\SimpleAudioEngine.h"
using namespace cocos2d;
using namespace CocosDenshion;
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
	void bindPlayermap(Player* _player);
	Monster* bindMonstermap(Monster* _monster,int num);
	void setcircle();//�������ö�Ȧ
		//��������������ĳ�ʼλ��
	std::map<int, Point> initPos;
	void initPosition();
	//��ʼ��monster
	void addPlayer();
	bool onContactBegin(PhysicsContact& contact);
	void initMonster();
	void monsterAttacked(Node* a,Node* b);
	void playerAttacked(Node* a, Node* b);
	bool isCurrentMonsterDie = false;
	bool isCurrentPlayerDie = false;
	Monster* what_monster_is(int);
	bool if_monster_tag(int tag);
	void update_if_die(float);
	bool dead(int tag);
	void update_number(float);
protected:
	TMXTiledMap* battlemap;
	TMXLayer* meta_barrier;
	TMXLayer* meta_grass;
	std::map<int, std::string> _heroPath;
private:
	Player* my_player = nullptr;
	Monster* my_monster[9];
	std::vector<int> monster_tag = { MY_MONSTER_1, MY_MONSTER_2, MY_MONSTER_3,
	MY_MONSTER_4, MY_MONSTER_5, MY_MONSTER_6,
	MY_MONSTER_7, MY_MONSTER_8, MY_MONSTER_9 };
	std::vector<int> die;
	ui::Button* _pauseButton;
	
	/*Monster* my_monster2 = nullptr;
	Monster* my_monster3 = nullptr;
	Monster* my_monster4 = nullptr;
	Monster* my_monster5 = nullptr;
	Monster* my_monster6 = nullptr;
	Monster* my_monster7 = nullptr;
	Monster* my_monster8 = nullptr;
	Monster* my_monster9 = nullptr;*/
	int maxMonsterNum = 9;
	int currentMonsterNum = 0;
	int redomPos[10] = { 0 };
	Label* label;
};


#endif // !BattleScene_H_
