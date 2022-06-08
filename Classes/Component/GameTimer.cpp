#include "GameTimer.h"

GameTimer::GameTimer()
{

}

GameTimer::~GameTimer()
{

}

bool GameTimer::init(float time)
{
	pTime = time;

	label = Label::createWithSystemFont(" ","fonts/arial.ttf",70.0f);
	label->setPosition(0, 0);

	this->addChild(label);

	schedule(CC_SCHEDULE_SELECTOR(GameTimer::update));

	return true;
}
void GameTimer::update(float delta)
{
	pTime -= delta;
	char* mtime = new char[10];
	//�˴�ֻ����ʾ������������  �Լ����Զ������ʱ���ʽ
	sprintf(mtime, "%d : %d", (int)pTime / 60, (int)pTime % 60);
	label->setString(mtime);
}

GameTimer* GameTimer::createTimer(float time)
{
	GameTimer* gametimer = new GameTimer;
	if (gametimer && gametimer->init(time))
	{
		gametimer->autorelease();
		return gametimer;
	}
	else
	{
		delete gametimer;
		gametimer = NULL;
	}
	return NULL;
}