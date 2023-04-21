#pragma once

class HP :public IGameObject
{

public:

	HP();
	~HP();


	int Hp = 3;
	int Restart = 0;
	int Score = 0;

};