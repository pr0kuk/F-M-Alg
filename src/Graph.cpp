#include "Graph.h"
#include <sstream>
#include <string>

Graph::Graph(std::ifstream &input) {
  unsigned num_edges = 0, num_vertices = 0, c_vert = 0;
  std::string line;
  input >> num_edges >> num_vertices;
  vertices = vector2d(num_vertices + 1);
  edges = vector2d(num_edges + 1);
  for (unsigned c_edge = 0; getline(input, line); c_edge++){
    std::istringstream stream(line);
    while (stream >> c_vert) {
      vertices[c_vert].push_back(c_edge);
      edges[c_edge].push_back(c_vert);
    }
  }
}