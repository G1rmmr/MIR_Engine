#include "Circle.h"
#include "Input.h"
#include "Time.h"

#include <cstdio>

using namespace MIR;

Circle::Circle() : m_x(0.0f), m_y(0.0f)
{

}

Circle::~Circle()
{
	delete this;
}

void Circle::Update(float speed)
{
	if(Input::GetKey(eKeyCode::A))
	{
		m_x -= speed * Time::GetDeltaTime();
	}

	if (Input::GetKey(eKeyCode::D))
	{
		m_x += speed * Time::GetDeltaTime();
	}

	if (Input::GetKey(eKeyCode::W))
	{
		m_y -= speed * Time::GetDeltaTime();
	}

	if (Input::GetKey(eKeyCode::S))
	{
		m_y += speed * Time::GetDeltaTime();
	}
}

void Circle::LateUpdate()
{

}

void Circle::Render(HDC hdc)
{
	Ellipse(hdc, 500 + m_x, 500 + m_y, 600 + m_x, 600 + m_y);
}