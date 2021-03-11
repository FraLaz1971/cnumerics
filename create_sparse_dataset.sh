#!/usr/bin/env bash
OUTFILEN="statsn.dat"
echo 100 > $OUTFILEN
SEED=$(bc  <<< "1+10*$RANDOM/32768")
# echo "SIGN  = $SIGN" >&2
# echo "RSIGN = $RSIGN" >&2
echo "SEED  = $SEED" >&2
for i in {1..100}
do 
	RSIGN=$(bc  <<< "2*$RANDOM/32768")
    if [[ $RSIGN -eq 0 ]]
    then
        SIGN=-1
    else
        SIGN=1
    fi
    echo "scale=5;100*$SEED*$SIGN*$RANDOM/32768" | bc -l
done >> $OUTFILEN
