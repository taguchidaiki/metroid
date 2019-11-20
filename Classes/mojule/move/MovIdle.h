#pragma once
#include "MoveCtl.h"

struct MovIdle
{
	bool operator()(cocos2d::Sprite& sp, ActMojule& act);
};