#pragma once
#include "OPRT.h"

struct OPRT_KEY :public OPRT
{
	
	OPRT_KEY(cocos2d::Node& sp);
	~OPRT_KEY() {};

	//�������֐�
	void Init(cocos2d::Node& sp) override;

	//���̓^�C�v��Ԃ�
	OPRT_TYPE GetOprtType(void) override { return OPRT_TYPE::KEY; };

	//�A�b�v�f�[�g�֐�
	void Update() override;

};

