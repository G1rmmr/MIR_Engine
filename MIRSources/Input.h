#pragma once

#include "CommonInclude.h"

namespace MIR
{
	enum class eKeyState
	{
		DOWN, PRESSED, UP, NONE
	};

	enum class eKeyCode
	{
		A, B, C, D, E, F, G, H, I, J, K, L, M,
		N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		LEFT, RIGHT, UP, DOWN, SPACE,
		END
	};

	const UINT MAX_KEY_SIZE = static_cast<UINT>(eKeyCode::END);

	class Input
	{
	public:
		struct Key
		{
			eKeyState state;
			eKeyCode keyCode;
			bool pressed;
		};

		static void Init();
		static void Update();

		static bool GetKeyDown(eKeyCode code)
		{
			return (*m_keys)[static_cast<UINT>(code)].state == eKeyState::DOWN;
		}

		static bool GetKeyUp(eKeyCode code)
		{
			return (*m_keys)[static_cast<UINT>(code)].state == eKeyState::UP;
		}

		static bool GetKey(eKeyCode code)
		{
			return (*m_keys)[static_cast<UINT>(code)].state == eKeyState::PRESSED;
		}

	private:
		static std::array<Key, MAX_KEY_SIZE>* m_keys;

		static void CreateKeys();
		static void UpdateKeys();
		static void UpdateKey(Input::Key& key);
		static bool IsKeyDown(eKeyCode key);
		static void UpdateKeyDown(Input::Key& key);
		static void UpdateKeyUp(Input::Key& key);
	};
}