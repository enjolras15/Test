#include "stdafx.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Gun.h"
#include "HPUI.h"
#include "HP.h"
#include "graphics/effect/EffectEmitter.h"
#include "Player.h"

Enemy::Enemy() {

	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/Enemy1.tkm");
	EffectEngine::GetInstance()->ResistEffect(0, u"Assets/effect/hit.efk");

	g_soundEngine->ResistWaveFileBank(3, "Assets/sound/explode.wav");

	SetPosition();

}

Enemy::~Enemy() {



}

void Enemy::Update() {

	gun = FindGO<Gun>("Gun");

	if (gun) {

		HP* h = FindGO<HP>("hp");

		for (int i = 0; i < 10; i++) {

			bullet = FindGO<Bullet>("Bullet" + i);

			if (bullet) {

				Vector3 diff = pos - bullet->pos;

				if (diff.Length() <= 38.0f || 200 < pos.z && diff.Length() <= 40.0f) {

					//if (bullet->pos.x>=pos.x-50 && pos.x+50>=bullet->pos.x) {


					effectEmitter = NewGO<EffectEmitter>(0);
					pos.y += 20;
					effectEmitter->SetPosition(pos);
					pos.y -= 20;
					effectEmitter->Init(0);
					effectEmitter->SetScale({ 5.0f,5.0f,5.0f });
					effectEmitter->Play();

					SoundSource* SE = NewGO<SoundSource>(0);

					SE->Init(3);

					SE->Play(false);

					h->Score++;

					//DeleteGO(this);
					pos.y = -500;
					available = 0;

					DeleteGO(bullet);
					gun->bulletCount--;

				}

			}


		}



		if (150 < pos.z && available == 1) {

			if (moveMode ==0) {

				pos.z -= 4.5f;

				if (pos.x >= 280) {

					Xmove = -1.0f;

				}

				else if (-280 >= pos.x) {

					Xmove = 1.0f;

				}

					pos.x += Xmove;

			}

			else if (moveMode == 1) {

				pos.z -= 4.0f;

				if (-10 > pos.x)
					Xmove = 2;
				else if (pos.x > 10)
					Xmove =-2;
				else
					Xmove = 0;

				pos.x += Xmove;

			}

			else if (moveMode == 2) {

				pos.z -= 3.0f;

				if (pos.x >= 280) {

					Xmove = -2.0f;

				}

				else if (-280 >= pos.x) {

					Xmove = 2.0f;

				}

				pos.x += Xmove;

			}

			else {

				pos.z -= 4.5f;

			}

		}

		else {
			if (available == 1) {

				//HPUI* n = FindGO<HPUI>("HPUI" + h->Hp);
				//DeleteGO(n);

				Player* p = FindGO<Player>("player");
				p->shake = 1;

				h->Hp--;

				pos.y = -500;
				available = 0;

			}

		}

	}

	else {

		pos.y = -500;
		available = 0;

	}

	modelRender.SetPosition(pos);
	modelRender.Update();

}

void Enemy::Render(RenderContext& rc) {

	modelRender.Draw(rc);

}

void Enemy::SetPosition() {

	pos.x = rand() % 1401 - 700;

	if (-280 > pos.x) {

		pos.x = -280;

	}

	else if (280 < pos.x) {

		pos.x = 280;

	}

	pos.y = 0.0f;
	pos.z = 2000.0f;

}