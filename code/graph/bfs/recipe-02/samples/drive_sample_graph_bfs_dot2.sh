#!/usr/bin/env bash

echo "./sample_graph_bfs_dot2 graph_bfs2.dot"
./sample_graph_bfs_dot2 graph_bfs2.dot
dot graph_bfs2.dot -T png -o graph_bfs2.png
echo "output png is graph_bfs2.png"

