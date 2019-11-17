#pragma once
#include "Obj.h"

class player :
	public Obj
{
public:
	player();
	~player();
	
	//生成用関数
	static cocos2d::Sprite* createPlayer(void);
	static player* create(void);

	//Node継承した初期化関数
	bool init(void)override;
	void update(float delta)override;

	//get関数
	
private:
	STATE _state;
};

