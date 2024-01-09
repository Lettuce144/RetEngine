#include <iostream>
#include <cmath>
#include "props.hpp"
#include "../mesh_loader.hpp"
#include "../texture.hpp"
#include "../files.hpp"
#include "../game.hpp"
#include "../obj_loader.hpp"
#include "btBulletDynamicsCommon.h"
#include "glm/ext.hpp"

//-----------------------------------------------------------------------
//                              Physics prop
//-----------------------------------------------------------------------


/// <summary>
/// Class for props that are affected by gravity
/// </summary>
/// <param name="path"></param>
/// <param name="pos"></param>
PhysicsProp::PhysicsProp(std::string model_path, glm::vec3 pos)
{
    std::cout << "Loading mesh: " + model_path << std::endl;
    m_prop = MeshLoader::loadPhysicsObject(Files::dataDir() / model_path);
    
    m_prop->setOrigin(pos);
    Game::rootNode.addChild(m_prop);
}

PhysicsProp::~PhysicsProp()
{
    m_prop->~PhysicsObject();
}

//-----------------------------------------------------------------------
//                              Static prop
//-----------------------------------------------------------------------

/// <summary>
/// Prop that doesn't move
/// </summary>
/// <param name="path"></param>
/// <param name="pos"></param>
StaticProp::StaticProp(std::string model_path, glm::vec3 pos, bool objModel )
{
    std::cout << "Loading mesh: " + model_path << std::endl;
        
    if(objModel)
        m_prop = ObjLoader::load(Files::dataDir() / model_path);
	else
        m_prop = MeshLoader::loadPhysicsObject(Files::dataDir() / model_path);
    m_prop->setOrigin(pos);
	Game::rootNode.addChild(m_prop);
}

StaticProp::~StaticProp()
{
	m_prop->~PhysicsObject();
    //Maybe use this?
    //Game::rootNode.removeChild(prop);
}