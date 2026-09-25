#!/bin/bash
# back-from-the-future.cpp を N 回実行し、出力値の頻度を集計する
# 使い方: ./tally.sh [実行回数]   (既定: 1000)
set -euo pipefail

cd "$(dirname "$0")"

N=${1:-1000}
SRC=back-from-the-future.cpp
BIN=./p

g++ -std=c++17 -pthread -o "$BIN" "$SRC"

for ((i = 0; i < N; i++)); do
    "$BIN"
done | sort -n | uniq -c | awk -v n="$N" '
    { printf "%s\t%d\t%6.2f%%\n", $2, $1, $1 * 100 / n }
    END { printf "----\n合計\t%d\n", n }
'
