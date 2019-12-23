#include "MovJump.h"

bool MovJump::operator()(cocos2d::Sprite & sp, ActMojule & act)
{
	sp.setPosition(sp.getPosition() + ((Obj&)sp).speed() * act.vec - ((Obj&)sp).gravity());
	lpSoundCtl.PlaySoundData("maougan", SND_PTN::SE);
	lpEffectCtl.AddEmitter("Laser01",sp,1.0f,cocos2d::Vec3(90,0,0), cocos2d::Vec2(120,30),cocos2d::Vec3(120, -128,0));
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
