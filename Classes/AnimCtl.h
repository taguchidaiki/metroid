#pragma once
#include "cocos2d.h"
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

	//アニメーションの追加処理
	void addAnimation(std::string fileName, std::string key, float animIntval);
	
	//アクションを受け渡す処理
	cocos2d::Action* getAction(cocos2d::Node* sp,std::string key, bool repeat, bool flip);
	
private:
	AnimCtl();
	AnimCtl(const AnimCtl&) {};
	AnimCtl &operator=(const AnimCtl&) {};
	~AnimCtl();


};
