#!/bin/bash

g++ -O2 -o exe "$1" || exit 1
g++ -O2 -o check "check.cpp" || exit 1

for filename in [0-9][0-9].in; do
  filename_no_ext=${filename::-3}
  printf "$filename_no_ext: "
  ./exe <$filename >result || exit 1
  ./check $filename_no_ext "$filename_no_ext.out" result || exit 1
done

rm result
rm exe
rm check
