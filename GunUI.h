#pragma once

class Gun;

class GunUI : public IGameObject
{

public: 

	GunUI();
	~GunUI();

	void Update();
	void Render(RenderContext& rc);
	int scaleUP = 0;

private:
	wchar_t Text[256];
	int TextAnimation = 0;
	float num, num2;
	SpriteRender spriteRender;
	FontRender fontRender;
	FontRender fontRender2;
	Gun* gun;

};
