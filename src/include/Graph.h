#pragma once
#include <fstream>
#include <iostream>
#include <vector>
using vector2d = std::vector<std::vector<unsigned>>;
class Graph {
  vector2d vertices;
  vector2d edges;
public:
  Graph(std::ifstream &);
  vector2d &get_vertices() { return vertices; }
  vector2d &get_edges() { return edges; }
};