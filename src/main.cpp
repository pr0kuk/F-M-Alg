#include "Graph.h"
#include "Partitionment.h"
#include <chrono>
#include <cstring>
unsigned FM(Graph &, Partitionment &, bool is_mod);
int main(int argc, char *argv[]) {
    if (argc == 1 || argc > 3 || (argc == 3 && strncmp(argv[1], "-m", 2) !=0 )) {
        std::cout << "ERR: argc = 1 or argc > 3 or argc = 3 and -m missed. Available options are: <file> or -m <file>\n";
        return -1;
    }
    bool is_mod = (argc == 3 && strncmp(argv[1], "-m", 2) == 0) ? true : false;
    std::string input_file = argv[argc-1];
    std::ifstream input(input_file);
    std::ofstream output(input_file + ".part.2");
    if (!input.is_open()) {
        std::cout << "ERR: input file isnt opened\n";
        return -1;
    }
    if (!output.is_open()) {
        std::cout << "ERR: output file isnt opened\n";
        return -1;
    }
    Graph graph(input);
    Partitionment prt(graph);
    auto start = std::chrono::steady_clock::now();
    unsigned iterations = FM(graph, prt, is_mod);
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
    std::cout << input_file << ' ' << graph.get_edges().size() << ' ' << graph.get_vertices().size() << ' ' << prt.get_cost() << ' ' << time << ' ' << iterations << '\n';
    prt.print(output);
    return 0;
}