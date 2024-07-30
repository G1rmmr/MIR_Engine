#pragma once

#include "CommonInclude.h"

namespace MIR
{
	class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject() = 0;
		
		virtual void Update(float speed) = 0;
		virtual void LateUpdate() = 0;
		virtual void Render(HDC hdc) = 0;
	};
}

