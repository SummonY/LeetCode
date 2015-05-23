#!/bin/bash

echo "method 1:"
tr -s ' ' '\n' < words.txt | sort | uniq -c | sort -nr | awk '{print $2, $1}'



echo "method 2:"
cat words.txt | awk '{for(i=1;i<=NF;++i){count[$i]++}} END{for(i in count) {print i,count[i]}}' | sort -k2nr

echo "method 3:"
cat words.txt | tr -s '[[:space:]]' '\n' | sort | uniq -c | sort -nr | sed -r -e 's/[[:space:]]*([[:digit:]]+)[[:space:]]*([[:alpha:]]+)/\2 \1/g'

echo "method 4:"
declare -A HashWord
File="words.txt"

function ReadTxtFile
{
    while read Line
    do
        Word=(${Line})
        for Var in ${Word[@]}
        do
            HashWord+=([${Var}]='1')
            Word[${Var}]=
            for i in ${Word[@]}
            do
                if [[ ${Var} -eq ${i} ]];then
                    Value=${HashWord[${Var}]}
                fi
            done
        done
    done < ${File}

    for Key in ${!HashWord[*]}
    do
        echo "${Key} ${#HashWord[${Key}]}" 
    done | sort -k2nr
}

### Main Login
ReadTxtFile
