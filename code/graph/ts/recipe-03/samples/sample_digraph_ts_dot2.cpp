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
    string dot_file = "digraph_ts2.dot";
    if (argc >= 2) {
        dot_file = argv[1];
    }

    //                      0    1    2    3  
    vector<string> vmap = {"内裤",  // 0
                           "裤子",  // 1
                           "腰带",  // 2
                           "衬衣",  // 3
                           "领带",  // 4
                           "夹克",  // 5
                           "袜子",  // 6
                           "鞋",    // 7 
                           "手表",  // 8
                           };
    vector<Edge> edges = {
                            {0, 1}, // 内裤 -> 裤子
                            {0, 7}, // 内裤 -> 鞋
                            {6, 7}, // 袜子 -> 鞋
                            {1, 7}, // 裤子 -> 鞋
                            {1, 2}, // 裤子 -> 腰带
                            {3, 2}, // 衬衣 -> 腰带
                            {3, 4}, // 衬衣 -> 领带
                            {4, 5}, // 领带 -> 夹克
                            {2, 5}, // 腰带 -> 夹克
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
