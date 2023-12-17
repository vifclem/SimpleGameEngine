#pragma once
#include "Component.h"
#include "Vector2.h"
class BoxCollisionComponent : public Component
{

public:
	BoxCollisionComponent(Actor* owner);
	BoxCollisionComponent() = delete;
	BoxCollisionComponent(const BoxCollisionComponent&) = delete;
	BoxCollisionComponent& operator=(const BoxCollisionComponent&) = delete;

	const Vector2 getPosition() const;
	const float getSizeX() const;
	const float getSizeY() const;

};

bool Intersect(const BoxCollisionComponent& a, const BoxCollisionComponent& b);





