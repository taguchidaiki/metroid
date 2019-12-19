#include "CheckHitObj.h"
#include "unit/Obj.h"

bool CheckHitObj::operator()(cocos2d::Sprite& sp, ActMojule& act)
{
	if (((Obj&)sp).getPosition().y - act.hitRect.y / 2 <= 0)
	{
		((Obj&)sp).setPosition(cocos2d::Vec2(((Obj&)sp).getPosition().x, act.hitRect.y / 2));
		if (((Obj&)sp).stateName() == "player-jump-l")
		{
			((Obj&)sp).stateName("player-idle-l");
		}
		else
		{
			((Obj&)sp).stateName("player-idle-r");
		}
	}

	return true;
}
