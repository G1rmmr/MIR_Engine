#pragma once

#include "CommonInclude.h"

namespace MIR
{
	class Time
	{
	public:
		static void Init();
		static void Update();
		static void Render(HDC hdc);

		static float GetDeltaTime() { return delta_time; }

	private:
		static LARGE_INTEGER cpu_freq;
		static LARGE_INTEGER pre_freq;
		static LARGE_INTEGER cur_freq;

		static float delta_time;
	};
}