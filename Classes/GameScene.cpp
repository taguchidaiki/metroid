﻿/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}


static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}


bool GameScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameScene::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

	//背景用レイヤー生成

	auto layer = Layer::create();
	layer->setName("hitObj");

	//当たり判定用背景
	auto pTiled = TMXTiledMap::create("mapdata/mapdata-1.tmx");
	pTiled->setName("map");
	layer->addChild(pTiled,0);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	
#else

#endif
	////アンドロイド用操作キーの画像
	//auto android = Layer::create();
	//android->setName("android");
	//auto up = cocos2d::Sprite::create("icon/moveIcon.png");
	//up->setPosition(cocos2d::Vec2(200, 200));
	//up->setRotation(-90);
	//android->addChild(up, 0);
	//auto right = cocos2d::Sprite::create("icon/moveIcon.png");
	//right->setPosition(cocos2d::Vec2(100, 100));
	//right->setRotation(180);
	//android->addChild(right, 0);
	//auto left = cocos2d::Sprite::create("icon/moveIcon.png");
	//left->setPosition(cocos2d::Vec2(300, 100));
	//android->addChild(left, 0);

	//layer->addChild(android, 2);

	//プレイヤー生成
	auto pl = player::createPlayer();
	pl->setName("player");
	layer->addChild(pl, 1);

	//レイヤーをゲームシーンの子に追加
	this->addChild(layer, 0);

	//位置を目視で確認するようの線（後で消す）
	/*for (int i = 0; i <= 5; i++)
	{
		auto line = DrawNode::create();
		line->drawSegment(Vec2(i * 100, 0), Vec2(i * 100, 500), 1.0f, Color4F::BLACK);
		this->addChild(line, 2);
	}
	for (int i = 0; i <= 5; i++)
	{
		auto line = DrawNode::create();
		line->drawSegment(Vec2(0, i * 100), Vec2(500, i * 100), 1.0f, Color4F::BLACK);
		this->addChild(line, 2);
	}*/

	this->scheduleUpdate();

	//エフェクトの登録処理
	lpEffectCtl.AddEffect("Laser01", 13.0f);
	lpEffectCtl.AddEffect("Homing_Laser01");

	//サウンドの初期化
	lpSoundCtl.AddSoundData("maoucyber", SND_PTN::BGM);
	lpSoundCtl.AddSoundData("maougan", SND_PTN::SE, 2.0f, 1.0f, 0, 0.0f, 0);

	//BGM再生処理
	lpSoundCtl.PlaySoundData("maoucyber", SND_PTN::BGM);

	

    return true;
}


void GameScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void GameScene::update(float delta)
{
	lpEffectCtl.Update();
	lpSoundCtl.Update();
}

void GameScene::visit(cocos2d::Renderer * renderer, const cocos2d::Mat4 & parentTransform, uint32_t parentFlags)
{
	lpEffectCtl.manager().begin(renderer, _globalZOrder);

	cocos2d::Scene::visit(renderer, parentTransform, parentFlags);

	lpEffectCtl.manager().end(renderer, _globalZOrder);
}
