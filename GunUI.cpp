#include "stdafx.h"
#include "GunUI.h"
#include "Gun.h"
#include "HP.h"

GunUI::GunUI() {

	fontRender.SetPosition({ -600.0f,-300.0f,0.0f });

	fontRender.SetColor(g_vec4White);
	

	fontRender2.SetPosition({ 550.0f,510.0f,0.0f });

	fontRender2.SetColor(g_vec4White);

	fontRender2.SetText(L"HP");

	spriteRender.Init("Assets/image/UI1.dds", 350.0f, 100.0f);
	spriteRender.SetPosition({ -450.0f,-320.0f,0.0f });



}

GunUI::~GunUI() {



}

void GunUI::Update() {

	if (scaleUP > 0) {

		fontRender.SetScale(1.1f);

		scaleUP--;

	}

	else fontRender.SetScale(1.0f);



	gun = FindGO<Gun>("Gun");

	if (gun->reloading > 0) {

		fontRender.SetColor(g_vec4White);
		
		if (TextAnimation == 0) {

			swprintf_s(Text, 256, L"リロード中.");
			TextAnimation = 1;

		}

		else if (TextAnimation == 1) {

			swprintf_s(Text, 256, L"リロード中..");
			TextAnimation = 2;

		}

		else if (TextAnimation == 2) {

			swprintf_s(Text, 256, L"リロード中...");
			TextAnimation = 0;

		}

	}
	

	else {

		num = gun->magazine;
		num2 = gun->maxMagazine;

		if (num > 0) {

			if (num / num2 > 0.8) {

				fontRender.SetColor(g_vec4White);

			}

			else if (num / num2 > 0.5) {

				fontRender.SetColor({ 1.0f,1.0f,0.0f,1.0f });

			}

			else {

				fontRender.SetColor({ 1.0f,0.0f,0.0f,1.0f });

			}

		}

		else 
			fontRender.SetColor({ 0.2f,0.2f,0.2f,1.0f });


		TextAnimation = 0;
		swprintf_s(Text, 256, L"弾　%d発/無限", gun->magazine);

	}

	HP* h = FindGO<HP>("hp");

	if (h->Hp==2) {

		fontRender2.SetColor({ 1.0f,1.0f,0.0f,1.0f });

	}

	if (h->Hp == 1) {

		fontRender2.SetColor({ 1.0f,0.0f,0.0f,1.0f });

	}
	
	fontRender.SetText(Text);

	spriteRender.Update();
}

void GunUI::Render(RenderContext& rc) {

	spriteRender.Draw(rc);
	fontRender.Draw(rc);
	fontRender2.Draw(rc);
	
}