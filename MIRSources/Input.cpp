#include "Input.h"

using namespace MIR;

std::array<int, MAX_KEY_SIZE> g_ascii =
{
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
	'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, VK_SPACE
};

std::array<Input::Key, MAX_KEY_SIZE>* Input::m_keys
	= new std::array<Input::Key, MAX_KEY_SIZE>;

void Input::Init()
{
	CreateKeys();
}

void Input::Update()
{
	UpdateKeys();
}

void Input::CreateKeys()
{
	eKeyCode now_code = eKeyCode::A;

	for (auto& key : *m_keys)
	{
		key.pressed = false;
		key.state = eKeyState::NONE;
		key.keyCode = now_code;

		now_code = static_cast<eKeyCode>(static_cast<UINT>(now_code) + 1);
	}
}

void Input::UpdateKeys()
{
	for (auto& key : *m_keys) UpdateKey(key);
}

void Input::UpdateKey(Input::Key& key)
{
	IsKeyDown(key.keyCode) ? UpdateKeyDown(key) : UpdateKeyUp(key);
}

bool Input::IsKeyDown(eKeyCode code)
{
	return GetAsyncKeyState(g_ascii[static_cast<UINT>(code)]) & 0x8000;
}

void Input::UpdateKeyDown(Input::Key& key)
{
	key.state = key.pressed ? eKeyState::PRESSED : eKeyState::DOWN;
	key.pressed = true;
}

void Input::UpdateKeyUp(Input::Key& key)
{
	key.state = key.pressed ? eKeyState::UP : eKeyState::NONE;
	key.pressed = false;
}