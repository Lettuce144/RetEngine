#pragma once
#include "../physics_object.hpp"

/// <summary>
/// Prop with physics
/// </summary>
class PhysicsProp : public PhysicsObject
{
public:
	PhysicsProp(std::string model_path, glm::vec3 pos);
	~PhysicsProp();

	PhysicsObject* prop;
private:


	float mass = 0.0f;
};

/// <summary>
/// Prop that doesn't move
/// </summary>
/// <param name="path"></param>
/// <param name="pos"></param>
class StaticProp
{
public:
	StaticProp(std::string model_path, glm::vec3 pos);

	PhysicsObject* prop;
	~StaticProp();

private:

};