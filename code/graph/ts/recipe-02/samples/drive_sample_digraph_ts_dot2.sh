#!/usr/bin/env bash

echo "./sample_digraph_ts_dot2 digraph_ts2.dot"
./sample_digraph_ts_dot2 digraph_ts2.dot
dot digraph_ts2.dot -T png -o digraph_ts2.png
echo "output png is digraph_ts2.png"

