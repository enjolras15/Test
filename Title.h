#pragma once
#include "sound/SoundSource.h"

class Title : public IGameObject
{
public: 
	Title();
	~Title();

	void Render(RenderContext& rc);
	void Update();
	int C = 1;
	int Start = 0;

	SoundSource* BGM;
	SpriteRender spriteRender;
	SpriteRender spriteRender2;
	FontRender fontRender;

};