#pragma once

#include "GameObject.h"

class Rect : public MIR::GameObject
{
public:
	Rect();
	~Rect() override;

	void Update(float speed) override;
	void LateUpdate() override;
	void Render(HDC hdc) override;

	void SetPos(float x, float y)
	{
		m_x = x;
		m_y = y;
	}

	void SetSize(float width, float height)
	{
		m_width = width;
		m_height = height;
	}

	float GetX() const { return m_x; }
	float GetY() const { return m_y; }
	float GetWidth() const { return m_width; }
	float GetHeight() const { return m_height; }

private:
	float m_x;
	float m_y;
	float m_width;
	float m_height;
};