//#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "EffectCtl.h"
#include "ck/ck.h"
#include "ck/config.h"
#include "ck/sound.h"
#include "ck/bank.h"

class HelloWorld : public cocos2d::Scene
{
private:

	int count = 0;

	CkBank* bank;
	CkSound* sound;
	CkSound* se;

public:
    static cocos2d::Scene* createScene();

    virtual bool init() override;
	virtual void update(float delta) override;

	virtual ~HelloWorld();

	virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags) override;
    CREATE_FUNC(HelloWorld);

};

//#endif // __HELLOWORLD_SCENE_H__

