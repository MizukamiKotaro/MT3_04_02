#include "MyVector3.h"
#include <cmath>

float MyVector3::Length() {
	float result = static_cast<float>(sqrt(powf(this->x, 2) + powf(this->y, 2) + powf(this->z, 2)));
	return result;
}

float MyVector3::Length(const MyVector3& pos) {
	float result = static_cast<float>(
		sqrt(powf(this->x - pos.x, 2) + powf(this->y - pos.y, 2) + powf(this->z - pos.z, 2)));
	return result;
}

MyVector3 MyVector3::Normalize() {
	float len = Length();

	MyVector3 result = {};

	if (len != 0) {
		result = { this->x / len, this->y / len, this->z / len };
	}

	return result;
}

MyVector3 operator+(const MyVector3& obj1, const MyVector3& obj2) {
	MyVector3 tmp = {};
	tmp.x = obj1.x + obj2.x;
	tmp.y = obj1.y + obj2.y;
	tmp.z = obj1.z + obj2.z;
	return tmp;
}


//減算
MyVector3 operator-(const MyVector3& obj1, const MyVector3& obj2) {
	MyVector3 tmp = {};
	tmp.x = obj1.x - obj2.x;
	tmp.y = obj1.y - obj2.y;
	tmp.z = obj1.z - obj2.z;
	return tmp;
}

//スカラー

//乗算
MyVector3 operator*(float a, const MyVector3& obj) {
	MyVector3 tmp = {};

	tmp.x = obj.x * a;
	tmp.y = obj.y * a;
	tmp.z = obj.z * a;
	return tmp;
}

MyVector3 operator*(const MyVector3& obj, float a) {
	MyVector3 tmp = {};

	tmp.x = obj.x * a;
	tmp.y = obj.y * a;
	tmp.z = obj.z * a;
	return tmp;
}

//除算
MyVector3 operator/(const MyVector3& obj, float a) {

	if (a == 0) {
		return {};
	}
	MyVector3 tmp = {};

	tmp.x = obj.x / a;
	tmp.y = obj.y / a;
	tmp.z = obj.z / a;
	return tmp;
}

MyVector3 operator+(const MyVector3& obj) {
	return obj;
}

MyVector3 operator-(const MyVector3& obj) {
	return { -obj.x,-obj.y,-obj.z };
}