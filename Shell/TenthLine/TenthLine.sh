#!/bin/bash

# method 1
awk 'NR==10{print $0}' file.txt

# method 2
awk 'NR==10' file.txt

# method 3
sed -n 10p file.txt

# method 4
tail -n+10 file.txt | head -1

# method 5
cnt=0
while read line && [ $cnt -le 10 ]; do
    let 'cnt=cnt+1'
    if [ $cnt -eq 10 ]; then
        echo $line
        exit 0
    fi
done < file.txt
