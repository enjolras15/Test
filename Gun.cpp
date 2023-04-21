#include "stdafx.h"
#include "Gun.h"
#include "GunUI.h"
#include "Player.h"
#include "Bullet.h"
#include "sound/SoundEngine.h"
#include "graphics/effect/EffectEmitter.h"
#include "game.h"

Gun::Gun() {

	Game* game = FindGO<Game>("game");
	type = game->x;

	if (type == 0) {

		modelRender.Init("Assets/modelData/Gun.tkm");

	}

	else if (type == 1) {

		maxMagazine = 10;
		magazine = maxMagazine+1;

		modelRender.Init("Assets/modelData/Gun2.tkm");

	}


	player = FindGO<Player>("player");

	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/shot.wav");
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/reload.wav");
    angle = g_camera3D->GetViewAngle();

	EffectEngine::GetInstance()->ResistEffect(0, u"Assets/effect/hit.efk");


}

Gun::~Gun() {



}

void Gun::Update() {

	player->Speed = 4.0f;

	g_camera3D->SetViewAngle(angle);

	float StickY = g_pad[0]->GetLStickYF();

	rot.SetRotationDegY(90.0f);

	ADS = 0;
		pos.x = player->pos.x + 50.0f;

		if (animationFrame == 0) {

			pos.y = player->pos.y - 17.0f;
			pos.z = player->pos.z + 32.0f;

		}

		if (g_pad[0]->IsPress(enButtonRB1)) {

			rot.SetRotationDegY(94.0f);

			pos.x = player->pos.x + 39.7f;
			pos.y = player->pos.y - 6.0f;
			pos.z = player->pos.z + 10.0f;

			player->Speed = 3.5f;

			g_camera3D->SetViewAngle(angle-0.1f);

			ADS = 1;

		}

		if (magazine > 0) {

			if (type == 0) {

				if (g_pad[0]->IsTrigger(enButtonA)) {

					Shot();

				}

			}

			else if (type == 1) {

				if (g_pad[0]->IsPress(enButtonA)) {

					if (coolDown == 0) {

						Shot();
						coolDown = 10;
					}

				}

			}

			if (g_pad[0]->IsTrigger(enButtonB) && magazine<maxMagazine) {
			
					magazine = 0;
					reloading = 50;

			}
		}

		else {

			if (g_pad[0]->IsPress(enButtonA) && coolDown==0 && type==1 ||
				g_pad[0]->IsTrigger(enButtonA) && type == 0 ||
				g_pad[0]->IsTrigger(enButtonB)) {

				if (reloading==0)
					reloading = 50;

			}
		}

		if (reloading > 0) {

			if (reloading == 20) {

				SE = NewGO<SoundSource>(0);

				SE->Init(2);

				SE->Play(false);

			}

			pos.y = player->pos.y - 30.0f;

			reloading -= 1;

			if (reloading == 0) {

				magazine = maxMagazine;
			}

		}


		if (animationFrame > 0) {

			animationFrame--;

			if (ADS == 0) {
				pos.y = player->pos.y - 17.0f;
				pos.y = pos.y + 3.0f;
			}

			if (animationFrame <= 7) {

				effectEmitter->Stop();

			}

		}
		
		if (coolDown>0)
			coolDown--;

	modelRender.SetRotation(rot);
	modelRender.SetPosition(pos);
	modelRender.Update();

}

void Gun::Render(RenderContext& rc) {

	modelRender.Draw(rc);

}

void Gun::Shot() {

	if (animationFrame <= 0) {

		pos.y = pos.y + 3.0f;

	}

	if (4 > player->addY) {

		player->addY += 4;

	}
	

	magazine -= 1;
	animationFrame = 10;

	effectEmitter = NewGO<EffectEmitter>(0, "Gunef");

	if (ADS == 0) {
		pos.y += 4;

	}

	else {

		pos.y += 2;

	}

	if (type == 1) {

		pos.z += 6;

	}

	else {

		pos.z += 3;

	}

	
	if (ADS == 1) {

		pos.x -= 38.7;

	}

	else {

		pos.x -= 39;

	}

	effectEmitter->SetPosition(pos);

	if (ADS == 0) {
		pos.y -= 4;

	}

	else {

		pos.y -= 2;

	}

	if (type == 1) {

		pos.z -= 6;

	}

	else {

		pos.z -= 3;

	}

	if (ADS==1) {

		pos.x += 38.7;

	}

	else {

		pos.x += 39;

	}

	effectEmitter->Init(0);
	effectEmitter->SetScale({ 0.5f,0.5f,0.5f });
	effectEmitter->Play();

	NewGO<Bullet>(0, "Bullet" + bulletCount);

	bulletCount++;

	if (bulletCount>9) {
		
		bulletCount = 0;

	}

	if (magazine != 10) {

		GunUI* ui = FindGO<GunUI>("GunUI");

		ui->scaleUP = 10;

		SE = NewGO<SoundSource>(0);

		SE->Init(1);

		SE->Play(false);

	}

	//SE->SetVolume(0.3f);

}