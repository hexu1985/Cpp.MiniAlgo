#!/usr/bin/env bash

echo "./sample_graph_dfs_dot1 graph_dfs1.dot"
./sample_graph_dfs_dot1 graph_dfs1.dot
dot graph_dfs1.dot -T png -o graph_dfs1.png
echo "output png is graph_dfs1.png"

