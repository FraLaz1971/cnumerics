#!/usr/bin/env bash
./configure
make
make install
make clean
echo "installed in bin/ the following programs"
ls -lhrt bin

