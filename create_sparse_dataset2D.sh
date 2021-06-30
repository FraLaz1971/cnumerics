#!/usr/bin/env bash
NSAMPLES=100
OUTFILEN="statsn.tsv"
printf "#n.of samples\n" > $OUTFILEN
echo $NSAMPLES >> $OUTFILEN
SEED=$(bc  <<< "1+10*$RANDOM/32768")
echo "SEED  = $SEED" >&2
printf "#n\tsample\n" >> $OUTFILEN
for i in $(eval echo {1..$NSAMPLES})
do 
	RSIGN=$(bc  <<< "2*$RANDOM/32768")
    if [[ $RSIGN -eq 0 ]]
    then
        SIGN=-1
    else
        SIGN=1
    fi
    # echo "SIGN  = $SIGN" >&2
    # echo "RSIGN = $RSIGN" >&2
    printf "%d\t%10.5f \n" $i $(echo "scale=5;100*$SEED*$SIGN*$RANDOM/32768" | bc -l)
done >> $OUTFILEN
#echo e >> $OUTFILEN
