#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "dense_graph.hpp"
#include "graph_dot_vlabel.hpp"
#include "cc.hpp"

using namespace std;
using namespace mini_algo;

int main(int argc, char *argv[])
{
    string dot_file = "graph_cc1.dot";
    if (argc >= 2) {
        dot_file = argv[1];
    }

    int vertex_number = 13;
    vector<Edge> edges = {  {0,1}, {0,9}, {1,9}, {1,4},
                            {8,11},
                            {7,10}, {2,10}, {6,10}, {2,7}, {2,12}, {6,12}, {3,12}, {5,12}
                         };

    DenseGraph graph(vertex_number, false);

    cout << "insert edges\n";
    for (auto edge: edges)
        graph.Insert(edge);

    // show edges
    cout << graph.E() << " edges in graph" << endl;

    CC<DenseGraph> connected_component(graph);
    connected_component.Search();

    cout << connected_component.Count() << " components" << endl;

    cout << "connected-components index:\n";
    auto cc = connected_component.Index();
    vector<string> vmap(vertex_number);
    for (int i = 0; i < vertex_number; i++) {
        cout << i << ": " << cc[i] << endl;
        vmap[i] = std::to_string(i) + " (#" + std::to_string(cc[i]) + ")";
    }
    cout << endl;

    // save dot file
    cout << "save graph to " << dot_file << " ...\n";
    WriteDotFile(dot_file, graph, vmap);

    cout << "write dot file success!" << endl;
    
    return 0;
}
