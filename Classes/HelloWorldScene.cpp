#include "HelloWorldScene.h"
#include "Effekseer/Effekseer.h"

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
	
	auto rsize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();

	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(320, 200));
	this->addChild(sprite, 0);
	
	this->scheduleUpdate();

	/**
		efk::EffectManagerのインスタンスを生成します。

	*/
	manager = efk::EffectManager::create(rsize);

	lpEffectCtl.AddEffect(manager,"Laser01", 13.0f);
	lpEffectCtl.AddEffect(manager,"Homing_Laser01");

	return true;
}

void HelloWorld::update(float delta)
{

	// Effect1
	if (count % 300 == 0)
	{
		/**
			拡大率を指定してエフェクトファイルを読み込みます。
		*/
		auto effect = lpEffectCtl.GetEffectData("Laser01");
		//auto effect = efk::Effect::create("effect/Laser01.efk",13.0f);
		if (effect != nullptr)
		{
			//auto emitter = efk::EffectEmitter::create(manager);
			//emitter->setEffect(effect);
			lpEffectCtl.GetEffectData("Laser01")->setPlayOnEnter(true);
			//emitter->setPlayOnEnter(true);
			lpEffectCtl.GetEffectData("Laser01")->setRotation3D(cocos2d::Vec3(0, 90, 0));
			//emitter->setRotation3D(cocos2d::Vec3(0, 90, 0));
			lpEffectCtl.GetEffectData("Laser01")->setPosition(Vec2(320, 150));
			//emitter->setPosition(Vec2(320, 150));
			
			// emitter->setScale(13);
			this->addChild(lpEffectCtl.GetEffectData("Laser01"), 0);

			// No need (because it uses autorelease after 1.41)
			//effect->release();

			//ファイルからエフェクトの生成
			//エミッターの生成
			//エミッターにエフェクトの設定
			//シーンに追加する
		}
	}

	// Effect2
	if (count % 300 == 120)
	{
		/**
		エフェクトファイルを読み込みます。
。
		*/
		auto effect = lpEffectCtl.GetEffectData("Homing_Laser01");
		//auto effect = efk::Effect::create("effect/Homing_Laser01.efk");
		if (effect != nullptr)
		{
			/*
			エミッターを生成し、パラメーターを設定してレイヤーに追加します。
			*/

			//auto emitter = efk::EffectEmitter::create(manager);
			//emitter->setEffect(effect);
			lpEffectCtl.GetEffectData("Homing_Laser01")->setPlayOnEnter(true);
			//emitter->setPlayOnEnter(true);
			lpEffectCtl.GetEffectData("Homing_Laser01")->setPosition(Vec2(320, 150));
			//emitter->setPosition(Vec2(320, 150));
			lpEffectCtl.GetEffectData("Homing_Laser01")->setScale(4);
			//emitter->setScale(4);
			this->addChild(lpEffectCtl.GetEffectData("Homing_Laser01"),0);

			/**
			Some parameters are required to set after addChild

			一部のパラメーターはAddChildした後に設定する必要があります。
			*/
			lpEffectCtl.GetEffectData("Homing_Laser01")->setTargetPosition(cocos2d::Vec3(320, 480, 0));
			//emitter->setTargetPosition(cocos2d::Vec3(320, 480, 0));

			// No need (because it uses autorelease after 1.41)
			//effect->release();
		}
	}

	
	//毎フレーム、マネージャーを更新します。
	
	manager->update();

	count++;
}

HelloWorld::~HelloWorld()
{
	/**
		終了時にマネージャーを破棄します。

		You will destroy the manager on exit.

	*/
	manager->release();
}

void HelloWorld::visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags)
{
	/**
		visitを継承して、エフェクトを実際に描画する処理を追加します。

	*/
	manager->begin(renderer, _globalZOrder);
	cocos2d::Scene::visit(renderer, parentTransform, parentFlags);
	manager->end(renderer, _globalZOrder);
}

