#include "Partitionment.h"
#include <algorithm>

void Partitionment::calculate_cost() {
  for (auto it = std::begin(graph.get_edges()) + 1; it < std::end(graph.get_edges()); ++it)
    if(std::find(std::begin(*it) + 1, std::end(*it), vertices[(*it)[0]]) != std::end(*it))
      cost++;
}

Partitionment::Partitionment(Graph graph) : graph{graph} {
  size_t size = graph.get_vertices().size() - 1;
  vertices.resize(size + 1);
  for (size_t i = 1; i <= size / 2; ++i)
    vertices[i] = false;
  for (size_t i = size / 2 + 1; i <= size; ++i)
    vertices[i] = true;
  color = size % 2;
  calculate_cost();
}

void Partitionment::update(unsigned Vertex) {
  color += vertices[Vertex] ? -1 : 1;
  vertices[Vertex] ^= 1;
}

void Partitionment::print(std::ostream &Out) {
  for (auto it = std::begin(vertices) + 1; it < std::end(vertices); ++it)
    Out << *it << '\n';
}