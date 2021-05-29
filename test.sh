#!/bin/bash

TESTER="./checker_linux"

WORST=0
if (( $#<2 ))
then
    echo $0 "[arg len]" "[repeat times]" "(checker)"
    exit
fi

if (( $# == 3))
then
    TESTER=$3
fi
echo "Checker is : $TESTER"
for ((i=0;i<$2;i++))
do
ARG=$(python3 gen.py $1)
./push_swap $ARG | $TESTER $ARG
RET=$(./push_swap $ARG | wc -l)
if (( "$WORST" < "$RET" ));
then
let "WORST = RET"
fi
let "MEAN = MEAN + RET"
done
let "MEAN = MEAN / $2"

echo "Pire  : $WORST"
echo "Moyen : $MEAN"
