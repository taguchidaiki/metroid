#pragma once
#include "MoveCtl.h"

struct MovJump {
	bool operator()(cocos2d::Sprite& sp, ActMojule& act);
};