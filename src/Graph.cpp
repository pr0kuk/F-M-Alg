#include "Graph.h"
#include <sstream>
#include <string>

Graph::Graph(std::ifstream &input) {
    unsigned num_edges = 0, num_vertices = 0, v = 0;
    std::string line;
    input >> num_edges >> num_vertices;
    vertices = vector2d(num_vertices + 1);
    edges = vector2d(num_edges + 1);
    for (unsigned e = 0; getline(input, line); e++){
        std::istringstream stream(line);
        while (stream >> v) {
            vertices[v].push_back(e);
            edges[e].push_back(v);
        }
    }
}