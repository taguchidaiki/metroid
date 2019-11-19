#pragma once
#include "move/MoveCtl.h"
#include "input/OPRT.h"
#include <memory>

struct CheckKeyData
{
	std::unique_ptr<OPRT> operator()(std::unique_ptr<OPRT> oprt);
};

