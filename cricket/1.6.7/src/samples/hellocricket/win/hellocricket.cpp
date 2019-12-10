#include <windows.h>
#include "ck/ck.h"
#include "ck/config.h"
#include "ck/bank.h"
#include "ck/sound.h"


int main(int argc, char* argv[])
{
    CkConfig config;
    CkInit(&config);

    CkBank* bank = CkBank::newBank("hellocricket.ckb");
    CkSound* sound = CkSound::newBankSound(bank, 0);
    sound->play();

    while (sound->isPlaying())
    {
        CkUpdate();
        Sleep(30);
    }

    sound->destroy();
    bank->destroy();

    CkShutdown();

	return 0;
}

