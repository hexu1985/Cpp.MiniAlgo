#!/usr/bin/env bash

echo "./sample_digraph_ts_dot1 digraph_ts1.dot"
./sample_digraph_ts_dot1 digraph_ts1.dot
dot digraph_ts1.dot -T png -o digraph_ts1.png
echo "output png is digraph_ts1.png"

