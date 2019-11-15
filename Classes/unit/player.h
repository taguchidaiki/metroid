#pragma once
#include "Obj.h"

class player :
	public Obj
{
public:
	player();
	~player();
	
	//¶¬—pŠÖ”
	static cocos2d::Sprite* createPlayer(void);
	static player* create(void);

	//NodeŒp³‚µ‚½‰Šú‰»ŠÖ”
	bool init(void)override;
	void update(float delta)override;

	//getŠÖ”
	
private:
	STATE _state;
};

