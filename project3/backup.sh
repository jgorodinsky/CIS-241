#!/bin/bash

l_f=false
n_f=false 
help_f=false


#Creates .backup directory if it doesn't exist
mkdir -p "~/.backup"

#Iterates through each argument passed to the script
for var in "$@"
do

#Checks if argument is a script flag
if [[ $var = "-"* ]]; then
	
	#Checks if $var equals --help flag
	if [[ $var = "--help" ]]; then
		help_f=true

	else
		#Checks if each character of var matches other flags
		for ((i=1; i <${#var}; i++)); do
			
			opt=${var:$i:1}
			

			if [[ $opt = "l" ]]; then

				l_f=true
			
		
			elif [[ $opt = "n" ]]; then
			
				n_f=true

			else
				echo backup.sh: invalid option $opt
			fi


		done
	fi

#$var is a file to be copied
else	
	if [[ -f $var  ]]; then
		cp $var ~/.backup
	elif [[ -d $var ]]; then
		cp -r $var ~/.backup
	fi
fi
if [[ $l_f = true ]]; then
	echo list of backup dir contents requested
fi

if [[ $n_f = true ]]; then
	echo number of files and mem used requested

fi

if [ $help_f = true ]; then
	echo help statement requested
fi
#Exits for loop
done
