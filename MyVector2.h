#pragma once
struct MyVector2
{
public:
	

	MyVector2& operator=(const MyVector2& obj) {
		x = obj.x;
		y = obj.y;
		return *this;
	}

	void operator+=(const MyVector2& obj) {
		this->x = this->x + obj.x;
		this->y = this->y + obj.y;
	}

	void  operator-=(const MyVector2& obj) {
		this->x -= obj.x;
		this->y -= obj.y;
	}

	void operator*=(float a) {
		this->x *= a;
		this->y *= a;
	}

	void operator/=(float a) {
		this->x /= a;
		this->y /= a;
	}

	float Length();

	float Length(const MyVector2& pos);

	MyVector2 Normalize();

public:
	float x;
	float y;
};

MyVector2 operator+(const MyVector2& obj1, const MyVector2& obj2);

MyVector2 operator-(const MyVector2& obj1, const MyVector2& obj2);

MyVector2 operator*(const MyVector2& obj, float a);

MyVector2 operator*(float a, const MyVector2& obj);

MyVector2 operator/(const MyVector2& obj, float a);