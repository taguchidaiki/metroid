#pragma once
#include "Obj.h"

class player :
	public Obj
{
public:
	player();
	~player();
	
	//�����p�֐�
	static cocos2d::Sprite* createPlayer(void);
	static player* create(void);

	//Node�p�������������֐�
	bool init(void)override;
	void update(float delta)override;

	//get�֐�
	
private:
	STATE _state;
};

