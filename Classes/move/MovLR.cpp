#include "MovLR.h"
#include "MoveCtl.h"

bool MovLR::operator()(cocos2d::Sprite& sp, ActMojule& act)
{
	//sp.runAction(cocos2d::MoveBy::create(1/60.0f,/*Vec2::�ړ��x�N�g�� * float::�ړ��ʗv�̓X�s�[�h�H*/));
	sp.setPosition(sp.getPosition() + static_cast<Obj&>(sp).speed() * cocos2d::Vec2(1,0));
	return false;
}