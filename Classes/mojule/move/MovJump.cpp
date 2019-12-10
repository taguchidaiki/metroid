#include "MovJump.h"

bool MovJump::operator()(cocos2d::Sprite & sp, ActMojule & act)
{
	sp.setPosition(sp.getPosition() + ((Obj&)sp).speed() * act.vec - ((Obj&)sp).gravity());
	lpSoundCtl.PlaySoundData("maougan", SND_PTN::SE);

	((Obj&)sp).gravity(cocos2d::Vec2(0,((Obj&)sp).gravity().y + 1));
	if (((Obj&)sp).gravity().y >= ((Obj&)sp).speed() * act.vec.y)
	{
		((Obj&)sp).gravity(cocos2d::Vec2(0, -1));
	}
	return true;
}
