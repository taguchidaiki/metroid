#include "MovIdle.h"

bool MovIdle::operator()(cocos2d::Sprite & sp, ActMojule & act)
{
	((Obj&)sp).stateName(act.stateName);
	return false;
}
