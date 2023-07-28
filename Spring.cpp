#include "Spring.h"
#include "Novice.h"

void Spring::Draw(const MyVector3& endPos, const MyMatrix4x4& viewProjectionMatrix, const MyMatrix4x4& viewportMatrix, uint32_t color) {

	MyVector3 start = MyMatrix4x4::Transform(MyMatrix4x4::Transform(anchor, viewProjectionMatrix), viewportMatrix);
	MyVector3 end = MyMatrix4x4::Transform(MyMatrix4x4::Transform(endPos, viewProjectionMatrix), viewportMatrix);

	Novice::DrawLine(int(start.x), int(start.y), int(end.x), int(end.y), color);
}