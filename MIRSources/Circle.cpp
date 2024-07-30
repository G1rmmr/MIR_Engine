#include "Circle.h"
#include "Input.h"
#include "Time.h"

using namespace MIR;

Circle::Circle() : m_x(0.0f), m_y(0.0f), m_radius(50.0f)
{

}

Circle::~Circle()
{
	delete this;
}

void Circle::Update(float speed)
{
	m_y -= 2.0f * speed * Time::GetDeltaTime();
}

void Circle::LateUpdate()
{

}

void Circle::Render(HDC hdc)
{
	Ellipse(hdc,
		m_x - m_radius,
		m_y - m_radius,
		m_x + m_radius,
		m_y + m_radius);
}