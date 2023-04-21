#include "stdafx.h"
#include "Tree.h"

Tree::Tree()  {

	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/tree.tkm");
	//pos.x = 600;
	//pos.y = 0;

}

Tree::~Tree() {



}

void Tree::Update() {

	modelRender.Update();

}

void Tree::Render(RenderContext& rc) {

	modelRender.Draw(rc);

}
