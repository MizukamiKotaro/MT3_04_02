#pragma once
#include "MyVector3.h"
#include "MyMatrix4x4.h"
#include<cstdint>

class Draw
{
public:
	static void DrawBezier(const MyVector3& p0, const MyVector3& p1, const MyVector3& p2,
		const MyMatrix4x4& viewProjectionMatrix, const MyMatrix4x4& viewportMatrix, uint32_t color);

	static void DrawCatmullRom(const MyVector3& p0, const MyVector3& p1, const MyVector3& p2, const MyVector3& p3,
		const MyMatrix4x4& viewProjectionMatrix, const MyMatrix4x4& viewportMatrix, uint32_t color);
};

