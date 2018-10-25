#pragma once

#include <math.h>

class Vector2D {
public:
	Vector2D(float x, float y) : m_x(x), m_y(y) {}
	float getX() { return m_x; }
	float getX() { return m_y; }
	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }
private:
	float m_x;
	float m_y;
};