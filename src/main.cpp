#include "Graph.h"
#include "Partitionment.h"
#include <chrono>
unsigned FM(Graph & graph, Partitionment & prt);
int main(int argc, char *argv[]) {
    std::string input_file = argv[1];
    std::ifstream input(input_file);
    std::ofstream output(input_file + ".part.2.txt");
    Graph graph(input);
    Partitionment prt(graph);
    auto start = std::chrono::steady_clock::now();
    unsigned iterations = FM(graph, prt);
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
    std::cout << input_file << ' ' << graph.get_edges().size() << ' ' << graph.get_vertices().size() << ' ' << prt.get_cost() << ' ' << time << ' ' << iterations << '\n';
    prt.print(output);
    return 0;
}