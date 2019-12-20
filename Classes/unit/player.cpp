#include "player.h"
#include "MojuleHeader.h"

#include "input/OPRT_KEY.h"

#include "input/OPRT_TOUCH.h"


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

	_speed = 5.0f;
	_gravity = cocos2d::Vec2(0,-1);

	//アニメーションの登録処理
	lpAnimCtl.addAnimation("player", "player-idle", 0.2f);
	lpAnimCtl.addAnimation("player", "player-run", 0.1f);
	lpAnimCtl.addAnimation("player", "player-run-shot", 0.1f);
	lpAnimCtl.addAnimation("player", "player-jump", 0.2f);

	//右移動
	/*{
		ActMojule act;
		act.stateName = "player-run-r";
		act.stateID = STATE::MOVE_R;
		act.whiteList.emplace_back(STATE::IDLE);
		act.whiteList.emplace_back(STATE::JUMP);
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.runAction = MovLR();
		act.keyData = std::tuple<PTN, bool, bool>(PTN::MOVE_R, false, true);
		act.vec = cocos2d::Vec2(1, 0);
		act.flip = false;
		act.repeat = false;
		act.action = lpAnimCtl.getAction(this,"player-run",true,act.flip);
		lpMoveCtl.AddActMojule(act.stateName,act);
	}*/
	//左移動
	/*{
		ActMojule act;
		act.stateName = "player-run-l";
		act.stateID = STATE::MOVE_L;
		act.whiteList.emplace_back(STATE::IDLE);
		act.whiteList.emplace_back(STATE::JUMP);
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.keyData = std::tuple<PTN, bool, bool>(PTN::MOVE_L, false, true);
		act.runAction = MovLR();
		act.vec = cocos2d::Vec2(-1, 0);
		act.flip = true;
		act.repeat = false;
		act.action = lpAnimCtl.getAction(this, "player-run", true, act.flip);
		lpMoveCtl.AddActMojule(act.stateName, act);	
	}*/
	//右ダッシュ中
	{
		ActMojule act;
		act.stateName = "player-running-r";
		act.stateID = STATE::MOVE_R;
		act.whiteList.emplace_back(STATE::IDLE_R);
		act.whiteList.emplace_back(STATE::JUMP_R);
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.runAction = MovLR();
		act.keyData.emplace_back(std::tuple<PTN, bool, bool>(PTN::MOVE_R, true, true));
		//act.keyData = std::tuple<PTN, bool, bool>(PTN::MOVE_R, true, true);
		act.vec = cocos2d::Vec2(1, 0);
		act.flip = false;
		act.repeat = false;
		act.action = lpAnimCtl.getAction(this, "player-run", true, act.flip);;
		lpMoveCtl.AddActMojule(act.stateName, act);	
	}
	//左ダッシュ中
	{
		ActMojule act;
		act.stateName = "player-running-l";
		act.stateID = STATE::MOVE_L;
		act.whiteList.emplace_back(STATE::IDLE_L);
		act.whiteList.emplace_back(STATE::JUMP_L);
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.runAction = MovLR();
		act.keyData.emplace_back(std::tuple<PTN, bool, bool>(PTN::MOVE_L, true, true));
		//act.keyData = std::tuple<PTN, bool, bool>(PTN::MOVE_L, true, true);
		act.vec = cocos2d::Vec2(-1, 0);
		act.flip = true;
		act.repeat = false;
		act.action = lpAnimCtl.getAction(this, "player-run", true, act.flip);;
		lpMoveCtl.AddActMojule(act.stateName, act);	
	}
	//右待機中
	{
		ActMojule act;
		act.stateName = "player-idle-r";
		act.stateID = STATE::IDLE_R;
		act.whiteList.emplace_back(STATE::MOVE_L);
		act.whiteList.emplace_back(STATE::MOVE_R);
		act.whiteList.emplace_back(STATE::JUMP_R);
		act.blackList.emplace_back(STATE::IDLE_L);
		act.blackList.emplace_back(STATE::JUMP_L);
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.runAction = MovIdle();
		act.keyData.emplace_back(std::tuple<PTN, bool, bool>(PTN::NON_KEY, true, true));
		act.keyData.emplace_back(std::tuple<PTN, bool, bool>(PTN::MOVE_R, true, false));
		//act.keyData = std::tuple<PTN, bool, bool>(PTN::NON_KEY, true, true);
		act.vec = cocos2d::Vec2(0, 0);
		act.flip = false;
		act.repeat = false;
		act.action = lpAnimCtl.getAction(this, "player-idle", true, false);
		lpMoveCtl.AddActMojule(act.stateName, act);	
		_stateName = act.stateName;
	}
	//左待機中
	{
		ActMojule act;
		act.stateName = "player-idle-l";
		act.stateID = STATE::IDLE_L;
		act.whiteList.emplace_back(STATE::MOVE_L);
		act.whiteList.emplace_back(STATE::MOVE_R);
		act.whiteList.emplace_back(STATE::JUMP_L);
		act.blackList.emplace_back(STATE::IDLE_R);
		act.blackList.emplace_back(STATE::JUMP_R);
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.runAction = MovIdle();
		act.keyData.emplace_back(std::tuple<PTN, bool, bool>(PTN::NON_KEY, true, true));
		act.keyData.emplace_back(std::tuple<PTN, bool, bool>(PTN::MOVE_L, true, false));
		//act.keyData = std::tuple<PTN, bool, bool>(PTN::NON_KEY, true, true);
		act.vec = cocos2d::Vec2(0, 0);
		act.flip = true;
		act.repeat = false;
		act.action = lpAnimCtl.getAction(this, "player-idle", true, false);
		lpMoveCtl.AddActMojule(act.stateName, act);
	}
	//右落下
	{
		ActMojule act;
		act.stateName = "player-fall-r";
		act.stateID = STATE::FALL;
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.runAction = MovFall();
		act.keyData.emplace_back(std::tuple<PTN, bool, bool>(PTN::NON_KEY, true, true));
		//act.keyData = std::tuple<PTN, bool, bool>(PTN::NON_KEY, true, true);
		act.vec = cocos2d::Vec2(0, -1);
		act.flip = false;
		act.hitRect = cocos2d::Vec2(66, 136);
		act.action = lpAnimCtl.getAction(this, "player-idle", true, false);;
		lpMoveCtl.AddActMojule(act.stateName, act);
	}
	//左落下
	{
		ActMojule act;
		act.stateName = "player-fall-l";
		act.stateID = STATE::FALL;
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.runAction = MovFall();
		act.keyData.emplace_back(std::tuple<PTN, bool, bool>(PTN::NON_KEY, true, true));
		//act.keyData = std::tuple<PTN, bool, bool>(PTN::NON_KEY, true, true);
		act.vec = cocos2d::Vec2(0, -1);
		act.flip = true;
		act.hitRect = cocos2d::Vec2(66, 136);
		act.action = lpAnimCtl.getAction(this, "player-idle", true, false);;
		lpMoveCtl.AddActMojule(act.stateName, act);
	}
	//落下中
	/*{
		ActMojule act;
		act.stateName = "player-falling";
		act.stateID = STATE::FALLING;
		act.actionList.emplace_back(CheckList());
		act.actionList.emplace_back(CheckHitObj());
		act.runAction = MovFall();
		act.keyData = std::tuple<PTN, bool, bool>(PTN::NON_KEY, true, true);
		act.vec = cocos2d::Vec2(0, -1);
		act.action = lpAnimCtl.getAction(this, "player-idle", true, false);;
		lpMoveCtl.AddActMojule(act.stateName, act);
	}*/
	//右ジャンプ
	{
		ActMojule act;
		act.stateName = "player-jump-r";
		act.stateID = STATE::JUMP_R;
		act.runAction = MovJump();
		act.keyData.emplace_back(std::tuple<PTN, bool, bool>(PTN::JUMP, false, true));
		//act.keyData = std::tuple<PTN, bool, bool>(PTN::JUMP, false, true);
		act.vec = cocos2d::Vec2(0, 3);
		act.repeat = false;
		act.flip = false;
		act.hitRect = cocos2d::Vec2(66, 136);
		act.action = lpAnimCtl.getAction(this, "player-jump", act.repeat, false);
		lpMoveCtl.AddActMojule(act.stateName, act);
	}
	//左ジャンプ
	{
		ActMojule act;
		act.stateName = "player-jump-l";
		act.stateID = STATE::JUMP_L;
		act.runAction = MovJump();
		act.keyData.emplace_back(std::tuple<PTN, bool, bool>(PTN::JUMP, false, true));
		//act.keyData = std::tuple<PTN, bool, bool>(PTN::JUMP, false, true);
		act.vec = cocos2d::Vec2(0, 3);
		act.repeat = false;
		act.flip = true;
		act.hitRect = cocos2d::Vec2(66, 136);
		act.action = lpAnimCtl.getAction(this, "player-jump", act.repeat, true);
		lpMoveCtl.AddActMojule(act.stateName, act);
	}

	runAction(lpMoveCtl.GetActData(_stateName).action);

	lpSoundCtl.AddSoundData("maougan", SND_PTN::SE, 2.0f, 1.0f, 0, 0.0f, 0);
	
