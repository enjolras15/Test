#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "Fade.h"
#include "sound/SoundEngine.h"
#include "Gun.h"


Title::Title() {

	spriteRender.Init("Assets/image/Title.dds",1920.0f,1080.0f);

	fontRender.SetPosition({ -200.0f,50.0f,0.0f });

	fontRender.SetColor(g_vec4White);
	
	//g_soundEngine->ResistWaveFileBank(4, "Assets/sound/Kikebankokunoroudousha.wav");

	g_soundEngine->ResistWaveFileBank(4, "Assets/sound/KikebankokunoroudoushaVocla.wav");

	BGM = NewGO<SoundSource>(0);

	BGM->Init(4);

	BGM->Play(true);

	BGM->SetVolume(0.7f);


}

Title::~Title() {



}

void Title::Update() {

	if (Start >= 1) {

		DeleteGO(BGM);

        Game* game=NewGO<Game>(0,"game");

		game->x = C;

		DeleteGO(this);

		Start = 0;

	}
	
	if (g_pad[0]->IsTrigger(enButtonA)) {

		fontRender.SetText(L"Now Loading");
		Start = 1;
		Fade* f = NewGO <Fade>(0,"fade");
		f->StartFadeIn();

	}

	if (g_pad[0]->IsTrigger(enButtonDown)) {

		C--;

		if (C == -1)
			C = 1;

	}

	if (g_pad[0]->IsTrigger(enButtonUp)) {

		C++;
		if (C == 2)
			C = 0;

	}

	if (Start == 0) {

		if (C == 1) {

			fontRender.SetText(L"難易度選択 Aで決定\n\n   ＞普通\n\n    困難");

		}
		
		else {

			fontRender.SetText(L"難易度選択 Aで決定\n\n    普通\n\n   ＞困難");

		}



	}

	else {

		Start++;

	}

}

void Title::Render(RenderContext& rc) {

	spriteRender.Draw(rc);
	fontRender.Draw(rc);

}