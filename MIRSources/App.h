#pragma once

#include "CommonInclude.h"

#include "Rect.h"
#include "Circle.h"

namespace MIR
{
	class App
	{
	public:
		App();
		~App();

		void Initialize(const HWND hwnd, UINT width, UINT height);

		void Run();

		void Update();
		void LateUpdate();

		void Render();

	private:
		std::vector<GameObject*>* m_objects;

		HWND m_hwnd;
		
		HDC m_front_hdc;
		HDC m_back_hdc;

		HBITMAP m_buf;

		UINT m_width;
		UINT m_height;

		float m_speed;
	};
}


