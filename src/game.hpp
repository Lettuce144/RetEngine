#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "glm/ext.hpp"
#include "btBulletDynamicsCommon.h"

#include "window.hpp"
#include "node.hpp"
#include "player.hpp"
#include "input_events.hpp"
#include "props/props.hpp"

namespace Game {

  extern Window *window;
  extern glm::vec4 clearColor;

  extern btDiscreteDynamicsWorld *dynamicsWorld;
  extern btCollisionDispatcher *collisionDispatcher;

  extern Node rootNode;
  extern BasePlayer *player;

  void start();
  void update();
  void end();
  double deltaTime();
  PhysicsObject* spawnObj(std::string File);
  void setObjThingPos(glm::vec3 pos);
  void removeObjThing();
  void input(InputEvent*);



} // namespace Game

#endif // __GAME_HPP__
