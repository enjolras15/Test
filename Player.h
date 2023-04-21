#pragma once
class Player : public IGameObject
{

public:

	Player();
	~Player();

	void Update();
	void Render(RenderContext& rc);

	float Speed = 4.0;
	int shake = 0;

	int addY=0;
	Vector3 pos;

};

