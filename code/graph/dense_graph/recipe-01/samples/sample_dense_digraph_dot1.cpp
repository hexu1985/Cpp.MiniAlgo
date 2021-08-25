/** \example sample_unweight_dense_graph1.cpp
 * This is an example of how to use the unweight::dense_graph class.
 */
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "dense_graph.hpp"
#include "graph_dot.hpp"

using namespace std;
using namespace mini_algo;

int main(int argc, char *argv[])
{
    string dot_file = "dense_digraph1.dot";
    if (argc >= 2) {
        dot_file = argv[1];
    }

    int vertex_number = 13;
    vector<Edge> edges = {
        {4,2}, {2,3}, {3,2}, {0,6}, {0,1},
        {2,0}, {11,12}, {12,9}, {9,10}, {9,11},
        {8,9}, {10,12}, {4,11}, {4,3}, {3,5},
        {7,8}, {8,7}, {5,4}, {0,5}, {6,4},
        {6,9}, {7,6}};

    DenseGraph graph(vertex_number, true);

    cout << "insert edges\n";
    for (auto edge: edges)
        graph.Insert(edge);

    // show edges
    cout << graph.E() << " edges in graph" << endl;

    cout << "graph to dot format:\n"
        << ToDotStr(graph)
        << endl;

    // save dot file
    cout << "save graph to " << dot_file << " ...\n";
    if (!WriteDotFile(dot_file, graph)) {
        cout << "write dot file " << dot_file << " failed!\n";
        exit(1);
    }

    cout << "write dot file success!" << endl;

    return 0;
}
