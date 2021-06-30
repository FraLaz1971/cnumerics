#!/usr/bin/env bash
ofn="statsn.dat";ifn="statsn.tsv"
#print the n-of-samples
head -2 "$ifn" | tail +2 >"$ofn"
#print only the samples column
tail +4 "$ifn" | awk '{print $2}'>>"$ofn"
