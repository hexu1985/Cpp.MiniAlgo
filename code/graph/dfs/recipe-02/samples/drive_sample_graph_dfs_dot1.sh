#!/usr/bin/env bash

echo "./sample_graph_dfs_dot1 graph_dfs.dot"
./sample_graph_dfs_dot1 graph_dfs.dot
dot graph_dfs.dot -T png -o graph_dfs.png
echo "output png is graph_dfs.png"

