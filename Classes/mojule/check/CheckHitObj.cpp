#include "CheckHitObj.h"
#include "unit/Obj.h"

bool CheckHitObj::operator()(cocos2d::Sprite& sp, ActMojule& act)
{
	auto director = cocos2d::Director::getInstance();
	auto hitScene = (cocos2d::TMXTiledMap*)director->getRunningScene()->getChildByName("hitObj")->getChildByName("map");
	auto hitNode = hitScene->getLayer("field");

	//プレイヤーの真下の位置情報
	auto hitRectData = cocos2d::Rect(((Obj&)sp).getPosition().x - act.hitRect.x / 2, ((Obj&)sp).getPosition().y + act.hitRect.y / 2, act.hitRect.x,act.hitRect.y);

	auto hitPos = cocos2d::Vec2(((Obj&)sp).getPosition().x, ((Obj&)sp).getPosition().y - act.hitRect.y / 2);
	
	//真下のタイル位置の情報
	auto tileNum = cocos2d::Vec2(hitPos.x / hitNode->getMapTileSize().width,
								 hitNode->getLayerSize().height - hitPos.y / hitNode->getMapTileSize().height);
	auto tileData = (cocos2d::TMXTiledMap*)hitNode->getTileAt(cocos2d::Vec2((int)tileNum.x,
																			(int)tileNum.y));

	if (tileData != nullptr)
	{
		((Obj&)sp).setPositionY(act.hitRect.y / 2 + tileData->getPosition().y + hitNode->getMapTileSize().height);
		((Obj&)sp).stateName("player-idle-r");
	}
	else
	{
		//((Obj&)sp).stateName("player-fall-r");
	}

	/*if (((Obj&)sp).getPosition().y - act.hitRect.y / 2 <= 0)
	{
		((Obj&)sp).setPosition(cocos2d::Vec2(((Obj&)sp).getPosition().x, act.hitRect.y / 2));
		if (((Obj&)sp).stateName() == "player-jump-l")
		{
			((Obj&)sp).stateName("player-idle-l");
		}
		else
		{
			((Obj&)sp).stateName("player-idle-r");
		}
	}*/

	return true;
}
