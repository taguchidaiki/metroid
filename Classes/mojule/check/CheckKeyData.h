#pragma once
#include "MoveCtl.h"
#include "input/OPRT.h"
#include <memory>

struct CheckKeyData
{
	void operator()(std::weak_ptr<OPRT> oprt);
};

