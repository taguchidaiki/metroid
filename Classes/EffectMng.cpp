#include "EffectMng.h"

void EffectMng::AddEffect(efk::EffectManager* manager, std::string effectName, float size)
{
	//エフェクトネームからリストを検索かけてなかったら登録する
	if (_effectList.find(effectName) == _effectList.end())
	{
		std::string effectdir = "effect/" + effectName + ".efk";
		auto effect = efk::Effect::create(effectdir,size);
		auto emitter = efk::EffectEmitter::create(manager);
		emitter->retain();
		emitter->setEffect(effect);
		_effectList[effectName] = std::make_pair(effect, emitter);
	}
}

void EffectMng::Update(void)
{
	
}

efk::EffectEmitter* EffectMng::GetEffectData(std::string effectName)
{
	if (_effectList.find(effectName) == _effectList.end())
	{
		return nullptr;
	}
	
	return _effectList[effectName].second;
}


EffectMng::~EffectMng()
{
	for (auto list : _effectList)
	{
		list.second.first->release();
		list.second.second->release();
	}
}
