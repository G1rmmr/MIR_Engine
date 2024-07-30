#include "Rect.h"
#include "Input.h"
#include "Time.h"

#include <cstdio>

using namespace MIR;

Rect::Rect() : m_x(0.0f), m_y(0.0f)
{

}

Rect::~Rect()
{
	delete this;
}

void Rect::Update(float speed)
{
	if (Input::GetKey(eKeyCode::LEFT))
	{
		m_x -= speed * Time::GetDeltaTime();
	}

	if (Input::GetKey(eKeyCode::RIGHT))
	{
		m_x += speed * Time::GetDeltaTime();
	}

	if (Input::GetKey(eKeyCode::UP))
	{
		m_y -= speed * Time::GetDeltaTime();
	}

	if (Input::GetKey(eKeyCode::DOWN))
	{
		m_y += speed * Time::GetDeltaTime();
	}
}

void Rect::LateUpdate()
{

}

void Rect::Render(HDC hdc)
{
	Rectangle(hdc, 100 + m_x, 100 + m_y, 200 + m_x, 200 + m_y);
}