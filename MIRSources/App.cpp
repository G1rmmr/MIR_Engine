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
	m_width(0.0f),
	m_height(0.0f),
	m_can_fire(true)
{
	// m_objects = new std::vector<GameObject*>;
	m_player = new Rect{};
	m_player->SetPos(500.0f, 500.0f);

	m_bullet = new Circle{};
	m_bullet->SetPos(m_player->GetX(), m_player->GetY());
}

App::~App()
{
	delete m_player;
	delete m_bullet;
}

void App::Initialize(const HWND hwnd, UINT width, UINT height)
{
	m_hwnd = hwnd;
	m_front_hdc = GetDC(hwnd);

	RECT rect = { 0, 0, width, height };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	m_width = rect.right - rect.left;
	m_height = rect.bottom - rect.top;

	// Double buffering (Trick)

	SetWindowPos(m_hwnd, nullptr, 0, 0, m_width, m_height, 0);
	ShowWindow(m_hwnd, true);

	m_buf = CreateCompatibleBitmap(m_front_hdc, width, height);
	m_back_hdc = CreateCompatibleDC(m_front_hdc);

	HBITMAP old_bitmap = static_cast<HBITMAP>(SelectObject(m_back_hdc, m_buf));
	DeleteObject(old_bitmap);

	//m_objects->emplace_back(new Rect{});
	//m_objects->emplace_back(new Circle{});

	Input::Init();
	Time::Init();
}

void App::Run()
{
	Update();
	LateUpdate();
	Render();
}

void App::UpdateBullet()
{
	float x = m_bullet->GetX();
	float y = m_bullet->GetY();

	if (m_can_fire) m_bullet->SetPos(m_player->GetX(), m_player->GetY());
	else
	{
		m_bullet->SetPos(x, y - 2.0f * m_speed * Time::GetDeltaTime());
	}

	if (y < 0.0f)
	{
		m_can_fire = true;
	}

	if (Input::GetKey(eKeyCode::SPACE))
	{
		m_can_fire = false;
	}
}

void App::Update()
{
	Input::Update();
	Time::Update();

	m_player->Update(m_speed);
	UpdateBullet();

	//for (auto& object : *m_objects)
	//{
	//	object->Update(m_speed);
	//}
}

void App::LateUpdate()
{

}

void App::Render()
{
	Rectangle(m_back_hdc, 0, 0, 1600, 900);

	Time::Render(m_back_hdc);

	m_player->Render(m_back_hdc);

	if(!m_can_fire) m_bullet->Render(m_back_hdc);

	//for (auto& object : *m_objects)
	//{
	//	object->Render(m_back_hdc);
	//}

	// Buffering
	BitBlt(m_front_hdc, 0, 0, m_width, m_height, m_back_hdc, 0, 0, SRCCOPY);
}