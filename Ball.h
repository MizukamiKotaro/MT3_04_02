#pragma once
#include "MyVector3.h"
#include"MyMatrix4x4.h"

struct  Ball
{
public:
	void Draw(const MyMatrix4x4& viewProjectionMatrix, const MyMatrix4x4& viewportMatrix);

public:
	MyVector3 position; // 位置
	MyVector3 velocity; // 速度
	MyVector3 acceleration; // 加速度
	float mass; // 質量
	float radius; // 半径
	unsigned int color; // 色
};
