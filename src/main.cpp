#include "Graph.h"
#include "Partitionment.h"
#include <chrono>
unsigned FM(Graph & graph, Partitionment & prt);
int main(int argc, char *argv[]) {
  std::string input_file = argv[1];
  std::ifstream input(input_file);
  std::ofstream output(input_file + ".part.1.txt");
  Graph graph(input);
  Partitionment prt(graph);
  auto start = std::chrono::steady_clock::now();
  unsigned iterations = FM(graph, prt);
  auto time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
  //OutFile << input_file << ' ' << Graph.getEdges().size() << ' ' << Graph.getVertices().size() << ' ' << Prt.getCost() << ' ' << time << ' ' << iterations << '\n';
  prt.print(output);
  return 0;
}