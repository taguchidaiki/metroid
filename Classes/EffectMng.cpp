#include "EffectMng.h"

void EffectMng::AddEffect(efk::EffectManager* manager, std::string effectName, float size)
{
	//エフェクトネームからリストを検索かけてなかったら登録する
	if (_effectList.find(effectName) == _effectList.end())
	{
		std::string effectdir = "effect/" + effectName + ".efk";
		_effectList.emplace(effectName,efk::EffectEmitter::create(manager,effectdir,size));
		_effectList[effectName]->autorelease();
	}
}

efk::EffectEmitter* EffectMng::GetEffectData(std::string effectName)
{
	if (_effectList.find(effectName) == _effectList.end())
	{
		
	}
	
	return _effectList[effectName];
}

EffectMng::~EffectMng()
{
	
}
