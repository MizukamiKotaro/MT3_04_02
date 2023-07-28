#include <Novice.h>
#include"MyMatrix4x4.h"
#include"MatrixScreenPrintf.h"
#include"MyVector3.h"
#include"VectorScreenPrintf.h"
#include"calc.h"
#include"Grid.h"
#include"Sphere.h"
#include<imgui.h>
#include"Line.h"
#include"Collision.h"
#include"Camera.h"
#include"Plane.h"
#include"Triangle.h"
#include"AABB.h"
#include"OBB.h"
#include"Draw.h"
#include"Spring.h"
#include"Ball.h"
#include"Behavior.h"
#include"Pendulum.h"

const char kWindowTitle[] = "学籍番号";

const int kWindowWidth = 1280;
const int kWindowHeight = 720;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};


	Pendulum pendulum{};
	pendulum.anchor = { 0.0f,1.0f,0.0f };
	pendulum.length = 0.8f;
	pendulum.angle = 0.7f;
	pendulum.angularAcceleration = 0.0f;
	pendulum.angularVelocity = 0.0f;

	bool start = false;

	BehaviorPendulum(&pendulum);

	Camera camera{};
	camera.Initialize({ 0.0f,1.9f,-6.49f }, { 0.26f,0.0f,0.0f });

	MyMatrix4x4 projectionMatrix = MyMatrix4x4::MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);
	MyMatrix4x4 viewportMatrix = MyMatrix4x4::MakeViewportMatrix(0.0f, 0.0f, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);

	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		ImGui::Begin("Window");
		ImGui::Text("SPACE : Start");
		if (ImGui::Button("Start")) {
			start = true;
		}
		ImGui::Text("R : Reset");
		if (ImGui::Button("Reset")) {
			pendulum.anchor = { 0.0f,1.0f,0.0f };
			pendulum.length = 0.8f;
			pendulum.angle = 0.7f;
			pendulum.angularAcceleration = 0.0f;
			pendulum.angularVelocity = 0.0f;

			start = false;
			BehaviorPendulum(&pendulum);

			camera.Initialize({ 0.0f,1.9f,-6.49f }, { 0.26f,0.0f,0.0f });
		}
		ImGui::End();

		if (keys[DIK_SPACE] && !start) {
			start = true;
		}

		if (start) {
			BehaviorPendulum(&pendulum);
		}

		if (keys[DIK_R]) {
			
			pendulum.anchor = { 0.0f,1.0f,0.0f };
			pendulum.length = 0.8f;
			pendulum.angle = 0.7f;
			pendulum.angularAcceleration = 0.0f;
			pendulum.angularVelocity = 0.0f;

			BehaviorPendulum(&pendulum);
			
			start = false;

			camera.Initialize({ 0.0f,1.9f,-6.49f }, { 0.26f,0.0f,0.0f });
		}

		camera.Update(keys, preKeys);

		MyMatrix4x4 cameraMatrix = MyMatrix4x4::MakeAffinMatrix(camera.GetScale(), camera.GetRotate(), camera.GetTranslate());
		MyMatrix4x4 viewMatrix = MyMatrix4x4::Inverse(cameraMatrix);
		MyMatrix4x4 viewProjectionMatrix = MyMatrix4x4::Multiply(viewMatrix, projectionMatrix);

		Sphere sphere{};
		sphere.Initialize(pendulum.endPos, 0.05f);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		Grid::DrawGrid(viewProjectionMatrix, viewportMatrix);

		pendulum.Draw(viewProjectionMatrix, viewportMatrix, 0xFFFFFFFF);

		sphere.Draw(viewProjectionMatrix, viewportMatrix, 0xFFFFFFFF);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
