#include "Behavior.h"
#include<cmath>

void BehaviorSpring(Spring* spring, Ball* ball) {

	MyVector3 diff = ball->position - spring->anchor;
	float length = diff.Length();

	if (length != 0) {
		MyVector3 restPosition = spring->anchor + diff.Normalize() * spring->naturalLength;
		MyVector3 displacement = length * (ball->position - restPosition);
		MyVector3 restoringForce = -spring->stiffness * displacement;
		MyVector3 dampingForce = -spring->dampingCoefficient * ball->velocity;
		MyVector3 force = restoringForce + dampingForce;
		ball->acceleration = force / ball->mass;
	}
	float deltaTime = 1.0f / 60.0f;

	ball->velocity += ball->acceleration * deltaTime;
	ball->position += ball->velocity * deltaTime;
}

void BehaviorSpring(Spring* spring, Ball* ball, const MyVector3& gravity) {

	MyVector3 diff = ball->position - spring->anchor;
	float length = diff.Length();

	if (length != 0) {
		MyVector3 restPosition = spring->anchor + diff.Normalize() * spring->naturalLength;
		MyVector3 displacement = length * (ball->position - restPosition);
		MyVector3 restoringForce = -spring->stiffness * displacement;
		MyVector3 dampingForce = -spring->dampingCoefficient * ball->velocity;
		MyVector3 force = restoringForce + dampingForce + gravity;
		ball->acceleration = force / ball->mass;
	}
	float deltaTime = 1.0f / 60.0f;

	ball->velocity += ball->acceleration * deltaTime;
	ball->position += ball->velocity * deltaTime;

}

void BehaviorCircleMovement(MyVector3* position, const float& angularVelocity, float* angle, const float& radius, const MyVector3& point) {

	float deltaTime = 1.0f / 60.0f;
	*angle += angularVelocity * deltaTime;

	position->x = point.x + std::cos(*angle) * radius;
	position->y = point.y + std::sin(*angle) * radius;
	position->z = point.z;

}

void BehaviorCircleMovement(Ball* ball, const float& angularVelocity, float* angle, const float& radius, const MyVector3& point) {

	float deltaTime = 1.0f / 60.0f;
	*angle += angularVelocity * deltaTime;

	ball->position.x = point.x + std::cos(*angle) * radius;
	ball->position.y = point.y + std::sin(*angle) * radius;
	ball->position.z = point.z;

	//加速度でする場合、初速与えないとダメ
	//半径を引数にしているがpointとの距離から作った方がよさそう
	/*float n = -powf(angularVelocity, 2.0f) * radius;
	ball->acceleration.x = n * std::cos(*angle);
	ball->acceleration.y = n * std::sin(*angle);
	ball->acceleration.z = 0.0f;

	ball->velocity += ball->acceleration * deltaTime;
	ball->position += ball->velocity * deltaTime;*/
}

void BehaviorCircleMovement(MyVector3* position, const float& angularVelocity, float* angle, const MyVector3& point) {

	float deltaTime = 1.0f / 60.0f;
	*angle += angularVelocity * deltaTime;

	float radius = position->Length(point);

	position->x = point.x + std::cos(*angle) * radius;
	position->y = point.y + std::sin(*angle) * radius;
	position->z = point.z;

}

void BehaviorCircleMovement(Ball* ball, const float& angularVelocity, float* angle, const MyVector3& point) {

	float deltaTime = 1.0f / 60.0f;
	*angle += angularVelocity * deltaTime;

	float radius = ball->position.Length(point);

	ball->position.x = point.x + std::cos(*angle) * radius;
	ball->position.y = point.y + std::sin(*angle) * radius;
	ball->position.z = point.z;

}

void BehaviorPendulum(Pendulum* pendulum) {

	float deltaTime = 1.0f / 60.0f;

	pendulum->angularAcceleration = -(9.8f / pendulum->length) * std::sin(pendulum->angle);
	pendulum->angularVelocity += pendulum->angularAcceleration * deltaTime;
	pendulum->angle += pendulum->angularVelocity * deltaTime;

	pendulum->endPos.x = pendulum->anchor.x + std::sin(pendulum->angle) * pendulum->length;
	pendulum->endPos.y = pendulum->anchor.y - std::cos(pendulum->angle) * pendulum->length;
	pendulum->endPos.z = pendulum->anchor.z;
}

