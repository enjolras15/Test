#include "stdafx.h"
#include "Enemygenerator.h"
#include "Enemy.h"

EnemyGenerator::EnemyGenerator() {



}

EnemyGenerator::~EnemyGenerator() {



}

void EnemyGenerator::Update() {

	if (waitFrame>=180-EnemySpawnTime) {
	

		
		for (int i = 0; i < 8; i++) {

			Enemy* enemy = FindGO<Enemy>("Enemy" + i);

			if (enemy->available == 0) {

				enemy->moveMode = rand() % 5;
				enemy->available = 1;
				enemy->SetPosition();
				break;

			}

		}

		

		//NewGO<Enemy>(0, "Enemy");

		waitFrame = 0;
		
		if (60 > EnemySpawnTime) {

			EnemySpawnTime += 10;

		}

		else if (90 > EnemySpawnTime) {

			EnemySpawnTime += 5;

		}

		else if (110>EnemySpawnTime) {

			EnemySpawnTime += 1;

		}

	}

	waitFrame++;

}