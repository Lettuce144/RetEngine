#include <iostream>
#include <cmath>
#include "props.hpp"
#include "../mesh_loader.hpp"
#include "../texture.hpp"
#include "../files.hpp"
#include "../game.hpp"
#include "btBulletDynamicsCommon.h"
#include "glm/ext.hpp"

//-----------------------------------------------------------------------
//                              Physics prop
//-----------------------------------------------------------------------


/// <summary>
/// Class for creating and managing props
/// </summary>
/// <param name="path"></param>
/// <param name="pos"></param>
PhysicsProp::PhysicsProp(std::string model_path, glm::vec3 pos)
{
    std::cout << "Loading mesh: " + model_path << std::endl;
    PhysicsObject* prop =
        MeshLoader::loadPhysicsObject(Files::dataDir() / model_path);
    
    prop->setOrigin(pos);
    Game::rootNode.addChild(prop);
}

PhysicsProp::~PhysicsProp()
{
	prop->~PhysicsObject();
}

//-----------------------------------------------------------------------
//                              Static prop
//-----------------------------------------------------------------------

/// <summary>
/// Prop that doesn't move
/// </summary>
/// <param name="path"></param>
/// <param name="pos"></param>
StaticProp::StaticProp(std::string model_path, glm::vec3 pos)
{
    std::cout << "Loading mesh: " + model_path << std::endl;
	PhysicsObject* prop =
		MeshLoader::loadPhysicsObject(Files::dataDir() / model_path);

	prop->setOrigin(pos);
	Game::rootNode.addChild(prop);
}

StaticProp::~StaticProp()
{
	prop->~PhysicsObject();
    //Maybe use this?
    //Game::rootNode.removeChild(prop);
}