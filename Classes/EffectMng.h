#pragma once
#include "cocos2d.h"
#include "Effekseer/Effekseer.h"
#include <map>
#include <memory>

#define lpEffectCtl EffectMng::getInstance()


class EffectMng
{
public:
	static EffectMng& getInstance(void)
	{
		static EffectMng getInstance;
		return getInstance;
	}

	void AddEffect(efk::EffectManager* manager, std::string effectName, float size = 1.0f);

	efk::EffectEmitter* GetEffectData(std::string effectName);

private:
	EffectMng() {};
	EffectMng(const EffectMng&) {};
	EffectMng& operator=(const EffectMng&) {};
	~EffectMng();

	//std::map<std::string, efk::Effect*> _effectList;
	std::map<std::string, efk::EffectEmitter*> _effectList;

};

