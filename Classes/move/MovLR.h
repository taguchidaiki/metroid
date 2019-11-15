#pragma once
#include "MoveCtl.h"

struct MovLR{
	bool operator()(cocos2d::Sprite& sp, ActMojule& act);
};