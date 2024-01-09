#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <vector>
#include <iostream>

#include "glm/ext.hpp"

class Node {

public:
  bool visible = false;

  glm::vec3 pos { 0.0f };
  glm::vec3 rot { 0.0f };
  glm::vec3 scl { 1.0f };
  
  /// <summary>
  /// Child classname of the node,
  /// Example: BasePlayer, parent: Node, So this will be BasePlayer
  /// </summary>
  std::string name = "";

  Node();
  virtual ~Node();

  Node *parent() const;
  void reparent(Node*);

  std::vector<Node*> children() const;
  bool hasChild(Node*) const;
  void addChild(Node*);
  void removeChild(Node*);

  glm::mat4 trans() const;
  glm::mat4 view() const;

  virtual void draw();

private:
  Node *m_parent = nullptr;
  std::vector<Node*> m_children {};

  glm::vec3 globalPos() const;
  glm::vec3 globalRot() const;

};

#endif // __NODE_HPP__
