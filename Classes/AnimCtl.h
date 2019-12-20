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

	//アニメーションの追加処理
	void addAnimation(std::string fileName, std::string key, float animIntval);
	
	//アクションを受け渡す処理
	cocos2d::Action* getAction(cocos2d::Node* sp,std::string key, bool repeat, bool flip);

	//アクション起動処理
	void runAction(cocos2d::Sprite& sp, ActMojule& act);
	
private:
	AnimCtl();
	AnimCtl(const AnimCtl&) {};
	AnimCtl &operator=(const AnimCtl&) {};
	~AnimCtl();


};
