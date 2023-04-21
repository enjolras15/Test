#pragma once

class HP;

class Score : public IGameObject
{

public:

	Score();
	~Score();

	void Update();

	void Render(RenderContext& rc);

	HP* h;

private:

	int animationFrame=0;
	int animation = 0;
	int S = 0;
	int printScore=0;
	bool waitFrame = 0;
	wchar_t Text[256];
	wchar_t Text2[256];
	SpriteRender spriteRender;
	FontRender fontRender;
	FontRender fontRender2;

};

