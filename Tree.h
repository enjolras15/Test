#pragma once
class Tree : public IGameObject
{
public:
	Tree();
	~Tree();

	void Update();
	void Render(RenderContext& rc);

	Vector3 pos;
	ModelRender modelRender;


};