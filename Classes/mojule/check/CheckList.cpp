#include "CheckList.h"
#include "unit/Obj.h"

bool CheckList::operator()(cocos2d::Sprite& sp, ActMojule& act)
{
	for (auto list : lpMoveCtl.GetActData(((Obj&)sp).stateName()).blackList)
	{
		if (act.stateID == list)
		{
			return false;
		}
	}
	
	for (auto list : lpMoveCtl.GetActData(((Obj&)sp).stateName()).whiteList)
	{
		if (act.stateID == list)
		{
			return true;
		}
	}
	
	return false;
}
