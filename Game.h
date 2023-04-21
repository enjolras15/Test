#pragma once

#include "Level3DRender/LevelRender.h"
#include "sound/SoundSource.h"

class Player;
class Enemy;
class Tree;
class Gun;
class EnemyGenerator;
class Floor;
class Wall;
class GunUI;
class HP;
class HPUI;

class Game : public IGameObject
{

public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void InitSky();
	int x;

private:

	ModelRender m_modelRender;
	Vector3 m_pos;
	SoundSource* BGM;
	//int EnemyCount = 0;
	int waitFrame = 0;
	SkyCube* m_skyCube = nullptr;
	int m_skyCubeType = enSkyCubeType_Day;
	LevelRender	m_levelRender;
	Tree* tree;
	Gun* gun;
	EnemyGenerator* enemyGenerator;
	Player* player;
	Floor* floor;
	Wall* wall;
	GunUI* gunUI;
	HP* hp;
	HPUI* hpUI;
	Vector3 lightpos = { 1,1,0 };
	PointLight m_pointLight;
	float range = 100.0f;

	//Enemy* enemy;

};

