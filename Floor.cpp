#include "stdafx.h"
#include "Floor.h"

Floor::Floor() {

	modelRender.Init("Assets/modelData/floor.tkm");
	modelRender.SetPosition(0.0f, 0.0f, 0.0f);
}


Floor::~Floor() {



}

void Floor::Update() {


	modelRender.Update();


}

void Floor::Render(RenderContext& rc) {

	modelRender.Draw(rc);

}