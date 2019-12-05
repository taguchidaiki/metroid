#include "EffectCtl.h"

//�t�@�C���̃G�t�F�N�g��,�G�t�F�N�g�̃T�C�Y
void EffectCtl::AddEffect(std::string effectName, float size)
{

	//�G�t�F�N�g�l�[�����烊�X�g�����������ĂȂ�������o�^����
	if (_effectList.find(effectName) == _effectList.end())
	{
		std::string effectdir = "effect/" + effectName + ".efk";
		auto effect = efk::Effect::create(effectdir,size);
		effect->retain();
		_effectList[effectName] = effect;
	}
}

void EffectCtl::Update(void)
{
	_manager->update();
}

//�G�t�F�N�g���A�G�t�F�N�g�Ǘ��A�R�Â���m�[�h�A�X�P�[���l�A3D��]�l�A�ʒu���A�����ʒu
bool EffectCtl::AddEmitter(std::string effectName,cocos2d::Node& node, float scale, cocos2d::Vec3& rot, cocos2d::Vec2& pos, cocos2d::Vec3& target)
{
	if (_effectList.find(effectName) == _effectList.end())
	{
		return false;
	}

	//�G�~�b�^�[�ւ̓o�^����
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

EffectCtl::EffectCtl()
{
	auto rsize = cocos2d::Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
	_manager = efk::EffectManager::create(rsize);
}

EffectCtl::~EffectCtl()
{
	_manager->release();

	for (auto list : _effectList)
	{
		list.second->release();
	}

	_effectList.clear();
}

