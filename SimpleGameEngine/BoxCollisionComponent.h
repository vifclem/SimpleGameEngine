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

	
	float getWidth() const;
	float getHeight() const;

	void setWidth(float width);
	void setHeight(float height);

	const Vector2 getCenter() const;

private:
	float height;
	float width;
};

bool Intersect(const BoxCollisionComponent& a, const BoxCollisionComponent& b);





