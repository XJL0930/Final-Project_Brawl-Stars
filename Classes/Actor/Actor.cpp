#include "Actor.h"

Actor* Actor::create()
{
    Actor* pRet = new (std::nothrow) Actor();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return nullptr;
    }
}

bool Actor::init()
{
    // Actor的初始化需要初始化参数，包括初始化血量，宝石个数...
    return false;
}

bool Actor::isAttack()
{
    return false;
}
