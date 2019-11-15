#include "MovIdle.h"

bool MovIdle::operator()()
{
	return false;
}

bool MovIdle::operator()(cocos2d::Sprite & sp, ActMojule & act)
{
	return false;
}
