#pragma once
#include <fstream>
#include <iostream>
#include <vector>
using vector2d = std::vector<std::vector<unsigned>>;
class Graph {
  vector2d Vertices;
  vector2d Edges;
public:
  Graph(std::ifstream &);
  vector2d &get_vertices() { return Vertices; }
  vector2d &get_edges() { return Edges; }
};