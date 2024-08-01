#include "Rect.h"
#include "Input.h"
#include "Time.h"

using namespace MIR;

Rect::Rect() : m_x(0.0f), m_y(0.0f), m_width(100.0f), m_height(100.0f)
{

}

Rect::~Rect()
{
	
}

void Rect::Update(float speed)
{
	if (Input::GetKey(eKeyCode::W))
	{
		m_y -= speed * Time::GetDeltaTime();
	}

	if (Input::GetKey(eKeyCode::A))
	{
		m_x -= speed * Time::GetDeltaTime();
	}

	if (Input::GetKey(eKeyCode::S))
	{
		m_y += speed * Time::GetDeltaTime();
	}

	if (Input::GetKey(eKeyCode::D))
	{
		m_x += speed * Time::GetDeltaTime();
	}
}

void Rect::LateUpdate()
{

}

void Rect::Render(HDC hdc)
{
	Rectangle(hdc, m_x, m_y, m_width + m_x, m_height + m_y);
}