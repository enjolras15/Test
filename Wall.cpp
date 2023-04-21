#include "stdafx.h"
#include "Wall.h"

Wall::Wall() {

	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/Wall.tkm");

	modelRender.SetPosition(0.0f,0.0f,50.0f);
	
}

Wall::~Wall() {
	

}

void Wall::Update() {


	modelRender.Update();

}

void Wall::Render(RenderContext& rc) {

	modelRender.Draw(rc);

}