#ifdef _DEBUG
	_dbgDrawBoxCC((*this), cocos2d::Color4F::WHITE);
#else
#endif
	

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	_oprtState = std::make_shared<OPRT_KEY>((*this));
#else
#endif
	
	
	this->scheduleUpdate();


	return true;
}

void player::update(float delta)
{
	/*if (_oprtState == nullptr)
	{
		auto director = cocos2d::Director::getInstance();
		auto touchLayer = (cocos2d::Layer*)director->getRunningScene()->getChildByName("hitObj")->getChildByName("android");
		_oprtState = std::make_shared<OPRT_TOUCH>((*this));
	}*/
	lpMoveCtl.SetActState((*this),_oprtState);

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

	//auto director = cocos2d::Director::getInstance();
	//auto  hitScene = (cocos2d::TMXTiledMap*)director->getRunningScene()->getChildByName("hitObj")->getChildByName("map");
	//auto hitNode = hitScene->getLayer("field");
	//for (unsigned int y = 0; y < hitNode->getLayerSize().height; y++)
	//{
	//	for (unsigned int x = 0; x < hitNode->getLayerSize().width; x++)
	//	{
	//		if (auto checkObj = (cocos2d::TMXTiledMap*)hitNode->getTileAt(cocos2d::Vec2(x, y)))
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

