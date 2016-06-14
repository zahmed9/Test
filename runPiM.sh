#!/bin/bash

rm ./pim

g++ -o pim pim.cxx `root-config --cflags --glibs`

rm ./RootFiles/*
rm ./LundFiles/*

x=1
while [ $x -le 1 ]
do
  	<< EOF ./pim 
5000000
$x
EOF

  x=$(( $x + 1 ))
done
