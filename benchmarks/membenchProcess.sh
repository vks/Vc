#!/bin/sh
if ! test -f "$1"; then
	echo "You need to specify the datafile!" >&2
	exit 1
fi

maxy=7
test -n "$2" && test $2 -gt 0 && maxy=$2

dir=`dirname $0`

testnames="`cat "$1"|awk '{ if(FNR>2) print }'|cut -d: -f1|cut -c2-|sort -u`"

pdfs=""

oldIFS="$IFS"
IFS="${IFS# }"
for title in ${testnames}; do
	IFS="$oldIFS"
	csv=`mktemp`
	echo -n "#" > "$csv"
	gawk -f "$dir/membenchProcess.awk" "-vfilter=$title:" "$1" >> "$csv"
	head=`cat "$csv"|head -n1|cut -f2-`
	width=`cat "$csv"|wc -l`
	width=$(($width-2))
	commands=""
	pos=2
	for h in $head; do
		commands="${commands} \
			\"$csv\" using $pos with linespoints title $h,"
		pos=$(($pos+1))
	done
	commands="${commands%,}"
	gnuplot <<EOF
set terminal postscript color
set output "$csv.ps"
set title "$title"
plot [0:$width] [0:${maxy}e9] $commands
EOF
	rm "$csv"
	ps2pdf14 "$csv.ps" "$csv.pdf"
	rm "$csv.ps"
	pdfs="$pdfs $csv.pdf"
done
IFS="$oldIFS"

pdftk $pdfs cat output "$1.pdf"
rm $pdfs
xdg-open "$1.pdf"
