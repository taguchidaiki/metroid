#include "MovLR.h"

bool MovLR::operator()(cocos2d::Sprite& sp, ActMojule& act)
{
	sp.setPosition(sp.getPosition() + ((Obj&)sp).speed() * act.vec);
	((Obj&)sp).stateName(act.stateName);
	return true;
}