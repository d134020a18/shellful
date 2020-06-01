#!/bin/bash
if [ "$1" == "-r" ]; then
cat ~/.notes.db | grep "$2\#" | sed -e "s/$2#//"
else
	echo Write the note:
	for (( ; ; )); do
		read note;
		if [ $note == breaknote ]; then
			break;
		else
			echo $1\#$note >> ~/.notes.db
		fi;
	done
fi
