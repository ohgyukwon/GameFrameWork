#include "Vector2D.h"

Vector2D operator+(const Vector2D& v2) const {
	return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
}

friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2) {
	v1.m_x += v2.m_x;
	v1.m_y += v2.m_y;
}

Vector2D operator*(float scalar) {
	return Vector2D(m_x * scalar, m_y * scalar);
}

Vector2D oprator*=(float scalar) {
	m_x *= scalar;
	m_y *= scalar;
	return *this;
}

Vector2D operator-(const Vector2D& v2) const {
	return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
}

friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2) {
	v1.m_x -= v2.m_x;
	v1.m_y -= v2.m_y;
}

Vector2D operator/(float scalar) {
	return Vector2D(m_x / scalar, m_y / scalar);
}

Vector2D oprator /= (float scalar) {
	m_x /= scalar;
	m_y /= scalar;
	return *this;
}

float length() { return sqrt(m_x * m_x + m_y * m_y); }

void normalize() {
	float l = length();
	if (l > 0) {
		(*this) *= 1 / l;
	}
}