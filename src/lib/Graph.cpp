#include "Graph.h"
#include <sstream>
#include <string>

Graph::Graph(std::ifstream &input) {
  unsigned num_edges = 0, num_vertices = 0, c_vert = 0;
  std::string line;
  input >> num_edges >> num_vertices;
  Vertices = vector2d(num_vertices + 1);
  Edges = vector2d(num_edges + 1);
  for (unsigned c_edge = 0; getline(input, line); c_edge++){
    std::istringstream Stream(line);
    while (Stream >> c_vert) {
      Vertices[c_vert].push_back(c_edge);
      Edges[c_edge].push_back(c_vert);
    }
  }
}