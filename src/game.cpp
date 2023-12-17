#include "game.hpp"

#include "glm/ext.hpp"
#include "btBulletDynamicsCommon.h"

#include "window.hpp"
#include "node.hpp"
#include "player.hpp"
#include "gen_world.hpp"
#include "input_events.hpp"
#include "setup_dynamics_world.hpp"
#include "animator.hpp"
#include "obj_loader.hpp"
#include "files.hpp"
#include <iostream>

namespace Game {

  Window *window = nullptr;
  glm::vec4 clearColor { 0.1f, 0.15f, 0.2f, 1.0f };

  btDiscreteDynamicsWorld *dynamicsWorld = nullptr;
  btCollisionDispatcher *collisionDispatcher = nullptr;
  //Test
  PhysicsObject* objThing = nullptr;

  Node rootNode;
  Player *player = nullptr;

  void start() {
    SetupDynamicsWorld::setup();
    //Creates world
    GenWorld::all();

    spawnObj("thing.obj");
    player = new Player();
    rootNode.addChild(player);
  }

  /// <summary>
  /// Call to change the object in the middle of the world
  /// </summary>
  /// <param name="File"></param>
  PhysicsObject* spawnObj(std::string File)
  {
      objThing = ObjLoader::load(Files::dataDir() / File);
      objThing->setOrigin({ 0.0f, 3.0f, 0.0f });
      objThing->mesh->shader =
          new Shader(Files::readFile(Files::dataDir() / "shader.vert"),
              Files::readFile(Files::dataDir() / "shader.frag"));
      objThing->texture = new Texture();
      objThing->texture->load(Files::dataDir() / "crate.jpg", 3, GL_RGB);
      rootNode.addChild(objThing);

      std::cout << "Spawned obj" << std::endl;

      return objThing;
  }

  void setObjThingPos(glm::vec3 newPos)
  {
      if (objThing && objThing != nullptr)
      {
          objThing->setOrigin(newPos);
      }
  }

  void removeObjThing()
  {
	  if (objThing && objThing != nullptr)
	  {
		  objThing->~PhysicsObject();
		  objThing = nullptr;
	  }
  }

  void update() {
    dynamicsWorld->stepSimulation(deltaTime());
    Animator::step();
  }

  void end() {

  }

  float m_fllastTick = 0.0f;
  float m_fldeltaTime = 0.0f;

  /// <summary>
  /// TODO: move to separate class
  /// </summary>
  double deltaTime()
  {
      m_fldeltaTime = (float)glfwGetTime() - m_fllastTick;
      m_fllastTick = (float)glfwGetTime();

      return m_fldeltaTime;
  }

  void input(InputEvent *event) {
    player->input(event);
  }

} // namespace Game
