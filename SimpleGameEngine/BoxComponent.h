#pragma once
#include "Rectangle.h"
#include "Component.h"

class Renderer;

class BoxComponent : public Component
{
public:

	BoxComponent(Actor* ownerP, float width, float height); // Lower draw order: further back
	virtual ~BoxComponent();
	BoxComponent() = delete;
	BoxComponent(const BoxComponent&) = delete;
	BoxComponent& operator=(const BoxComponent&) = delete;

	//virtual void setTexture(const Texture& textureP);
	void draw(Renderer& renderer);

	//int getDrawOrder() const { return drawOrder; }
	

protected:
	
	Rectangle rectangle;
	
};
