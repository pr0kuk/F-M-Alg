#include "Partitionment.h"
#include <algorithm>

void Partitionment::calculate_cost() {
    for (auto it = std::begin(graph.get_edges()) + 1; it != std::end(graph.get_edges()); ++it)
        if (std::any_of(std::begin(*it) + 1, std::end(*it), [this, it](int v){return vertices[v] != vertices[(*it).front()];}))
            cost++;
}

Partitionment::Partitionment(Graph graph) : graph{graph} {
    size_t size = graph.get_vertices().size() - 1;
    vertices = std::vector<int>(size + 1, 0);
    for (size_t i = size / 2 + 1; i <= size; vertices[i++] = 1);
    color = size % 2;
    calculate_cost();
}

void Partitionment::apply(unsigned v) {
    color += vertices[v] ? -1 : 1;
    vertices[v] ^= 1;
}

void Partitionment::print(std::ostream &out) {
    for (auto it = std::begin(vertices) + 1; it < std::end(vertices); ++it)
        out << *it << '\n';
}