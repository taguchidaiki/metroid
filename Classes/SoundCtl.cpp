#include "SoundCtl.h"

bool SoundCtl::AddSoundData(std::string soundName, SND_PTN ptn)
{
	int soundPtn = static_cast<int>(ptn);

	if (_soundData[soundPtn].find(soundName) == _soundData[soundPtn].end())
	{
		if (ptn == SND_PTN::BGM)
		{
			std::string soundDir = "sound/bgm/" + soundName + ".cks";
			_soundData[soundPtn].emplace(soundName, CkSound::newStreamSound(soundDir.c_str()));
		}
		else if (ptn == SND_PTN::SE)
		{
			std::string sounddir = "sound/se/" + soundName + ".ckb";
		}
		else
		{
			return false;
		}
	}

	if (_soundData[soundPtn][soundName] == nullptr)
	{
		TRACE("�T�E���h�f�[�^���������ǂݍ��߂܂���ł���");
		return false;
	}
	//�{�����[���A�Đ����x�A�Đ��ʒu�A�p���̈ʒu�A���[�v�񐔁A

	return true;
}

void SoundCtl::PlaySound(std::string soundName, SND_PTN ptn)
{
	
}

void SoundCtl::Update(void)
{
	CkUpdate();
}

SoundCtl::SoundCtl()
{
#if CK_PLATFORM_ANDROID
	CkConfig config(env, activity);
	CkPathType pathType = kCkPathType_Default;
#else
	CkConfig config;
	CkPathType pathType = kCkPathType_FileSystem;
#endif

	CkInit(&config);
}


SoundCtl::~SoundCtl()
{

	CkShutdown();
}
