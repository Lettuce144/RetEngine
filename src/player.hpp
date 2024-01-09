#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "btBulletDynamicsCommon.h"
#include "glm/ext.hpp"

#include "camera.hpp"
#include "input_events.hpp"
#include "physics_object.hpp"

/// <summary>
/// Base class for the player, this class is mainly used for debug purposes, and for the example game.
/// There are multiple virtual functions like drawing and such
/// </summary>
class BasePlayer : public PhysicsObject {

public:
  static const float HEIGHT;
  static const float RADIUS;
  static const float MASS;
  static const float MOUSE_SENS;
  static const float SPEED;
  static const float ACCEL;
  static const float AIR_ACCEL;
  static const float JUMP;
  static const float JUMP_HORIZONTAL_MULT;

  BasePlayer();
  ~BasePlayer();

  Camera *camera() const;

  void draw();
  void input(InputEvent*);

private:
  float m_animSpeedMult = 1.0f;
  bool m_bIsInNoclip = false;
  Camera *m_camera = new Camera();

};

#endif // __PLAYER_HPP__
