#!/usr/bin/env bash
set -ex
start_string=++++++++++++++++
end_string=-----------------

echo > result32.txt
echo > result64.txt

for BIT_SIZE in 32 64
do
    for VAR in "default" {2..12}
    do
        OPTION="-mpreferred-stack-boundary=$VAR"
        if [ "default" = "$VAR" ]; then
            OPTION=""
        fi

        if [[ "$VAR" -eq 2 && "$BIT_SIZE" -eq 64 ]]; then
            continue
        fi
        filename="flag$BIT_SIZE""_""$VAR"
        gcc main.c -o $filename -m$BIT_SIZE $OPTION -Wno-format-security -no-pie
        echo $start_string >> result$BIT_SIZE.txt
        echo option: $VAR >> result$BIT_SIZE.txt
        gdb -batch -ex 'x/10i main' $filename >> result$BIT_SIZE.txt
        echo $end_String >> result$BIT_SIZE.txt
        # rm $filename
    done
done
