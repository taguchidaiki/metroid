#include "MoveCtl.h"
#include "MovLR.h"
#include "CheckKeyData.h"

void MoveCtl::AddActMojule(std::string actName, ActMojule & act)
{
	_actList.try_emplace(actName, act);
}

std::unique_ptr<OPRT> MoveCtl::ActUpdate(std::string actName, cocos2d::Sprite & sp, std::unique_ptr<OPRT> oprt)
{
	for (auto key : oprt->key())
	{
		for (auto actData : _actList)
		{
			
		}
		//static_cast<Obj&>(sp).act();
	}
	
	return std::move(oprt);
}
