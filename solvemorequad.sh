#!/usr/bin/env bash
EX_BADARGS=85
if [[ $# -ge 1 ]]
then
	while IFS= read -r line; do
  	printf ' ./solvequad %s \n' "$line"
  	./solvequad <<< "$line"
	done < "$1"
else
	echo "usage: $0 <input_file>"
	exit $EX_BADARGS
fi
