#pragma once
#include <JNI/jni.h>
#include <JNI/jvmti.h>
#include <chrono>
#include <Windows.h>
#include <iostream>

namespace Ripterms
{
	inline HINSTANCE module = nullptr;
	inline HWND window = nullptr;
	enum Version
	{
		UNDEFINED,
		LUNAR_1_7_10,
		LUNAR_1_8_9,
		VANILLA_1_8_9,
		LUNAR_1_16_5,
		FORGE_1_7_10,
		MAJOR_1_8_9,
		MAJOR_1_16_5
	};
	inline Version version = UNDEFINED;
	inline Version majorVersion = UNDEFINED;
	inline JavaVM* p_jvm = nullptr;
	inline JNIEnv* p_env = nullptr;
	inline jvmtiEnv* p_tienv = nullptr;
	inline int ticksExisted = 0;

	class Timer {
	public:
		Timer(std::chrono::milliseconds everyXms);
		bool isElapsed();
		void setEvery(std::chrono::milliseconds everyXms);
	private:
		std::chrono::steady_clock::time_point timerBegin;
		std::chrono::milliseconds targetMs;
	};
	
	BOOL init(HMODULE dll, FILE* fbuffer1, FILE* fbuffer2, FILE* fbuffer3);
	void clean();
	void partialClean();
}