#include "gen_world.hpp"

#include "btBulletDynamicsCommon.h"
#include "btBulletCollisionCommon.h"

#include "gl.hpp"
#include "game.hpp"
#include "mesh.hpp"
#include "shader.hpp"
#include "shaders.hpp"
#include "mesh_gen.hpp"
#include "mesh_instance.hpp"
#include "texture.hpp"
#include "files.hpp"
#include "mesh_loader.hpp"
#include "physics_object.hpp"
#include "props/props.hpp"
#include "obj_loader.hpp"

//Loads the world
namespace GenWorld {

  void ground() {
    StaticProp *gnd = new StaticProp("ground.mesh", { 0.0f, -0.5f, 0.0f });

    PhysicsObject *slope =
      MeshLoader::loadPhysicsObject(Files::dataDir()/"slope.mesh");
    slope->setOrigin({ 0.0f, -0.5f, 0.0f });
    Game::rootNode.addChild(slope);

    auto Place = [](glm::vec3 origin) -> void {
      PhysicsObject *box =
        MeshLoader::loadPhysicsObject(Files::dataDir()/"crate.mesh");
      box->setOrigin(origin);
      box->setMassProps(5.0f, glm::vec3(1.0f, 1.0f, 1.0f));  // Set mass and local inertia
      box->setCollisionShape(new btBoxShape(btVector3(1.0f, 1.0f, 1.0f)));  // Example: Box shape
      box->setInertiaTensor();  // Set inertia tensor
      box->Update();
      Game::rootNode.addChild(box);
    };

    PhysicsProp* prop = new PhysicsProp("crate.mesh", { 0.0f, 0.0f, -5.0f });

    Place({ 0.0f, 0.0f, -5.0f });
    Place({ 3.0f, 1.5f, -7.0f });
    Place({ 4.0f, 2.5f, -4.0f });
    Place({ 7.0f, 3.5f, -4.0f });
    Place({ 12.0f, 4.0f, 0.0f });
    Place({ 13.0f, 5.0f, 6.0f });

    Game::rootNode.addChild(MeshLoader::loadPhysicsObject(Files::dataDir()
                                                          /"hall.mesh"));
    Game::rootNode.addChild(MeshLoader::loadPhysicsObject(Files::dataDir()
                                                          /"hall_floor.mesh"));

    PhysicsObject *objSphere = ObjLoader::load(Files::dataDir()/"sphere.obj");
    objSphere->setOrigin({ -2.0f, 2.0f, -10.0f });
    objSphere->mesh->shader =
      new Shader(Files::readFile(Files::dataDir()/"shader.vert"),
                 Files::readFile(Files::dataDir()/"shader.frag"));
    objSphere->texture = new Texture();
    objSphere->texture->load(Files::dataDir()/"crate.jpg", 3, GL_RGB);
    Game::rootNode.addChild(objSphere);
  }

  void all() {
    ground();
  }

} // namespace GenWorld
