#include "player.h"
#include "MojuleHeader.h"
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "input/OPRT_KEY.h"
#else
#include "input/OPRT_TOUCH.h"
#endif

player::player()
{	
}

player::~player()
{
}

cocos2d::Sprite * player::createPlayer(void)
{
	return player::create();
}

player * player::create(void)
{
	player *sprite = new (std::nothrow) player();
	if (sprite && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool player::init(void)
{
	initWithTexture(nullptr, cocos2d::Rect(240, 240, 66, 136));

	setPosition(cocos2d::Vec2(200, 100));

	_speed = 3.0f;
	//右移動
	{
		ActMojule act;
		act.stateID = STATE::RUN;
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.runAction = MovLR();
		act.keyData = std::tuple<PTN, bool, bool>(PTN::M_RIGHT, false, true);
		act.vec = cocos2d::Vec2(1, 0);
		lpMoveCtl.AddActMojule("player-run-r",act);
	}
	//左移動
	{
		ActMojule act;
		act.stateID = STATE::RUN;
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.keyData = std::tuple<PTN, bool, bool>(PTN::M_LEFT, false, true);
		act.runAction = MovLR();
		act.vec = cocos2d::Vec2(-1, 0);
		lpMoveCtl.AddActMojule("player-run-l", act);
	}
	//右ダッシュ中
	{
		ActMojule act;
		act.stateID = STATE::RUNNING;
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.runAction = MovLR();
		act.keyData = std::tuple<PTN, bool, bool>(PTN::M_RIGHT, true, true);
		act.vec = cocos2d::Vec2(1, 0);
		lpMoveCtl.AddActMojule("player-running-r", act);
	}
	//左ダッシュ中
	{
		ActMojule act;
		act.stateID = STATE::RUNNING;
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.runAction = MovLR();
		act.keyData = std::tuple<PTN, bool, bool>(PTN::M_LEFT, true, true);
		act.vec = cocos2d::Vec2(-1, 0);
		lpMoveCtl.AddActMojule("player-running-l", act);
	}
	//待機中
	{
		ActMojule act;
		act.stateID = STATE::IDLE;
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.runAction = MovIdle();
		act.vec = cocos2d::Vec2(0, 0);
		lpMoveCtl.AddActMojule("player-idle", act);
	}
	////落下
	//{
	//	ActMojule act;
	//	act.stateID = STATE::FALL;
	//}
	////落下中
	//{
	//	ActMojule act;
	//	act.stateID = STATE::FALLING;
	//}
	
	//アニメーションの登録処理
	lpAnimCtl.addAnimation("player", "player-idle", 0.2f);
	lpAnimCtl.addAnimation("player", "player-run", 0.1f);
	lpAnimCtl.addAnimation("player", "player-run-shot", 0.1f);
	lpAnimCtl.addAnimation("player", "player-jump", 0.2f);

	_dbgDrawBoxCC((*this), cocos2d::Color4F::WHITE);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	_oprtState = std::make_shared<OPRT_KEY>((*this));
#else
	_oprtState = std::make_shared<OPRT_TOUCH>((*this));
#endif

	this->scheduleUpdate();

	return true;
}

void player::update(float delta)
{
	/*_oldStateName = _stateName;
	auto oldPos = getPosition();*/

	_oprtState->Update();

	lpMoveCtl.SetActState((*this),_act,_oprtState);

	lpMoveCtl.ActUpdate((*this),_act);

	//if (oldPos != getPosition())
	//{
	//	TRACE("x = %f y = %f\n", getPosition().x, getPosition().y);
	//}

	/*if (_oprtState->dir()[static_cast<int>(KEY::RIGHT)].second || _oprtState->dir()[static_cast<int>(KEY::LEFT)].second)
	{
		_stateName = "player-run";
	}
	else if(_oprtState->dir()[static_cast<int>(KEY::SPACE)].second)
	{
		_stateName = "player-idle";
	}*/

	/*if (_oprtState->dir()[static_cast<int>(KEY::RIGHT)].second)
	{
		_flip = false;
	}
	else if(_oprtState->dir()[static_cast<int>(KEY::LEFT)].second)
	{
		_flip = true;
	}*/

	////ｱﾆﾒｰｼｮﾝ更新時または現在のｱﾆﾒｰｼｮﾝが終了したとき
	//if ((_stateName != _oldStateName))
	//{
	//	stopAllActions();
	//	auto flip = cocos2d::FlipX::create(_flip);
	//	runAction(lpAnimCtl.getAction(this, _stateName, true, _flip));
	//	runAction(flip);
	//}

	//auto director = Director::getInstance();
	//auto  hitScene = (TMXTiledMap*)director->getRunningScene()->getChildByName("hitObj")->getChildByName("map");
	//auto hitNode = hitScene->getLayer("field");
	//for (unsigned int y = 0; y < hitNode->getLayerSize().height; y++)
	//{
	//	for (unsigned int x = 0; x < hitNode->getLayerSize().width; x++)
	//	{
	//		if (auto checkObj = (TMXTiledMap*)hitNode->getTileAt(Vec2(x, y)))
	//		{
	//			//簡易当たり判定処理
	//			if ((checkObj->getPosition().x <= getPosition().x + _rect.size.width / 2)
	//				&&(checkObj->getPosition().x + hitScene->getTileSize().width >= getPosition().x - _rect.size.width / 2)
	//				&&(checkObj->getPosition().y >= getPosition().y - _rect.size.height / 2)
	//				&&(checkObj->getPosition().y - hitScene->getTileSize().height <= getPosition().y + _rect.size.height / 2))
	//			{
	//				TRACE("hit\n");
	//			}
	//		}
	//	}
	//}
	
}

