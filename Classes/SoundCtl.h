#pragma once
#include <array>
#include <vector>
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

	//サウンド情報の登録処理
	bool AddSoundData(std::string soundName, SND_PTN ptn, 
					  float volume = 1.0f, float speed = 1.0f, int pos = 0, float pan = 0.0f, int count = -1);

	//引数で渡されたサウンドを鳴らす
	void PlaySoundData(std::string soundName, SND_PTN ptn);
	
	//引数で渡されたサウンドを止める
	bool StopSound();

	//すべてのサウンドを止める
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
	std::vector<CkBank*> _bankData;
};

