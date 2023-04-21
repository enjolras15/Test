#pragma once
#include "sound/SoundSource.h"

class Bullet;
class Gun;
class HPUI;

class Enemy : public IGameObject
{

public:

	Enemy();
	~Enemy();

	void Update();
	void Render(RenderContext& rc);
	void SetPosition();

	int available = 1;
	int moveMode = 0;
	float Xmove = 1.5f;

	Vector3 pos;
	ModelRender modelRender;
	Bullet* bullet;
	Gun* gun;
	HPUI* ui;
	EffectEmitter* effectEmitter;

};

