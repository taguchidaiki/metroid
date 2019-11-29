#include "EffectMng.h"

//ファイルのエフェクト名,エフェクトのサイズ
void EffectMng::AddEffect(std::string effectName, float size)
{
	//エフェクトネームからリストを検索かけてなかったら登録する
	if (_effectList.find(effectName) == _effectList.end())
	{
		std::string effectdir = "effect/" + effectName + ".efk";
		auto effect = efk::Effect::create(effectdir,size);
		effect->retain();
		_effectList[effectName] = effect;
	}
}

void EffectMng::Update(void)
{
	_manager->update();
}

//エフェクト名、エフェクト管理、紐づけるノード、スケール値、3D回転値、位置情報、収束位置
bool EffectMng::AddEmitter(std::string effectName,cocos2d::Node& node, float scale, cocos2d::Vec3& rot, cocos2d::Vec2& pos, cocos2d::Vec3& target)
{
	if (_effectList.find(effectName) == _effectList.end())
	{
		return false;
	}

	//エミッターへの登録処理
	{
		auto emitter = efk::EffectEmitter::create(_manager);
		emitter->setEffect(_effectList[effectName]);
		emitter->setPlayOnEnter(true);
		emitter->setRotation3D(rot);
		emitter->setPosition(pos);
		emitter->setScale(scale);

		node.addChild(emitter);

		emitter->setTargetPosition(target);
	}

	return true;
}

EffectMng::EffectMng()
{
	auto rsize = cocos2d::Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
	_manager = efk::EffectManager::create(rsize);
}

EffectMng::~EffectMng()
{
	_manager->release();

	for (auto list : _effectList)
	{
		list.second->release();
	}

	_effectList.clear();
}

