#!/bin/bash

# Using grep
echo "grep:"
grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt

# Using egrep
echo "egrep:"
egrep -o "^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$" file.txt

# Using sed
echo "sed:"
sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt

# Using awk
echo "awk:"
awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt
