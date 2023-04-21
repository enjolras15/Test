#pragma once

class Gun;
class Bullet : public IGameObject
{
public:

	Bullet();
	~Bullet();

	void Update();

	Vector3 pos;
	Gun* gun;

};

