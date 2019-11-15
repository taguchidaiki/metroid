#ifdef _DEBUG
#include <windows.h>
#include "_DebugConOut.h"

std::unique_ptr<_DebugConOut, _DebugConOut::_DebugConOutDeleter> _DebugConOut::s_Instance(new _DebugConOut);

_DebugConOut::_DebugConOut()
{
	//�\�����Ԃ̌Œ�
	//HWND hWnd = GetForegroundWindow();				//�O�ɂ���E�C���h�E�̃n���h�����擾

	//�R���\�[���\���p�̊֐�
	AllocConsole();

	//�R���\�[���ւ̕����̏o��
	freopen_s(&_debugFp,"CONOUT$","w",stdout);			//��2 CONOUT$, ��3 "w"write�̗�, ��4�@stdout

	//�R���\�[���ւ̕����̓���
	freopen_s(&_debugFp, "CONIN$", "r", stdin);

	//�n���h���̐ݒ�
	//SetForegroundWindow(hWnd);
}


_DebugConOut::~_DebugConOut()
{
	//�R���\�[������p�̊֐�
	FreeConsole();
}
#endif //_DEBUG