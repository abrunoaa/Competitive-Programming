#!/bin/bash

for filename in [0-9][0-9]; do
  echo $filename
  ./"Palindromic Refrain" <$filename >result
  ./check $filename "$filename.a" result
done

rm result
