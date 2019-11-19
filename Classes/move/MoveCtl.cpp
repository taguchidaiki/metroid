#include "MoveCtl.h"
#include "MovLR.h"
#include "MovIdle.h"
#include "CheckKeyData.h"

void MoveCtl::AddActMojule(std::string actName, ActMojule & act)
{
	_actList.try_emplace(actName, act);
}

bool MoveCtl::SetActState(cocos2d::Sprite& sp, std::weak_ptr<OPRT> oprt)
{
	for (auto keyData : oprt.lock()->key())
	{
		for (auto actData : _actList)
		{
			if (actData.second.keyData == keyData)
			{
				static_cast<Obj&>(sp).act(actData.second);
			}
		}
	}
	return true;
}

void MoveCtl::ActUpdate(std::string actName, cocos2d::Sprite & sp, std::weak_ptr<OPRT> oprt)
{
	//static_cast<Obj&>(sp).act(_actList.at(actName));

	
	
}
