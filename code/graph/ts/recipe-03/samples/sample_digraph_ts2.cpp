#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "dense_graph.hpp"
#include "graph_print_vlabel.hpp"
#include "ts.hpp"

using namespace std;
using namespace mini_algo;

int main(int argc, char *argv[])
{
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

    // show adjLists
    cout << "graph after insert edges:\n";
    Print(cout, digraph, vmap);
    cout << endl;

    TS<DenseGraph> topo_sort(digraph);
    topo_sort.Search();

    cout << "topo-sort order:\n";
    auto tsI = topo_sort.Index();
    for (int i = 0; i < vertex_number; i++) {
        cout << vmap[i] << ": " << tsI[i] << endl;
    }
    cout << endl;

    std::vector<int> ts(vertex_number, -1);
    for (int i = 0; i < vertex_number; i++) {
        ts[tsI[i]] = i;
    }
    cout << "topo-sort:\n";
    for (int i = 0; i < vertex_number; i++) {
        cout << vmap[ts[i]] << ", ";
    }
    cout << endl;

    return 0;
}
