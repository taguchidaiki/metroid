#include "CheckKeyData.h"

std::unique_ptr<OPRT> CheckKeyData::operator()(std::unique_ptr<OPRT> oprt)
{
	
	return std::move(oprt);
}
