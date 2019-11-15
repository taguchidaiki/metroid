#pragma once
#ifdef _DEBUG
#include <Windows.h>
#include <memory>

#define TRACE(fmt, ...) printf(fmt, __VA_ARGS__)

//#define AST(){//\
//	//CHAR 
//};

class _DebugConOut
{
public:
	static _DebugConOut&GetInstance(void)
	{
		return (*s_Instance);
	}
	
private:
	//�f���[�^�[
	struct _DebugConOutDeleter 
	{
		void operator()(_DebugConOut* debugConOut)const
		{
			delete debugConOut;
		}
	};

	_DebugConOut();
	~_DebugConOut();

	//static _DebugConOut *s_Instance;
	static std::unique_ptr<_DebugConOut, _DebugConOutDeleter> s_Instance;

	//�f�o�b�N�p�̃t�@�C���̃|�C���^
	FILE* _debugFp = nullptr;					
};
#else
#define TRACE(fmt, ...)
#define AST()
#endif //_DEBUG