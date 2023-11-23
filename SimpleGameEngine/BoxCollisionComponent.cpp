#include "BoxCollisionComponent.h"
#include "Actor.h"

BoxCollisionComponent::BoxCollisionComponent(Actor* owner) : Component(owner), height(20.0f), width(50.0f)
{
}

float BoxCollisionComponent::getWidth() const
{
	return owner.getScale() * width;
}

float BoxCollisionComponent::getHeight() const
{
	return owner.getScale() * height;
}

void BoxCollisionComponent::setWidth(float widthP)
{
	width = widthP;
}

void BoxCollisionComponent::setHeight(float heightP)
{
	height = heightP;
}

const Vector2 BoxCollisionComponent::getCenter() const
{
	return owner.getPosition();
}

//bool Intersect(const BoxCollisionComponent& a, const BoxCollisionComponent& b)
//{
//	Vector2 aCenter = a.getCenter();
//	Vector2 bCenter = b.getCenter();
//	Vector2 ab = bCenter - aCenter;
//	float distSq = ab.lengthSq();
//	float sumOfRadius = a.getRadius() + b.getRadius();
//	return distSq <= sumOfRadius * sumOfRadius;
//}
