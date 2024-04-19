#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <vector>
#include <iostream>

#include "glm/ext.hpp"

/// <summary>
/// An object in 3D space, all gameobjects derrive from this
/// </summary>
class Node {

public:
  bool visible = false;

  glm::vec3 pos { 0.0f };
  glm::vec3 rot { 0.0f };
  glm::vec3 scl { 1.0f };

  Node();
  virtual ~Node();

  Node *parent() const;
  void reparent(Node*);

  std::vector<Node*> children() const;
  bool hasChild(Node*) const;
  void addChild(Node*);
  void removeChild(Node*);

  std::string GetClassName() const;

  glm::mat4 trans() const;
  glm::mat4 view() const;

  virtual void draw();

private:
  Node *m_parent = nullptr;
  std::vector<Node*> m_children {};

  std::string m_derivedClassName = "";

  glm::vec3 globalPos() const;
  glm::vec3 globalRot() const;

};

#endif // __NODE_HPP__
