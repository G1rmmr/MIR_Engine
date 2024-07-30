#pragma once

#include "GameObject.h"

class Rect : public MIR::GameObject
{
public:
	Rect();
	virtual ~Rect() override;

	virtual void Update(float speed) override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;

	void SetPos(float x, float y)
	{
		m_x = x;
		m_y = y;
	}

	float GetX() const { return m_x; }
	float GetY() const { return m_y; }

private:
	float m_x;
	float m_y;
};