#include"MyAnimation.h"

USING_NS_CC;

Animate* MyAnimation::creatHeroWalkAnimation(int hero_type, const char* direction,  int num,int loop )
{
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	
	char strPlistName[100], strPhotoName[100];
	sprintf(strPlistName, "Scene/hero/res/Hero%d%s.plist",hero_type,direction);
	sprintf(strPhotoName, "Scene/hero/res/Hero%d%s.png", hero_type, direction);

	cache->addSpriteFramesWithFile(strPlistName);
	
	Vector<SpriteFrame*> frameVec;
	SpriteFrame* frame = NULL;
	for (int ix = 1; ix <= num; ix++)
	{
		frame = cache->getSpriteFrameByName(StringUtils::format("Scene/hero/Hero%d_%s_%d.png",hero_type , direction, ix));
		if (frame == NULL)
			break;

		frameVec.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(frameVec,0.2f/4);
	Animate* myAnimate = Animate::create(animation);
	return myAnimate;
}