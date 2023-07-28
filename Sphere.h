#pragma once
#include"MyVector3.h"
#include"MyMatrix4x4.h"
#include<cstdint>

struct Sphere
{
public:
	/*Sphere(const MyVector3& center, const float& radius);

	Sphere(const MyVector3& center, const MyVector3& rotate, const float& radius);

	Sphere(const MyVector3& center, const MyVector3& scale, const MyVector3& rotate, const float& radius);*/

	void Initialize(const MyVector3& center, const float& radius);
	void Initialize(const MyVector3& center, const MyVector3& rotate, const float& radius);
	void Initialize(const MyVector3& center, const MyVector3& scale, const MyVector3& rotate, const float& radius);

	void Draw(const MyMatrix4x4& viewProjectionMatrix, const MyMatrix4x4& viewportMatrix, uint32_t color);

private:
	

public:
	MyVector3 center_;
	MyVector3 scale_;
	MyVector3 rotate_;
	float radius_;
};

