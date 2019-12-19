#include "MovFall.h"

bool MovFall::operator()(cocos2d::Sprite & sp, ActMojule & act)
{
	sp.setPosition(sp.getPosition() + act.vec);
	((Obj&)sp).stateName(act.stateName);
	return false;
}
