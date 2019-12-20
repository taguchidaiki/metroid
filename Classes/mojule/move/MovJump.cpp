#include "MovJump.h"

bool MovJump::operator()(cocos2d::Sprite & sp, ActMojule & act)
{
	sp.setPosition(sp.getPosition() + ((Obj&)sp).speed() * act.vec - ((Obj&)sp).gravity());
	lpSoundCtl.PlaySoundData("maougan", SND_PTN::SE);
	((Obj&)sp).stateName(act.stateName);

	((Obj&)sp).gravity(cocos2d::Vec2(0,((Obj&)sp).gravity().y + 1));
	if (((Obj&)sp).gravity().y >= ((Obj&)sp).speed() * act.vec.y)
	{
		auto string = ((Obj&)sp).stateName();
		if (((Obj&)sp).stateName() == "player-jump-l")
		{
			((Obj&)sp).stateName("player-fall-l");
		}
		else
		{
			((Obj&)sp).stateName("player-fall-r");
		}
		
		((Obj&)sp).gravity(cocos2d::Vec2(0, -1));
	}
	return true;
}
