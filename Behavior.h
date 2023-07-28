#pragma once
#include "Ball.h"
#include "Spring.h"
#include "Pendulum.h"

void BehaviorSpring(Spring* spring, Ball* ball);

void BehaviorSpring(Spring* spring, Ball* ball, const MyVector3& gravity);

void BehaviorCircleMovement(MyVector3* position, const float& angularVelocity, float* angle, const float& radius, const MyVector3& point);

void BehaviorCircleMovement(Ball* ball, const float& angularVelocity, float* angle, const float& radius, const MyVector3& point);

void BehaviorCircleMovement(MyVector3* position, const float& angularVelocity, float* angle, const MyVector3& point);

void BehaviorCircleMovement(Ball* ball, const float& angularVelocity, float* angle, const MyVector3& point);

void BehaviorPendulum(Pendulum* pendulum);
