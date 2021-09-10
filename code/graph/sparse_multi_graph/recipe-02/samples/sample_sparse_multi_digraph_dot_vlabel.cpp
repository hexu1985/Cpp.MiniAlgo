#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "sparse_multi_graph.hpp"
#include "graph_dot_vlabel.hpp"

using namespace std;
using namespace mini_algo;

int main(int argc, char *argv[])
{
    string dot_file = "sparse_multi_digraph_vlabel.dot";
    if (argc >= 2) {
        dot_file = argv[1];
    }

    //                      0    1    2    3  
    vector<string> vmap = {"s", "v", "w", "t"};
    vector<Edge> edges = {
                            {0,1,1}, // s - v
                            {0,2,4}, // s - w 
                            {1,2,2}, // v - w
                            {1,3,6}, // v - t
                            {2,3,3}, // w - t
                         };
    int vertex_number = vmap.size();

    SparseMultiGraph digraph(vertex_number, true);

    cout << "insert edges\n";
    for (auto &edge: edges)
        digraph.Insert(&edge);

    // show edges
    cout << digraph.E() << " edges in graph" << endl;

    // save dot file
    cout << "save graph to " << dot_file << " ...\n";
    WriteDotFile(dot_file, digraph, vmap);

    cout << "write dot file success!" << endl;

    return 0;
}
