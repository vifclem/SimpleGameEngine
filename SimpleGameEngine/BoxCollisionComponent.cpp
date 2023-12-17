#include "BoxCollisionComponent.h"
#include "Actor.h"

BoxCollisionComponent::BoxCollisionComponent(Actor* owner) : Component(owner)
{
}

const Vector2 BoxCollisionComponent::getPosition() const
{
	return owner.getPosition();
}

const float BoxCollisionComponent::getSizeX() const
{
	return owner.getSizeX();
}

const float BoxCollisionComponent::getSizeY() const
{
	return owner.getSizeY();
}

bool Intersect(const BoxCollisionComponent& a, const BoxCollisionComponent& b)
{
	float xMinA = a.getPosition().x;
	float xMaxA = a.getPosition().x + a.getSizeX();
	float yMinA = a.getPosition().y;
	float yMaxA = a.getPosition().y + a.getSizeY();
	float xMinB = b.getPosition().x;
	float xMaxB = b.getPosition().x + b.getSizeX();
	float yMinB = b.getPosition().y;
	float yMaxB = b.getPosition().y + b.getSizeY();
	return!(xMinA > xMaxB || xMaxA < xMinB || yMinA > yMaxB || yMaxA < yMinB);
}
