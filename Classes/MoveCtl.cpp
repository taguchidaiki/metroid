#include "MoveCtl.h"
#include "unit/Obj.h"
#include "MojuleHeader.h"

void MoveCtl::AddActMojule(std::string actName, ActMojule & act)
{
	if (_actList.find(actName) == _actList.end())
	{
		_actList.emplace(actName, act);
	}
	//_actList.try_emplace(actName, act);
}

bool MoveCtl::SetActState(cocos2d::Sprite& sp, ActMojule& actData, std::weak_ptr<OPRT> oprt)
{
	actData = _actList["player-idle"];

	for (auto keyData : oprt.lock()->key())
	{
		for (auto act : _actList)
		{
			if (act.second.keyData == keyData)
			{
				actData = act.second;
			}
		}
	}
	return true;
}

void MoveCtl::ActUpdate(cocos2d::Sprite & sp, ActMojule& actData)
{
	auto checkList = [&](){
		for (auto list: actData.actionList)
		{
			if (!list)
			{
				return false;
			}
		}
		return true;
	};
	
	for (auto act : actData.actionList)
	{
		if (checkList())
		{
			actData.runAction(sp, actData);
		}
	}

}
