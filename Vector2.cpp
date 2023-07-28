#include "MyVector2.h"
#include <cmath>

float MyVector2::Length() {
	float result = static_cast<float>(sqrt(powf(this->x, 2) + powf(this->y, 2)));
	return result;
}

float MyVector2::Length(const MyVector2& pos) {
	float result = static_cast<float>(
		sqrt(powf(this->x - pos.x, 2) + powf(this->y - pos.y, 2)));
	return result;
}

MyVector2 MyVector2::Normalize() {
	float len = Length();

	MyVector2 result = {};

	if (len != 0) {
		result = { this->x / len, this->y / len };
	}

	return result;
}

MyVector2 operator+(const MyVector2& obj1, const MyVector2& obj2) {
	MyVector2 tmp = {};
	tmp.x = obj1.x + obj2.x;
	tmp.y = obj1.y + obj2.y;
	return tmp;
}

MyVector2 operator-(const MyVector2& obj1, const MyVector2& obj2) {
	MyVector2 tmp = {};
	tmp.x = obj1.x - obj2.x;
	tmp.y = obj1.y - obj2.y;
	return tmp;
}

MyVector2 operator*(const MyVector2& obj, float a) {
	MyVector2 tmp = {};

	tmp.x = obj.x * a;
	tmp.y = obj.y * a;
	return tmp;
}

MyVector2 operator*(float a, const MyVector2& obj) {
	return obj * a;
}


MyVector2 operator/(const MyVector2& obj, float a) {
	MyVector2 tmp = {};

	tmp.x = obj.x / a;
	tmp.y = obj.y / a;
	return tmp;
}