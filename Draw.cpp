#include "Draw.h"
#include "Novice.h"
#include "calc.h"

void Draw::DrawBezier(const MyVector3& p0, const MyVector3& p1, const MyVector3& p2,
	const MyMatrix4x4& viewProjectionMatrix, const MyMatrix4x4& viewportMatrix, uint32_t color) {
	
	const int kDivisionNum = 32;

	MyVector3 bezier0 = {};
	MyVector3 bezier1 = {};

	float t0 = 0;
	float t1 = 0;

	for (int index = 0; index < kDivisionNum; index++) {
		t0 = float(index) / kDivisionNum;
		t1 = float(index + 1) / kDivisionNum;

		bezier0 = Calc::Bezier(p0, p1, p2, t0);
		bezier1 = Calc::Bezier(p0, p1, p2, t1);

		bezier0 = MyMatrix4x4::Transform(MyMatrix4x4::Transform(bezier0, viewProjectionMatrix), viewportMatrix);
		bezier1 = MyMatrix4x4::Transform(MyMatrix4x4::Transform(bezier1, viewProjectionMatrix), viewportMatrix);


		Novice::DrawLine(static_cast<int>(bezier0.x), static_cast<int>(bezier0.y), static_cast<int>(bezier1.x), static_cast<int>(bezier1.y), color);
	}
}

void  Draw::DrawCatmullRom(const MyVector3& p0, const MyVector3& p1, const MyVector3& p2, const MyVector3& p3,
	const MyMatrix4x4& viewProjectionMatrix, const MyMatrix4x4& viewportMatrix, uint32_t color) {
	const int kDivisionNum = 32;

	for (int index = 0; index < kDivisionNum; index++) {
		float t0 = index / float(kDivisionNum);
		float t1 = (index + 1) / float(kDivisionNum);

		MyVector3 catmull0 = Calc::Catmull_rom(p0, p0, p1, p2, t0);
		MyVector3 catmull01 = Calc::Catmull_rom(p0, p0, p1, p2, t1);
		MyVector3 catmull1 = Calc::Catmull_rom(p0, p1, p2, p3, t0);
		MyVector3 catmull11 = Calc::Catmull_rom(p0, p1, p2, p3, t1);
		MyVector3 catmull2 = Calc::Catmull_rom(p1, p2, p3, p3, t0);
		MyVector3 catmull21 = Calc::Catmull_rom(p1, p2, p3, p3, t1);

		catmull0 = MyMatrix4x4::Transform(MyMatrix4x4::Transform(catmull0, viewProjectionMatrix), viewportMatrix);
		catmull01 = MyMatrix4x4::Transform(MyMatrix4x4::Transform(catmull01, viewProjectionMatrix), viewportMatrix);
		catmull1 = MyMatrix4x4::Transform(MyMatrix4x4::Transform(catmull1, viewProjectionMatrix), viewportMatrix);
		catmull11 = MyMatrix4x4::Transform(MyMatrix4x4::Transform(catmull11, viewProjectionMatrix), viewportMatrix);
		catmull2 = MyMatrix4x4::Transform(MyMatrix4x4::Transform(catmull2, viewProjectionMatrix), viewportMatrix);
		catmull21 = MyMatrix4x4::Transform(MyMatrix4x4::Transform(catmull21, viewProjectionMatrix), viewportMatrix);

		Novice::DrawLine(static_cast<int>(catmull0.x), static_cast<int>(catmull0.y), static_cast<int>(catmull01.x), static_cast<int>(catmull01.y), color);
		Novice::DrawLine(static_cast<int>(catmull1.x), static_cast<int>(catmull1.y), static_cast<int>(catmull11.x), static_cast<int>(catmull11.y), color);
		Novice::DrawLine(static_cast<int>(catmull2.x), static_cast<int>(catmull2.y), static_cast<int>(catmull21.x), static_cast<int>(catmull21.y), color);
	}
}
