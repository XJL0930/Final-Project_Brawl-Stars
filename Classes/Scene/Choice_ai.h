
#ifndef __CHOICE_AI_H__
#define __CHOICE_AI_H__
#include "cocos2d.h"
USING_NS_CC;
class ChoiceAI : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    //std::string heropath;
    std::vector<Sprite*> playervec;
    //std::map<int, bool> buttonmap;
    std::map<int, std::string> heroPath;
    Sprite* nowButton;
    void nextone();
    virtual bool init();

    // a selector callback
    void menuEnterCallback();
    Label* enter = Label::createWithTTF("Play", "fonts/arial.ttf", 40);
    //void touchlisten(Label* label);
    // implement the "static create()" method manually
    CREATE_FUNC(ChoiceAI);
};

#endif // __CHOICE_AI_H__
