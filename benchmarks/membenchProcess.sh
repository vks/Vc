#!/bin/sh
if ! test -f "$1"; then
	echo "You need to specify the datafile!" >&2
	exit 1
fi

maxy=7
test -n "$2" && test $2 -gt 0 && maxy=$2

xlabel="Memory Position [GB]"

dir=`dirname $0`

testnames="`cat "$1"|awk '{ if(FNR>2 && index($1, "benchmark.name") != 2) print }'|cut -d: -f1|
cut -c2-|awk '{
if (! ($0 in seen)) {
	seen[$0] = 1
	print
}
}'`"

psfile="$1.ps"
echo -n > "$psfile"

oldIFS="$IFS"
IFS="${IFS# }"
for title in ${testnames}; do
	lmaxy="[0:${maxy}e9]"
	IFS="$oldIFS"
	csv=`mktemp`
	echo -n "#" > "$csv"
	if echo "$title" | grep -q "latency"; then
		gawk -f "$dir/membenchProcess.awk" "-vfilter=$title:" "-vvalueIndex=10" "-vinvert=1" "$1" >> "$csv"
		lmaxy="[40:65]"
		ylabel="Latency [cycles/read]"
	else
		gawk -f "$dir/membenchProcess.awk" "-vfilter=$title:" "-vvalueIndex=8" "-vinvert=0" "$1" >> "$csv"
		ylabel="Throughput [bytes/cycle]"
	fi
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
set ylabel "$ylabel"
set xlabel "$xlabel"
plot [0:$width] ${lmaxy} $commands
EOF
	cat "$csv.ps" >> "$psfile"
	rm "$csv" "$csv.ps"
done
IFS="$oldIFS"

ps2pdf14 "$psfile" "$1.pdf"
rm "$psfile"
xdg-open "$1.pdf"

# vim: noet sw=4 ts=4
