#pragma once
class Floor : public IGameObject
{

	public:

	Floor();
	~Floor();

	void Update();
	void Render(RenderContext& rc);

	ModelRender modelRender;

};

