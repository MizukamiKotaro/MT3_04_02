#pragma once
#include "MyVector3.h"
#include"MyMatrix4x4.h"
#include<cstdint>

struct Spring {
	//アンカー。固定された端の位置
	MyVector3 anchor;
	float naturalLength; // 自然長
	float stiffness; // 剛性。ばねの定数k
	float dampingCoefficient; // 減衰係数

	void Draw(const MyVector3& endPos, const MyMatrix4x4& viewProjectionMatrix, const MyMatrix4x4& viewportMatrix, uint32_t color);

};
