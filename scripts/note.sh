#!/bin/bash
#Check arguments
if [ "$1" == "-r" ]; then
#Get note content in database that match with name
cat ~/.notes.db | grep "\#$2" | sed -e "s/#$2//"
else
	echo Write the note:
	#Do a loop
	for (( ; ; )); do
		read note;
		#Break if detect entered breaknote
		if [ $note == breaknote ]; then
			break;
		else
			#Add the content to database
			echo $note\#$1 >> ~/.notes.db
		fi;
	done
fi
