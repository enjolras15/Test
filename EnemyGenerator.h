#pragma once

class Enemy;

class EnemyGenerator : public IGameObject
{

public: 

	EnemyGenerator();
	~EnemyGenerator();

	void Update();

private:
	int waitFrame = 130;
	int EnemySpawnTime = 0;

};

