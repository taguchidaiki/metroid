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
		act.stateName = "player-run-r";
		act.stateID = STATE::MOVE_R;
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.runAction = MovLR();
		act.keyData = std::tuple<PTN, bool, bool>(PTN::MOVE_R, false, true);
		act.vec = cocos2d::Vec2(1, 0);
		act.flip = false;
		lpMoveCtl.AddActMojule(act.stateName,act);
	}
	//左移動
	{
		ActMojule act;
		act.stateName = "player-run-l";
		act.stateID = STATE::MOVE_L;
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.keyData = std::tuple<PTN, bool, bool>(PTN::MOVE_L, false, true);
		act.runAction = MovLR();
		act.vec = cocos2d::Vec2(-1, 0);
		act.flip = true;
		lpMoveCtl.AddActMojule(act.stateName, act);	
	}
	//右ダッシュ中
	{
		ActMojule act;
		act.stateName = "player-running-r";
		act.stateID = STATE::MOVE_R;
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.runAction = MovLR();
		act.keyData = std::tuple<PTN, bool, bool>(PTN::MOVE_R, true, true);
		act.vec = cocos2d::Vec2(1, 0);
		act.flip = false;
		lpMoveCtl.AddActMojule(act.stateName, act);	
	}
	//左ダッシュ中
	{
		ActMojule act;
		act.stateName = "player-running-l";
		act.stateID = STATE::MOVE_L;
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.runAction = MovLR();
		act.keyData = std::tuple<PTN, bool, bool>(PTN::MOVE_L, true, true);
		act.vec = cocos2d::Vec2(-1, 0);
		act.flip = true;
		lpMoveCtl.AddActMojule(act.stateName, act);	
	}
	//待機中
	{
		ActMojule act;
		act.stateName = "player-idle";
		act.stateID = STATE::IDLE;
		act.whiteList.emplace_back(STATE::MOVE_L);
		act.whiteList.emplace_back(STATE::MOVE_R);
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.runAction = MovIdle();
		act.keyData = std::tuple<PTN, bool, bool>(PTN::NON_KEY, true, true);
		act.vec = cocos2d::Vec2(0, 0);
		lpMoveCtl.AddActMojule(act.stateName, act);	
		_stateName = act.stateName;
	}
	//ジャンプ
	{
		ActMojule act;
		act.stateName = "player-jump";
		act.stateID = STATE::JUMP;
		act.runAction = MovJump();
		act.keyData = act.keyData = std::tuple<PTN, bool, bool>(PTN::JUMP, false, true);
		act.vec = cocos2d::Vec2(0, 1);
		lpMoveCtl.AddActMojule(act.stateName, act);
	}
	//ジャンプ中
	{
		ActMojule act;
		act.stateName = "player-jumping";
		act.stateID = STATE::JUMPING;
		act.blackList.emplace_back(STATE::FALLING);
		act.whiteList.emplace_back(STATE::MOVE_R);
		act.whiteList.emplace_back(STATE::MOVE_L);
		act.runAction = MovJump();
		act.keyData = std::tuple<PTN, bool, bool>(PTN::NON_KEY, true, true);
		act.vec = cocos2d::Vec2(0, 1);
		lpMoveCtl.AddActMojule(act.stateName, act);

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

	//_dbgDrawBoxCC((*this), cocos2d::Color4F::WHITE);

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
	lpMoveCtl.SetActState((*this),_oprtState);

	lpMoveCtl.ActUpdate((*this));

	_oprtState->Update();

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

