#pragma once
class HPUI : public IGameObject
{

public:

	HPUI();
	~HPUI();

	void Update();
	void Render(RenderContext& rc);
	int num = 0;

	Vector3 pos;
	SpriteRender spriteRender;
	SpriteRender spriteRender2;
	FontRender fontRender;

};

