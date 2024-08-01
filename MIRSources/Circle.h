#pragma once

#include "GameObject.h"

class Circle : public MIR::GameObject
{
public:
	Circle();
	~Circle() override;

	void Update(float speed) override;
	void LateUpdate() override;
	void Render(HDC hdc) override;

	void SetPos(float x, float y)
	{
		m_x = x;
		m_y = y;
	}

	void SetRadius(float radius) { m_radius = radius; }

	float GetX() const { return m_x; }
	float GetY() const { return m_y; }
	float GetRadius() const { return m_radius; }

private:
	float m_x;
	float m_y;
	float m_radius;
};