#!/usr/bin/env bash

echo "./sample_graph_dfs_dot2 graph_dfs2.dot"
./sample_graph_dfs_dot2 graph_dfs2.dot
dot graph_dfs2.dot -T png -o graph_dfs2.png
echo "output png is graph_dfs2.png"

