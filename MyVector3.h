#pragma once
struct MyVector3
{
public:

	bool operator==(const MyVector3& obj) {
		if (x == obj.x && y == obj.y && z == obj.z) {
			return true;
		}
		return false;
	}

	//変換
	MyVector3& operator=(const MyVector3& obj) {
		x = obj.x;
		y = obj.y;
		z = obj.z;
		return *this;
	}

	//加算
	void operator+=(MyVector3 obj) {
		this->x = this->x + obj.x;
		this->y = this->y + obj.y;
		this->z = this->z + obj.z;
	}

	//減算
	void  operator-=(MyVector3 obj) {
		this->x -= obj.x;
		this->y -= obj.y;
		this->z -= obj.z;
	}

	//スカラー

	//乗算
	void operator*=(float a) {
		this->x *= a;
		this->y *= a;
		this->z *= a;
	}

	//除算
	void operator/=(float a) {
		this->x /= a;
		this->y /= a;
		this->z /= a;
	}

	float Length();

	float Length(const MyVector3& pos);

	MyVector3 Normalize();

public:
	float x;
	float y;
	float z;
};

MyVector3 operator+(const MyVector3& obj1, const MyVector3& obj2);

//減算
MyVector3 operator-(const MyVector3& obj1, const MyVector3& obj2);

//スカラー
//乗算
MyVector3 operator*(float a, const MyVector3& obj);

MyVector3 operator*(const MyVector3& obj, float a);

//除算
MyVector3 operator/(const MyVector3& obj, float a);

MyVector3 operator+(const MyVector3& obj);

MyVector3 operator-(const MyVector3& obj);