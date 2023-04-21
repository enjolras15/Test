#pragma once
class Wall : public IGameObject
{

public:

	Wall();
	~Wall();

	void Update();
	void Render(RenderContext& rc);

	
	ModelRender modelRender;

};

