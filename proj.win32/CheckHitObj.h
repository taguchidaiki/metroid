#pragma once
#include "move/MoveCtl.h"

struct CheckHitObj {
	bool operator()(cocos2d::Sprite& sp, ActMojule& act);
};

