#include "stdafx.h"
#include "Player.h"
#include "graphics/effect/EffectEmitter.h"

Player::Player() {

	pos.x = 0.0f;
	pos.y = 40.0f;
	pos.z = 0.0f;

}

Player::~Player() {



}

void Player::Update() {


	/*
	float StickX = g_pad[0]->GetLStickXF();

	if (StickX > 0.0f && pos.x >= 450.0f) {

	}

	else if (StickX < 0.0f && pos.x <= -450.0f) {

	}

	else {

		pos.x += StickX * 5.0f;

	}
	
	*/

	EffectEmitter* ef = FindGO<EffectEmitter>("Gunef");
	
	if (g_pad[0]->IsPress(enButtonRight)) {

		if (pos.x < 450.0f) {

			pos.x += Speed;

			if (ef) {

				Vector3 efPos = ef->GetPosition();
				efPos.x += Speed;
				ef->SetPosition(efPos);

			}

		}

	}

	if (g_pad[0]->IsPress(enButtonLeft)) {

		if (pos.x > -450.0f) {

			pos.x -= Speed;

			if (ef) {

				Vector3 efPos = ef->GetPosition();
				efPos.x -= Speed;
				ef->SetPosition(efPos);

			}

		}
		
	}


	// ƒJƒƒ‰ˆÚ“®
	Vector3 CameraPos;

	CameraPos.x = pos.x;
	CameraPos.y = pos.y;
	CameraPos.z = pos.z;

	g_camera3D->SetPosition(CameraPos);

	if (shake > 0 && shake < 5) {

		CameraPos.x -= 20;

		shake++;

	}

	else if (shake >= 5 && shake < 10) {

		CameraPos.x += 20;

		shake++;

	}

	else {

		CameraPos.x = pos.x;
		shake = 0;

	}



	Vector3 target;

	target.x = CameraPos.x;
	target.y = CameraPos.y + addY;
	target.z = CameraPos.z + 300.0f;

	g_camera3D->SetTarget(target);

	if (addY > 0) {

		addY -= 1;

	}

}

void Player::Render(RenderContext& rc) {



}
