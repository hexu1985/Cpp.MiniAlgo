#include <vector>
#include <string>
#include <iostream>
#include "sparse_multi_graph.hpp"
#include "graph_dot.hpp"

using namespace std;
using namespace mini_algo;

int main(int argc, char *argv[])
{
    string dot_file = "sparse_multi_graph.dot";
    if (argc >= 2) {
        dot_file = argv[1];
    }

    int vertexNumber = 8;
    vector<Edge> edges = {
        {0,6, .51},
        {0,1, .32},
        {0,2, .29},
        {4,3, .34},
        {5,3, .18},
        {7,4, .46},
        {5,4, .40},
        {0,5, .60},
        {6,4, .51},
        {7,0, .31},
        {7,6, .25},
        {7,1, .21}
    };

    SparseMultiGraph graph(vertexNumber, false);

    cout << "insert edges\n";
    for (auto &edge: edges)
        graph.Insert(&edge);

    // show edges
    cout << graph.E() << " edges in graph" << endl;

    cout << "graph to dot format:\n"
        << ToDotStr(graph)
        << endl;

    // save dot file
    cout << "save graph to " << dot_file << " ...\n";
    if (!WriteDotFile(dot_file, graph)) {
        cout << "open " << dot_file << " failed!\n";
        exit(1);
    }

    cout << "write dot file success!" << endl;

    return 0;
}
