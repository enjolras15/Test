#include "stdafx.h"
#include "Score.h"
#include "Title.h"
#include "HP.h"

Score::Score() {

	spriteRender.Init("Assets/image/floor.dds", 1920.0f, 1080.0f);

	h = FindGO<HP>("hp");
	fontRender.SetPosition({ -300.0f,200.0f,0.0f });
	fontRender.SetScale(2);
	fontRender.SetColor(g_vec4White);
	S = h->Score;

}

Score::~Score() {



}

void Score::Update() {

	if (animationFrame==1) {

		fontRender2.SetPosition({ -370.0f,100.0f,0.0f });

		if (S == 0)

			if (animation <= 30)
		    fontRender2.SetText(L"戦線の防衛に多大な功績を残しました。\n            Yで再開");
			else
			fontRender2.SetText(L"戦線の防衛に多大な功績を残しました。\n");

		else if (S < 30)
			if (animation <= 30)
			fontRender2.SetText(L"　   貴方のランク　二等兵　　　　　　\n            Yで再開");
			else
			fontRender2.SetText(L"　   貴方のランク　二等兵　　　　　　\n");

		else if (S < 50)
			if (animation <= 30)
			fontRender2.SetText(L"   　貴方のランク　一等兵　　　　　　\n            Yで再開");
			else
			fontRender2.SetText(L"   　貴方のランク　一等兵　　　　　　\n");

		else if (S < 70)
			if (animation <= 30)
			fontRender2.SetText(L" 　  貴方のランク　上等兵　　　　　　\n            Yで再開");
			else
			fontRender2.SetText(L" 　  貴方のランク　上等兵　　　　　　\n");

		else if (S < 90)
			if (animation <= 30)
			fontRender2.SetText(L"  　 　貴方のランク　兵長　　　　　　\n            Yで再開");
			else
			fontRender2.SetText(L"  　 　貴方のランク　兵長　　　　　　\n");

		else if (S < 120)
			if (animation <= 30)
			fontRender2.SetText(L"  　 貴方のランク　下士官　　　　　　\n            Yで再開");
			else
			fontRender2.SetText(L"  　 貴方のランク　下士官　　　　　　\n");

		else if (S < 150)
			if (animation <= 30)
			fontRender2.SetText(L"  　　 貴方のランク　将校　　　　　　\n            Yで再開");
			else
			fontRender2.SetText(L"  　　 貴方のランク　将校　　　　　　\n");

		else if (S < 180)
			if (animation <= 30)
			fontRender2.SetText(L"   　　貴方のランク　将軍　　　　　　\n            Yで再開");
		    else
			fontRender2.SetText(L"   　　貴方のランク　将軍　　　　　　\n");

		else
			if (animation <= 30)
			fontRender2.SetText(L"  　 　貴方のランク　元帥　　　　　　\n            Yで再開");
			else
			fontRender2.SetText(L"   　　貴方のランク　元帥　　　　　　\n");

		animation ++ ;

		if (animation >= 60) {

			animation = 0;

		}


	}

	if (animationFrame ==1) {

		if (g_pad[0]->IsTrigger(enButtonY)) {

			NewGO<Title>(0);
			DeleteGO(this);

		}

	}

	else {

		swprintf_s(Text, 256, L"戦果　%d人迎撃", printScore);
		fontRender.SetText(Text);

		if (S > printScore) {

			if (waitFrame == 0) {

				printScore++;
				waitFrame = 1;

			}

			else {

				waitFrame = 0;

			}

		}

		else {

			animationFrame = 1;

		}

	}

}

void Score::Render(RenderContext& rc) {

	spriteRender.Draw(rc);
	fontRender.Draw(rc);
	fontRender2.Draw(rc);
}