#include "stdafx.h"
#include "Game.h"
#include "Enemy.h"
#include "Player.h"
#include "Gun.h"
#include "GunUI.h"
#include "sound/SoundEngine.h"
#include "Floor.h"
#include "Wall.h"
#include "Tree.h" 
#include "EnemyGenerator.h"
#include "HPUI.h"
#include "HP.h"
#include "nature/SkyCube.h"
#include "graphics/RenderingEngine.h"
#include "Score.h"
#include "Bullet.h"
#include "Fade.h"

void Game::InitSky() {

	DeleteGO(m_skyCube);
	m_skyCube = NewGO<SkyCube>(0, "skycube");

	m_skyCube->SetLuminance(1.0f);
	m_skyCube->SetType((EnSkyCubeType)m_skyCubeType);

	// 環境光の計算のためのIBLテクスチャをセットする。
	g_renderingEngine->SetAmbientByIBLTexture(m_skyCube->GetTextureFilePath(), 1.0f);
	// 環境日光の影響が分かりやすいように、ディレクションライトはオフに。
	//g_renderingEngine->SetDirectionLight(0, g_vec3Zero, g_vec3Zero);

}

Game::Game() {

	/*
	Vector3 pointLightPosition = {0.0f,0.0f,600.0f};

	m_pointLight.Init();
	m_pointLight.SetPosition(pointLightPosition);
	m_pointLight.SetColor(Vector3(100.0f, 100.0f, 100.0f));
	m_pointLight.SetAffectPowParam(0.7f);

	m_pointLight.SetRange(range);

	g_renderingEngine->SetAmbient({ 10,0,0 });
	*/
}

Game::~Game() {

	Fade* f = NewGO <Fade>(0, "fade");
	f->StartFadeIn();

	DeleteGO(enemyGenerator);
	DeleteGO(player);
	DeleteGO(gunUI);
	DeleteGO(gun);
	DeleteGO(hpUI);
	hp->Hp = 3;
	hp->Restart = 1;
	hp->Score = 0;
	DeleteGO(BGM);
	DeleteGO(floor);
	DeleteGO(m_skyCube);
	DeleteGO(wall);


}

bool Game::Start()
{

	InitSky();

	g_camera3D->SetNear(0.1f);

	g_camera3D->SetFar(40000.0f);

	//UIの描画
	gunUI = NewGO<GunUI>(0, "GunUI");

	hp = FindGO<HP>("hp");

	if (!hp)
	hp=NewGO<HP>(0, "hp");

	for (int i = 1; i <= hp->Hp; i++) {

		hpUI = NewGO<HPUI>(0, "HPUI" + i);
		hpUI->pos.x = 850 - i * 70;
		hpUI->num = i;

	}

	if (hp->Restart == 0) {

		for (int i = 0; i < 8; i++) {

			Enemy* enemy = NewGO<Enemy>(0, "Enemy" + i);

				enemy->pos.y = -500;
				enemy->available = 0;

		}

		for (int i = 1; i < 7; i++) {

			tree = NewGO<Tree>(0, "tree" + i);

			if (i < 4) {

				tree->pos.x = 600;
				tree->pos.z = 350 * i + i * 50;

			}

			else if (i < 7) {

				tree->pos.x = -600;
				tree->pos.z = 350 * (i - 3) + i * 50;

			}

			tree->modelRender.SetPosition(tree->pos);

		}

	}

	player = NewGO<Player>(0,"player");
	gun = NewGO<Gun>(0, "Gun");

	//BGM

	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/kongyo.wav");

	BGM = NewGO<SoundSource>(0);

	BGM->Init(0);

	BGM->Play(true);

	BGM->SetVolume(0.3f);

	//MAPの描画

	floor=NewGO<Floor>(0);
	wall=NewGO<Wall>(0);

	enemyGenerator=NewGO<EnemyGenerator>(0);

	return true;
}

void Game::Update()
{


	/*
	g_renderingEngine->SetDirectionLight(
		1,				// ライトの番号
		lightpos,	// 方向
		{ 100, 0, 0 }	// カラー
	);

	lightpos.x += 1;
	lightpos.y += 1;

	if (lightpos.x == 2) lightpos.x = -1;
	if (lightpos.y == 2) lightpos.y = -1;
	*/

	 hp = FindGO<HP>("hp");

	if (hp && 0>=hp->Hp) {

		NewGO<Score>(0);
		hp->Hp = 3;

		/*for (int i = 0; i < 8; i++) {

			Enemy* enemy = FindGO<Enemy>("Enemy" + i);

			DeleteGO(enemy);

		}

		for (int i = 1; i < 7; i++) {

			tree = FindGO<Tree>("tree" + i);
			DeleteGO(tree);

		}
		

		for (int i = 0; i < gun->bulletCount + 10; i++) {

			Bullet* bullet = FindGO<Bullet>("Bullet" + i);

			if (bullet) {

				DeleteGO(bullet);

			}

		}

		*/

		DeleteGO(this);


	}

	range += 10;

	//m_pointLight.SetRange(range);

	if (range > 200) range = 50;

	//m_pointLight.Update();

	waitFrame++;
	// g_renderingEngine->DisableRaytracing();
	//m_modelRender.Update();
}

void Game::Render(RenderContext& rc)
{
	//m_modelRender.Draw(rc);
}

