#include "MovLR.h"

bool MovLR::operator()(cocos2d::Sprite& sp, ActMojule& act)
{
	//sp.runAction(cocos2d::MoveBy::create(1/60.0f,/*Vec2::�ړ��x�N�g�� * float::�ړ��ʗv�̓X�s�[�h�H*/));
	sp.setPosition(sp.getPosition() + ((Obj&)sp).speed() * act.vec);
	((Obj&)sp).stateName(act.stateName);
	return true;
}