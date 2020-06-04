#!/bin/bash
fol="$HOME/.bepmuc"
mkdir -p "$fol"
if ! [[ $1 =~ -.* ]]; then
	echo "$@" |
	sed 's/doa/523/g;s/rea/587/g;s/mia/659/g;s/faa/698/g;s/sola/784/g;s/laa/880/g;s/sia/988/g;s/do/262/g;s/re/294/g;s/mi/330/g;s/fa/349/g;s/sol/392/g;s/la/440/g;s/si/494/g;s/\ /\ -q -f\ /g;s/s/\ -l 100/g;s/c/\ -l 200/g;s/n/\ -l 400/g;s/b/\ -l 800/g;s/w/\ /g;s/q/n/g' |
	beep -f $(tee)
else
	if [ "$1" == "-f" ]; then
		cd "$fol"
		cat "$2" | bepmuc $(tee)
	fi
	if [ "$1" == "--add" ]; then
		cd "$fol"
		printf "$3" > "$2"
	fi
	if [ "$1" == "--del" ]; then
		cd "$fol"
		rm "$2"
	fi
fi
