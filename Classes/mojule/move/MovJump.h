#pragma once
#include "MoveCtl.h"
#include "unit/Obj.h"

struct MovJump {
	bool operator()(cocos2d::Sprite& sp, ActMojule& act);
};