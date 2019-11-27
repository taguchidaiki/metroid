#include "EffectMng.h"

void EffectMng::AddEffection(std::string effectName, float size = 1.0f)
{
	if (_effectList.find(effectName) == _effectList.end())
	{
		std::string effectdir = "effect/" + effectName;
		_effectList.emplace(effectName,efk::Effect::create(effectdir,size));
	}
}

efk::Effect* EffectMng::GetEffectData(std::string effectName)
{
	if (_effectList.find(effectName) == _effectList.end())
	{
		return nullptr;
	}

	return _effectList[effectName];
}
