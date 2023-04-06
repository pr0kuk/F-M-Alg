#pragma once
#include "Graph.h"
#include <vector>

class Partitionment {
  std::vector<int> vertices;
  Graph &graph;
  int cost = 0;
  int color = 0;
public:
  Partitionment(Graph graph);
  void set_cost(int cost) { this->cost = cost; }
  int get_cost() { return cost; }
  int get_color() { return color; }
  void calculate_cost();
  void update(unsigned vertex);
  void print(std::ostream &Out = std::cout);
  std::vector<int> &get_prt() { return vertices; }
};
