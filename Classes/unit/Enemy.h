#pragma once
#include "Obj.h"

class Enemy :
	public Obj
{
public:
	Enemy();
	~Enemy();

	bool init(void)override;
	void update(float delta)override;

};

