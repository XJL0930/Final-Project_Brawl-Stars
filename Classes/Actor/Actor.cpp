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
    // Actor�ĳ�ʼ����Ҫ��ʼ��������������ʼ��Ѫ������ʯ����...
    return false;
}

bool Actor::isAttack()
{
    return false;
}
