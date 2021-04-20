#!/bin/bash

if [ $# -ne 1 ];then
	echo "No file here"
	exit 1
fi

sed -i 's/^\s*./\U&\E/g' $@
sed -i 's/[\.!?]\s*./\U&\E/g' $@
