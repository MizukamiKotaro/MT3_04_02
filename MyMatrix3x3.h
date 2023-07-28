#pragma once
#include"MyVector2.h"

class MyMatrix3x3 
{
public:
	static MyMatrix3x3 Add(const MyMatrix3x3 m1, const MyMatrix3x3& m2);

	static MyMatrix3x3 Subtract(const MyMatrix3x3& m1, const MyMatrix3x3& m2);

	static MyMatrix3x3 Multiply(const MyMatrix3x3& m1, const MyMatrix3x3& m2);

	static MyMatrix3x3 Multiply(float num, const MyMatrix3x3& m);

	static MyVector2 Multiply(const MyVector2& vector, const MyMatrix3x3& m);

	static MyMatrix3x3 Inverse(const MyMatrix3x3& m);

	MyMatrix3x3 Inverse();

	static MyMatrix3x3 MakeAffineTransformMatrix(const MyVector2& scale, float radian, const MyVector2& translate);

	static float SarrasRule(const MyMatrix3x3& m);

	static MyMatrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom);

	static MyMatrix3x3 MakeViewportMatrix(float left, float top, float right, float bottom);

	static MyMatrix3x3 MakeWvpVpMatrix(const MyVector2& objectScale, float objectRadian, const MyVector2& objectTranslate,
		const MyVector2& cameraScale, float cameraRadian, const MyVector2& cameraTranslate,
		const MyVector2& orthoTopLeft, const MyVector2& orthoBottomRight, const MyVector2& viewportTopLeft, const MyVector2& viewportBottomRight);

public:
	float m[3][3];
};

MyMatrix3x3 operator+(const MyMatrix3x3 m1, const MyMatrix3x3& m2);

MyMatrix3x3 operator-(const MyMatrix3x3 m1, const MyMatrix3x3& m2);

MyMatrix3x3 operator*(const MyMatrix3x3 m1, const MyMatrix3x3& m2);

MyMatrix3x3 operator*(float s, const MyMatrix3x3& m);

MyMatrix3x3 operator*(const MyMatrix3x3& m, float s);

MyVector2 operator*(const MyVector2& v, const MyMatrix3x3& m);

MyVector2 operator*(const MyMatrix3x3& m, const MyVector2& v);