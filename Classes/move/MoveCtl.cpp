#include "MoveCtl.h"
#include "MovLR.h"
#include "CheckKeyData.h"

void MoveCtl::AddActMojule(std::string actName, ActMojule & act)
{
	_actMojule.try_emplace(actName, act);
}

std::unique_ptr<OPRT> MoveCtl::ActUpdate(std::string actName, cocos2d::Sprite & sp, std::unique_ptr<OPRT> oprt)
{
	for (auto key : oprt->key())
	{
		
	}
	
	return std::move(oprt);
}
