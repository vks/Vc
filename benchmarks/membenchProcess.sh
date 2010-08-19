#!/bin/sh
if ! test -f "$1"; then
	echo "You need to specify the datafile!" >&2
	exit 1
fi

dir=`dirname $0`

gawk -f "$dir/membenchProcess.awk" "-vfilter=read:"  "$1" > "$1_read.csv"
gawk -f "$dir/membenchProcess.awk" "-vfilter=read "  "$1" > "$1_read_prefetch.csv"
gawk -f "$dir/membenchProcess.awk" "-vfilter=add 1:" "$1" > "$1_add1.csv"
gawk -f "$dir/membenchProcess.awk" "-vfilter=add 1 " "$1" > "$1_add1_prefetch.csv"
gawk -f "$dir/membenchProcess.awk" "-vfilter=bzero"  "$1" > "$1_bzero.csv"
