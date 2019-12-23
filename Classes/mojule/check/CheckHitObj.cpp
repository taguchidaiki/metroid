#include "CheckHitObj.h"
#include "unit/Obj.h"

bool CheckHitObj::operator()(cocos2d::Sprite& sp, ActMojule& act)
{

	auto hitScene = (cocos2d::TMXTiledMap*)cocos2d::Director::getInstance()->getRunningScene()->getChildByName("hitObj")->getChildByName("map");
	auto hitNode = hitScene->getLayer("field");

	//プレイヤーの当たり判定矩形の位置情報(左下の座標、矩形の大きさ)
	auto hitRectData = cocos2d::Rect(((Obj&)sp).getPosition().x - act.hitRect.x / 2, ((Obj&)sp).getPosition().y - act.hitRect.y / 2, act.hitRect.x, act.hitRect.y);

	char lr = ((Obj&)sp).stateName().back();
	std::pair<cocos2d::TMXTiledMap*, cocos2d::TMXTiledMap*> tileData;
	std::pair<cocos2d::Vec2, cocos2d::Vec2> tileNum;
	
	if (lr == 'r')
	{
		tileNum.first = cocos2d::Vec2(hitRectData.getMaxX() / hitNode->getMapTileSize().width, hitNode->getLayerSize().height - hitRectData.getMidY() / hitNode->getMapTileSize().height);
		tileNum.second = cocos2d::Vec2(hitRectData.getMaxX() / hitNode->getMapTileSize().width, hitNode->getLayerSize().height - hitRectData.getMinY() / hitNode->getMapTileSize().height);
	}
	else
	{
		tileNum.first = cocos2d::Vec2(hitRectData.getMinX() / hitNode->getMapTileSize().width, hitNode->getLayerSize().height - hitRectData.getMidY() / hitNode->getMapTileSize().height);
		tileNum.second = cocos2d::Vec2(hitRectData.getMinX() / hitNode->getMapTileSize().width, hitNode->getLayerSize().height - hitRectData.getMinY() / hitNode->getMapTileSize().height);
	}

	tileData.first = (cocos2d::TMXTiledMap*)hitNode->getTileAt(cocos2d::Vec2((int)tileNum.first.x, (int)tileNum.first.y));
	tileData.second = (cocos2d::TMXTiledMap*)hitNode->getTileAt(cocos2d::Vec2((int)tileNum.second.x, (int)tileNum.second.y));

	if (tileData.first != nullptr && lr == 'r')
	{
		((Obj&)sp).setPositionX(tileData.first->getPositionX() - act.hitRect.x / 2);
	}
	else if (tileData.first != nullptr  && lr == 'l')
	{
		((Obj&)sp).setPositionX(tileData.first->getPositionX() + hitNode->getMapTileSize().width + act.hitRect.x / 2);
	}

	//プレイヤーの真下の位置情報
	auto hitPos = cocos2d::Vec2(((Obj&)sp).getPosition().x, ((Obj&)sp).getPosition().y - act.hitRect.y / 2);
	
	//真下のタイル位置の情報
	tileNum.first = cocos2d::Vec2(hitPos.x / hitNode->getMapTileSize().width,
								 hitNode->getLayerSize().height - hitPos.y / hitNode->getMapTileSize().height);
	tileData.first = (cocos2d::TMXTiledMap*)hitNode->getTileAt(cocos2d::Vec2((int)tileNum.first.x,
																	   (int)tileNum.first.y));

	if (tileData.first != nullptr)
	{
		((Obj&)sp).setPositionY(act.hitRect.y / 2 + tileData.first->getPosition().y + hitNode->getMapTileSize().height);
		((Obj&)sp).stateName("player-idle-r");
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
