#include "MoveCtl.h"
#include "MovLR.h"
#include "MovIdle.h"
#include "CheckKeyData.h"

void MoveCtl::AddActMojule(std::string actName, ActMojule & act)
{
	_actList.try_emplace(actName, act);
}

std::unique_ptr<OPRT> MoveCtl::ActUpdate(std::string actName, cocos2d::Sprite & sp, std::unique_ptr<OPRT> oprt)
{
	static_cast<Obj&>(sp).act(_actList.at(actName));

	for (auto keyData : oprt->key())
	{
		for (auto key : static_cast<Obj&>(sp).act().keyList)
		{
			if (keyData == key)
			{
				int i = 0;
			}
		}
	}
	
	return std::move(oprt);
}
