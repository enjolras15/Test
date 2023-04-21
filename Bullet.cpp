#include "stdafx.h"
#include "Bullet.h"
#include "Gun.h"

Bullet::Bullet() {

	gun = FindGO<Gun>("Gun");
	pos.x = gun->pos.x;
	pos.y= 0;
	pos.z = gun->pos.z+130;

}

Bullet::~Bullet() {



}

void Bullet::Update() {

	pos.z += 50.0f;

	if (pos.z>2050.0f) {

		DeleteGO(this);

	}

}