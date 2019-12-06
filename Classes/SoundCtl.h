#pragma once
#include <array>
#include <vector>
#include <map>
#include <string>
#include "debug/_DebugConOut.h"
#include <ck/ck.h>
#include <ck/config.h>
#include <ck/sound.h>
#include <ck/bank.h>
#include <jni.h>

#define lpSoundCtl SoundCtl::GetInstance()

#ifndef __ANDROID_JNI__
#define __ANDROID_JNI__
#ifdef __cplusplus
extern "C" {
#endif

	JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_AppActivity_initCricket(JNIEnv *env,jclass activity, jobject context);

#ifdef __cplusplus
}
#endif
#endif
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

	CkPathType _pathType;
	std::array<std::map<std::string, CkSound*>, static_cast<int>(SND_PTN::MAX)> _soundData;
	std::vector<CkBank*> _bankData;
};

