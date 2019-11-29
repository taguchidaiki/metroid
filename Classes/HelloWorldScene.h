//#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "EffectMng.h"
#include "ck/ck.h"
#include "ck/config.h"
#include "ck/sound.h"

/**
	必ずEffekseer.hをインクルードする必要があります

	You must include Effekseer.h

	你必須包括Effekseer.h

	你必须包括Effekseer.h
*/

class HelloWorld : public cocos2d::Scene
{
private:
	/**
		efk::EffectManager*をレイヤーのメンバ変数に追加します。このクラスはエフェクトを管理します。
	*/

	int count = 0;

	CkSound* sound;

public:
    static cocos2d::Scene* createScene();

    virtual bool init() override;
	virtual void update(float delta) override;

	virtual ~HelloWorld();

	virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags) override;
    CREATE_FUNC(HelloWorld);

};

//#endif // __HELLOWORLD_SCENE_H__

