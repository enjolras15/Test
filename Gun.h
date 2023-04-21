#pragma once
#include "sound/SoundSource.h"

class Player;
class Bullet;

class Gun : public IGameObject
{

public:

	Gun();
	~Gun();

	void Update();
	void Render(RenderContext& rc);
	void Shot();
	
	int animationFrame = 0;
	int bulletCount = 0;
	bool ADS = 0;
	int type = 0;
	int maxMagazine = 7;
	//int spareMagazine = 0;
	int magazine = maxMagazine;
	int reloading = 0;
	int coolDown = 0;
	float angle;

	EffectEmitter* effectEmitter;
	Vector3 pos;
	ModelRender modelRender;
	Player* player;
	Quaternion rot;
	SoundSource* SE;

};

