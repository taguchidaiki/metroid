#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

bool HelloWorld::init()
{
	if ( !Scene::init() )
	{
		return false;
	}

	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(320, 200));
	this->addChild(sprite, 0);
	
	this->scheduleUpdate();

	/**
		efk::EffectManagerのインスタンスを生成します。

	*/

	lpEffectCtl.AddEffect("Laser01", 13.0f);
	lpEffectCtl.AddEffect("Homing_Laser01");


#if CK_PLATFORM_ANDROID
	CkConfig config(env, activity);
	CkPathType pathType = kCkPathType_Default;
#else
	CkConfig config;
	CkPathType pathType = kCkPathType_FileSystem;
#endif

	CkInit(&config);

	sound = CkSound::newStreamSound("sound/bgm/maoucyber.cks", pathType);
	sound->play();

	bank = CkBank::newBank("sound/se/maougan.ckb", pathType);
	se = CkSound::newBankSound(bank,"maougan");
	se->play();
	return true;
}

void HelloWorld::update(float delta)
{
	
	if (count % 300 == 0)
	{
		
		if (!lpEffectCtl.AddEmitter("Laser01", (*this), 1.0f, Vec3(0, 90, 0), Vec2(320, 150), Vec3(0, 0, 0)))
		{
			
		}
	}

	if (count % 300 == 120)
	{
		
		if (!lpEffectCtl.AddEmitter("Homing_Laser01", (*this), 4.0f, Vec3(0, 0, 0), Vec2(320, 150), Vec3(320, 480, 0)))
		{
			
		}
	}
	
	//毎フレーム、マネージャーを更新します。
	lpEffectCtl.Update();

	CkUpdate();

	count++;
}

HelloWorld::~HelloWorld()
{
	sound->destroy();
	se->destroy();
	bank->destroy();
	CkShutdown();
}

void HelloWorld::visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags)
{
	/**
		visitを継承して、エフェクトを実際に描画する処理を追加します。
	*/
	lpEffectCtl.manager().begin(renderer, _globalZOrder);

	cocos2d::Scene::visit(renderer, parentTransform, parentFlags);

	lpEffectCtl.manager().end(renderer, _globalZOrder);
	
}

