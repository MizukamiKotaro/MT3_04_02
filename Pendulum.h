#pragma once
#include "MyVector3.h"
#include"MyMatrix4x4.h"
#include<cstdint>

struct Pendulum
{

	MyVector3 anchor; // アンカーポイント。固定された端の位置
	MyVector3 endPos; // 固定されてない方の端
	float length; // 紐の長さ
	float angle; // 現在の角度
	float angularVelocity; // 角速度
	float angularAcceleration; // 角加速度

	void Draw(const MyMatrix4x4& viewProjectionMatrix, const MyMatrix4x4& viewportMatrix, uint32_t color);

};

