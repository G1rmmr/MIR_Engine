#include "MIRApplication.h"

using namespace MIR;

Application::Application() :
	m_hwnd(nullptr),
	m_hdc(nullptr),
	m_speed(0.0f),
	m_x(0.0f),
	m_y(0.0f)
{

}

Application::~Application()
{

}

void Application::Initialize(const HWND hwnd)
{
	m_hwnd = hwnd;
	m_hdc = GetDC(hwnd);
}

void Application::Run()
{
	Update();
	PostUpdate();
	Render();
}

void Application::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_x -= 0.01f;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_x += 0.01f;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_y -= 0.01f;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_y += 0.01f;
	}
}

void Application::PostUpdate()
{

}

void Application::Render()
{
	Rectangle(m_hdc, 100 + m_x, 100 + m_y, 200 + m_x, 200 + m_y);
}