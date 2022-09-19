#!/bin/bash
i=1000
echo "I'm ghoul!!!"
while [ $i -gt 7 ]
do
    echo "$i - 7 = $(( $i - 7 ))"
    i=$(( $i - 7 ))
done
