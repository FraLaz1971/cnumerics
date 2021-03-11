#!/usr/bin/env bash
OUTFILEN="sum100.dat"
echo 100 > $OUTFILEN
for i in {1..100}
	do  echo "scale=5;100*$RANDOM/32768" | bc -l
done >> $OUTFILEN
