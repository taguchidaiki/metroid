#include "CheckHitObj.h"
#include "unit/Obj.h"

bool CheckHitObj::operator()(cocos2d::Sprite& sp, ActMojule& act)
{
	auto director = cocos2d::Director::getInstance();
	auto hitScene = (cocos2d::TMXTiledMap*)director->getRunningScene()->getChildByName("hitObj")->getChildByName("map");
	auto hitNode = hitScene->getLayer("field");

	auto i = hitNode->getLayerSize().height;
	auto vec = cocos2d::Vec2((((Obj&)sp).getPosition().x) / hitNode->getMapTileSize().width,
		(hitNode->getLayerSize().height - ((Obj&)sp).getPosition().y - act.hitRect.y / 2) / hitNode->getMapTileSize().height);

	int x = (((Obj&)sp).getPosition().x) / hitNode->getMapTileSize().width;
	int y = (hitNode->getLayerSize().height - ((Obj&)sp).getPosition().y - act.hitRect.y / 2) / hitNode->getMapTileSize().height;
	auto checkUnder = (cocos2d::TMXTiledMap*)hitNode->getTileAt(cocos2d::Vec2((((Obj&)sp).getPosition().x) / hitNode->getMapTileSize().width,
																			  (hitNode->getMapTileSize().height - ((Obj&)sp).getPosition().y - act.hitRect.y / 2) / hitNode->getMapTileSize().height));

	if (checkUnder != nullptr)
	{
		auto pos = checkUnder->getPosition().y + hitNode->getMapTileSize().height / 2;
		((Obj&)sp).setPositionY(checkUnder->getPosition().y + hitNode->getMapTileSize().height / 2);
	}

	if (((Obj&)sp).getPosition().y - act.hitRect.y / 2 <= 0)
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
	}

	return true;
}
