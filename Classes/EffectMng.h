#pragma once
#include "cocos2d.h"
#include "Effekseer/Effekseer.h"
#include <map>

#define lpEffectCtl EffectMng::getInstance()


class EffectMng
{
public:
	static EffectMng& getInstance(void)
	{
		static EffectMng getInstance;
		return getInstance;
	}

	void AddEffection(std::string effectName, float size = 1.0f);

	efk::Effect* GetEffectData(std::string effectName);

private:
	EffectMng() {};
	EffectMng(const EffectMng&) {};
	EffectMng& operator=(const EffectMng&) {};
	~EffectMng() {} ;
	
	std::map<std::string, efk::Effect*> _effectList;
};

