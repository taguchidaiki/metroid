#include "MoveCtl.h"
#include "MovLR.h"

void MoveCtl::AddActMojule(std::string actName, ActMojule & act)
{
	_actMojule.try_emplace(actName, act);
}

void MoveCtl::ActUpdate(std::string actName, cocos2d::Sprite & sp)
{
	MovLR()(sp, _actMojule[actName]);
}
