#include "App.h"
#include "Input.h"
#include "Time.h"

using namespace MIR;

App::App() :
	m_hwnd(nullptr),
	m_front_hdc(nullptr),
	m_back_hdc(nullptr),
	m_buf(nullptr),
	m_speed(500.0f),
	m_width(0),
	m_height(0)
{
	m_objects = new std::vector<Rect>;
}

App::~App()
{
	delete m_objects;
}

void App::Initialize(const HWND hwnd, UINT width, UINT height)
{
	AdjustWindow(hwnd, width, height);
	CreateBuffer(width, height);

	Rect rect;

	rect.SetPos(500.0f, 500.0f);
	rect.SetSize(100.0f, 100.0f);

	
	m_objects->emplace_back(Rect{});

	InitEtc();
}

void App::Run()
{
	Update();
	LateUpdate();
	Render();
}

void App::Update()
{
	Input::Update();
	Time::Update();

	for (auto& object : *m_objects) object.Update(m_speed);
}

void App::LateUpdate()
{

}

void App::Render()
{
	ClearRenderTarget();
	Time::Render(m_back_hdc);

	for (auto& object : *m_objects) object.Render(m_back_hdc);
	CopyRenderTarget(m_back_hdc, m_front_hdc);
}

void App::ClearRenderTarget()
{
	Rectangle(m_back_hdc, -1, -1, 1601, 901);
}

void App::CopyRenderTarget(HDC source, HDC dest)
{
	BitBlt(dest, 0, 0, m_width, m_height, source, 0, 0, SRCCOPY);
}

void App::AdjustWindow(const HWND hwnd, UINT width, UINT height)
{
	m_hwnd = hwnd;
	m_front_hdc = GetDC(hwnd);

	RECT rect = { 0, 0, static_cast<LONG>(width), static_cast<LONG>(height) };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false); 

	m_width = rect.right - rect.left;
	m_height = rect.bottom - rect.top;

	SetWindowPos(m_hwnd, nullptr, 0, 0, m_width, m_height, 0);
	ShowWindow(m_hwnd, true);
}

void App::CreateBuffer(UINT width, UINT height)
{
	m_buf = CreateCompatibleBitmap(m_front_hdc, width, height);
	m_back_hdc = CreateCompatibleDC(m_front_hdc);

	HBITMAP old_bitmap = static_cast<HBITMAP>(SelectObject(m_back_hdc, m_buf));
	DeleteObject(old_bitmap);
}

void App::InitEtc()
{
	Input::Init();
	Time::Init();
}