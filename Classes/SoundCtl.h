#pragma once
#include <array>
#include <map>
#include "debug/_DebugConOut.h"
#include "ck/ck.h"
#include "ck/config.h"
#include "ck/sound.h"
#include "ck/bank.h"

#define lpSoundCtl SoundCtl::GetInstance()

enum class SND_PTN
{
	BGM,
	SE,
	MAX
};

class SoundCtl
{
public:

	static SoundCtl& GetInstance(void)
	{
		static SoundCtl getInstance;
		return getInstance;
	}

	//�T�E���h���̓o�^����
	bool AddSoundData(std::string soundName, SND_PTN ptn);

	//�����œn���ꂽ�T�E���h��炷
	void PlaySound(std::string soundName, SND_PTN ptn);
	
	//�����œn���ꂽ�T�E���h���~�߂�
	bool StopSound();

	//���ׂẴT�E���h���~�߂�
	void StopAllSound();

	void Update(void);

private:
	SoundCtl();
	SoundCtl(const SoundCtl&) {};
	SoundCtl& operator=(const SoundCtl&) {};
	~SoundCtl();

	CkConfig config;
	CkPathType _pathType;
	std::array<std::map<std::string, CkSound*>, static_cast<int>(SND_PTN::MAX)> _soundData;
};

