#include "stdafx.h"
#include "HPUI.h"
#include "HP.h"

HPUI::HPUI() {

spriteRender.Init("Assets/image/redFlag.dds",50.0f,50.0f);
spriteRender2.Init("Assets/image/UI2.dds", 300.0f, 80.0f);
spriteRender2.SetPosition({ 700.0f,500.0f,0.0f });

pos.y = 500;

}

HPUI::~HPUI() {



}

void HPUI::Update() {

	if (pos.x != 850 - num * 70) {

		pos.x = 850 - num * 70;

	}

	HP* h = FindGO<HP>("hp");

	if (num > h->Hp) {

		DeleteGO(this);

	}

	spriteRender.SetPosition(pos);
	spriteRender2.Update();
	spriteRender.Update();

}

void HPUI::Render(RenderContext& rc) {

	spriteRender.Draw(rc);
	spriteRender2.Draw(rc);
}

