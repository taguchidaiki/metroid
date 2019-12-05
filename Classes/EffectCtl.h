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

	//�G�t�F�N�g�o�^
	void AddEffect(std::string effectName, float size = 1.0f);

	//�}�l�[�W���[�̃A�b�v�f�[�g
	void Update(void);

	//�o�^�����G�t�F�N�g�ɃG�~�b�^�[�����ăA�^�b�`
	bool AddEmitter(std::string effectName, cocos2d::Node& node,
					   float scale = 1.0f, cocos2d::Vec3& rot = cocos2d::Vec3(0, 90, 0), cocos2d::Vec2& = cocos2d::Vec2(0, 0), cocos2d::Vec3& target = cocos2d::Vec3(0,0,0));

	//get�֐�
	efk::EffectManager& manager(void) const  { return (*_manager); };

	//set�֐�

private:
	EffectCtl();
	EffectCtl(const EffectCtl&) {};
	EffectCtl& operator=(const EffectCtl&) {};
	~EffectCtl();

	//�G�t�F�N�g��񂪓��郊�X�g
	std::map < std::string, efk::Effect*> _effectList;

	//�G�t�F�N�g���Ǘ�����}�l�[�W���[
	efk::EffectManager* _manager;

};

