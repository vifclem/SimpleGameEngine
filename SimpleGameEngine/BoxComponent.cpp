#include "BoxComponent.h"
#include "Actor.h"
#include "Game.h"
#include "Renderer.h"

BoxComponent::BoxComponent(Actor* ownerP, float width, float height) :
	Component(ownerP),
	rectangle{ Rectangle{0,0,width, height} }
{
	owner.getGame().getRenderer().addRectangle(this);
}

BoxComponent::~BoxComponent()
{
	owner.getGame().getRenderer().removeRectangle(this);
}

//void BoxComponent::setTexture(const Texture& textureP)
//{
//	texture = textureP;
//	texture.updateInfo(texWidth, texHeight);
//}

void BoxComponent::draw(Renderer& renderer)
{
	Rectangle rect = Rectangle{ owner.getPosition().x, owner.getPosition().y, rectangle.width, rectangle.height };
	renderer.drawRectangle(rect);
}