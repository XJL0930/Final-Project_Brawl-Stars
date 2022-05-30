#include"MyAnimate.h"

USING_NS_CC;

Animate* MyAnimate::creatHeroAnimate(int hero_type, const char* direction,  int num,int loop )
{
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	
	char strPlistName[100];
		sprintf(strPlistName, "hero/hero%d%s.plist",hero_type,direction);
	log(strPlistName);
	cache->addSpriteFramesWithFile(strPlistName);
	
	Vector<SpriteFrame*> frameVec;
	SpriteFrame* frame = NULL;
	for (int ix = 1; ix <= num; ix++)
	{
		frame = cache->getSpriteFrameByName(StringUtils::format("Hero%d_%s_%d.png", hero_type, direction, ix));
		if (frame == NULL)
			break;

		frameVec.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(frameVec,0.2f/4);
	animation->setLoops(-1);
	Animate* myAnimate = Animate::create(animation);
	myAnimate->retain();
	return myAnimate;
}
Animate* MyAnimate::creatWeaponAnimate(const char* plistName, const char* pngName, int loop)
{
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	char plistpath[30];
	sprintf(plistpath, "weapon/%s.plist", plistName);
	cache->addSpriteFramesWithFile(plistpath);
	Vector<SpriteFrame*> frameVec;
	char picName[30];
	for (int i = 1; i <= 5; i++)
	{
		sprintf(picName, "%s%d.png", pngName, i);
		frameVec.pushBack(cache->getSpriteFrameByName(picName));
	}
	Animation* animation = Animation::createWithSpriteFrames(frameVec, 0.2f / 4);
	Animate* myAnimate = Animate::create(animation);
	return myAnimate;
}