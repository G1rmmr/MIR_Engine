#include "Time.h"

using namespace MIR;

LARGE_INTEGER Time::cpu_freq = {};
LARGE_INTEGER Time::pre_freq = {};
LARGE_INTEGER Time::cur_freq = {};

float Time::delta_time = 0.0f;

void Time::Init()
{
	QueryPerformanceFrequency(&cpu_freq);
	QueryPerformanceCounter(&pre_freq);
}

void Time::Update()
{
	QueryPerformanceCounter(&cur_freq);

	float freq_diff
		= static_cast<float>(cur_freq.QuadPart - pre_freq.QuadPart);

	delta_time = freq_diff / static_cast<float>(cpu_freq.QuadPart);

	pre_freq.QuadPart = cur_freq.QuadPart;
}

void Time::Render(HDC hdc)
{
	static float time = 0.0f;
	time += delta_time;

	float fps = 1.0f / delta_time;

	wchar_t str[50] = L"";
	swprintf_s(str, 50, L"Time : %d", static_cast<int>(fps));

	int len = wcsnlen_s(str, 50);
	TextOutW(hdc, 0, 0, str, len);
}