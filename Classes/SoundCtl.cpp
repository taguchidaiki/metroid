#include "SoundCtl.h"

//サウンド名、サウンドの種類、ボリューム、再生速度、再生位置、パンの位置(-1.0f ~ 1.0f)、ループ回数
bool SoundCtl::AddSoundData(std::string soundName, SND_PTN ptn ,float volume, float speed, int pos, float pan, int count)
{
	int soundPtn = static_cast<int>(ptn);

	if (_soundData[soundPtn].find(soundName) == _soundData[soundPtn].end())
	{
		if (ptn == SND_PTN::BGM)
		{
			std::string soundDir = "sound/bgm/" + soundName + ".cks";
			_soundData[soundPtn].emplace(soundName, CkSound::newStreamSound(soundDir.c_str(),_pathType));
		}
		else if (ptn == SND_PTN::SE)
		{
			std::string soundDir = "sound/se/" + soundName + ".ckb";
			_bankData.emplace_back(CkBank::newBank(soundDir.c_str(), _pathType));
			_soundData[soundPtn].emplace(soundName, CkSound::newBankSound(_bankData.back(), soundName.c_str()));
		}
		else
		{
			return false;
		}
	}

	if (_soundData[soundPtn][soundName] == nullptr)
	{
		TRACE("サウンドデータが正しく読み込めませんでした");
		return false;
	}
	//ボリューム、再生速度、再生位置、パンの位置、ループ回数、
	
	_soundData[soundPtn][soundName]->setVolume(volume);
	_soundData[soundPtn][soundName]->setSpeed(speed);
	_soundData[soundPtn][soundName]->setPlayPosition(pos);
	_soundData[soundPtn][soundName]->setPan(pan);
	_soundData[soundPtn][soundName]->setLoopCount(count);

	return true;
}

//サウンド名、サウンドの種類
void SoundCtl::PlaySoundData(std::string soundName, SND_PTN ptn)
{
	_soundData[static_cast<int>(ptn)][soundName]->play();
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
	for (int i = 0; i < static_cast<int>(SND_PTN::MAX);i++)
	{
		for (auto data : _soundData[i])
		{
			data.second->destroy();
		}
	}

	for (auto data : _bankData)
	{
		data->destroy();
	}

	CkShutdown();
}
