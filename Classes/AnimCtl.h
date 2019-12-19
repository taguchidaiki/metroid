#pragma once
#include "cocos2d.h"
#include "MoveCtl.h"
#include <map>
#include <memory>

#define lpAnimCtl AnimCtl::GetInstance()

class AnimCtl
{
public:
	static AnimCtl& GetInstance(void)
	{
		static AnimCtl getInstance;
		return getInstance;
	}

	//�A�j���[�V�����̒ǉ�����
	void addAnimation(std::string fileName, std::string key, float animIntval);
	
	//�A�N�V�������󂯓n������
	cocos2d::Action* getAction(cocos2d::Node* sp,std::string key, bool repeat, bool flip);

	//�A�N�V�����N������
	void runAction(cocos2d::Sprite& sp, ActMojule& act);
	
private:
	AnimCtl();
	AnimCtl(const AnimCtl&) {};
	AnimCtl &operator=(const AnimCtl&) {};
	~AnimCtl();


};
