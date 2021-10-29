#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "dense_graph.hpp"
#include "graph_dot_vlabel.hpp"
#include "ts.hpp"

using namespace std;
using namespace mini_algo;

int main(int argc, char *argv[])
{
    string dot_file = "digraph_ts1.dot";
    if (argc >= 2) {
        dot_file = argv[1];
    }

    //                      0    1    2    3  
    vector<string> vmap = {"s", "v", "w", "t"};
    vector<Edge> edges = {
                            {0,1}, // s - v
                            {0,2}, // s - w 
                            {1,2}, // v - w
                            {1,3}, // v - t
                            {2,3}, // w - t
                         };
    int vertex_number = vmap.size();

    DenseGraph digraph(vertex_number, true);

    cout << "insert edges\n";
    for (auto edge: edges)
        digraph.Insert(edge);

    // show edges
    cout << digraph.E() << " edges in graph" << endl;

    TS<DenseGraph> topo_sort(digraph);
    topo_sort.Search();

    cout << "topo-sort order:\n";
    auto tsI = topo_sort.Index();
    for (int i = 0; i < vertex_number; i++) {
        cout << vmap[i] << ": " << tsI[i] << endl;
        vmap[i] += " (#" + std::to_string(tsI[i]) + ")";
    }
    cout << endl;

    // save dot file
    cout << "save graph to " << dot_file << " ...\n";
    WriteDotFile(dot_file, digraph, vmap);

    cout << "write dot file success!" << endl;

    return 0;
}
