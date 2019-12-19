#include "AnimCtl.h"

//フォルダ名、アニメーションのキー名、アニメーションの間隔
void AnimCtl::addAnimation(std::string fileName, std::string key, float animIntval)
{
	std::string fileDir = "image/Sprites/" + fileName + "/" + key + "/" + key + ".plist";
	auto spriteFrameCache = cocos2d::SpriteFrameCache::getInstance();
	spriteFrameCache->addSpriteFramesWithFile(fileDir);
	auto animation = cocos2d::Animation::create();

	//フォルダの総ざらい処理
	for (int i = 1; i < 15;i++)
	{
		std::string tt_str = "-%i.png";
		auto t_str = cocos2d::__String::createWithFormat(tt_str.c_str(), i);
		std::string str = key + t_str->getCString();

		cocos2d::SpriteFrame* sprite = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(str.c_str());
		if (sprite == nullptr)
		{
			break;
		}
		animation->addSpriteFrame(sprite);
	}
	
	animation->setDelayPerUnit(animIntval);
	animation->setRestoreOriginalFrame(true);
	cocos2d::AnimationCache::getInstance()->addAnimation(animation, key);
}

//アニメーションのキー名、継続して流すかどうかのフラグ、
cocos2d::Action * AnimCtl::getAction(cocos2d::Node* sp,std::string key, bool repeat, bool flip)
{
	cocos2d::Action* action;

	if (repeat)
	{
		action = cocos2d::RepeatForever::create(cocos2d::Animate::create(cocos2d::AnimationCache::getInstance()->getAnimation(key)));
	}
	else
	{
		action = cocos2d::Animate::create(cocos2d::AnimationCache::getInstance()->getAnimation(key));
	}

	return action;
}

void AnimCtl::runAction(cocos2d::Sprite & sp, ActMojule& act)
{
	sp.stopAllActions();
	sp.runAction(act.action);
	sp.runAction(cocos2d::FlipX::create(act.flip));

}

AnimCtl::AnimCtl()
{
}


AnimCtl::~AnimCtl()
{
}
