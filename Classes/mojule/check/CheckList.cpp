#include "CheckList.h"
#include "unit/Obj.h"

bool CheckList::operator()(cocos2d::Sprite& sp, ActMojule& act)
{
	for (auto list : act.blackList)
	{
		if (((Obj&)sp).act().stateID == list)
		{
			return false;
		}
	}
	
	for (auto list : act.whiteList)
	{
		if (((Obj&)sp).act().stateID == list)
		{
			return true;
		}
	}
	
	return false;
}
