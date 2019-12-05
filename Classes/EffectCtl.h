#pragma once
#include "cocos2d.h"
#include "Effekseer/Effekseer.h"
#include <map>
#include <memory>

#define lpEffectCtl EffectCtl::getInstance()


class EffectCtl
{
public:
	static EffectCtl& getInstance(void)
	{
		static EffectCtl getInstance;
		return getInstance;
	}

	//エフェクト登録
	void AddEffect(std::string effectName, float size = 1.0f);

	//マネージャーのアップデート
	void Update(void);

	//登録したエフェクトにエミッターをつけてアタッチ
	bool AddEmitter(std::string effectName, cocos2d::Node& node,
					   float scale = 1.0f, cocos2d::Vec3& rot = cocos2d::Vec3(0, 90, 0), cocos2d::Vec2& = cocos2d::Vec2(0, 0), cocos2d::Vec3& target = cocos2d::Vec3(0,0,0));

	//get関数
	efk::EffectManager& manager(void) const  { return (*_manager); };

	//set関数

private:
	EffectCtl();
	EffectCtl(const EffectCtl&) {};
	EffectCtl& operator=(const EffectCtl&) {};
	~EffectCtl();

	//エフェクト情報が入るリスト
	std::map < std::string, efk::Effect*> _effectList;

	//エフェクトを管理するマネージャー
	efk::EffectManager* _manager;

};

