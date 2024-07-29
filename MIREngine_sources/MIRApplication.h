#pragma once

#include "CommonInclude.h"

namespace MIR
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(const HWND hwnd);

		void Run();

		void Update();
		void PostUpdate();

		void Render();

	private:
		HWND m_hwnd;
		HDC m_hdc;

		float m_speed;
		float m_x;
		float m_y;
	};
}


