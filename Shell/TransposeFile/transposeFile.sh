#!/bin/bash

echo "method 1:"
awk '
{
    for (i = 1; i <= NF; ++i) {
        if (NR == 1) {
            s[i] = $i;
        } else {
            s[i] = s[i] " " $i;
        }
    }
}
    END {
        for (i = 1; s[i] != ""; ++i) {
            print s[i];
        }
}' file.txt

echo -e '\nmethod 2:'
awk '
{
    for (i = 1; i <= NF; ++i) {
        a[NR, i] = $i;
    }
}
NF>p {p = NF}
END {
for (j = 1; j <= p; ++j) {
    str = a[1, j];
    for (i = 2; i <= NR; ++i) {
        str=str" "a[i,j];
    }
    print str;
}
}' file.txt

echo -e "\nmethod 3:"
ncol=`head -n1 file.txt | wc -w`
for i in `seq 1 ${ncol}`
do
    echo `cut -d' ' -f$i file.txt`
done

echo -e "\nmethod 4:"
col=`head -1 file.txt | awk '{print NF}'`
for ((i=1;i<=col;++i))
do
    awk '{printf "%s %s", $'"$i"'," "}END{print ""}' file.txt
done
