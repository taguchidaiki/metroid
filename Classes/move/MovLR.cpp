#include "MovLR.h"

bool MovLR::operator()(cocos2d::Sprite& sp, ActMojule& act)
{
	//sp.runAction(cocos2d::MoveBy::create(1/60.0f,/*Vec2::移動ベクトル * float::移動量要はスピード？*/));
	sp.setPosition(sp.getPosition() + static_cast<Obj&>(sp).speed() * act.vec);
	return true;
}