#!/bin/bash

l_f=false
n_f=false 
help_f=false
echo_switch=false

#Creates .backup directory if it doesn't exist
	mkdir -p ~/.backup

#Iterates through each argument passed to the script
for var in "$@"
do

#Checks if argument is a script flag
if [[ $var = "-"* ]]; then
	
	#Checks if $var equals --help flag
	if [[ $var = "--help" ]]; then
		help_f=true
		echo_switch=true

	else
		#Checks if each character of var matches other flags
		for ((i=1; i <${#var}; i++)); do
			
			opt=${var:$i:1}
			

			if [[ $opt = "l" ]]; then
				l_f=true
				echo_switch=true
		
			elif [[ $opt = "n" ]]; then
				n_f=true
				echo_switch=true;

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

#Exits for loop
done

#Actives selected options
if [[ $echo_switch = true ]]; then
	echo
fi

if [[ $l_f = true ]]; then
	ls -R ~/.backup
fi

if [[ $n_f = true ]]; then
	size=$(ls -l ~/.backup | wc -l)
	data=$(du -hb --total  ~/.backup)
	
	echo .backup contains $size files/directories
	echo $data
fi

if [ $help_f = true ]; then
	echo "backup.sh [options] targetFileList"
	echo "-l: lists the contents of the .backup directory" 
	echo "-n: shows the number of files in the .backup directory and how much space they consume"
fi

if [ "$#" -lt 1 ]; then
	echo
	echo_switch=true;
	echo "backup.sh: illegal amount of parameters, try --help"
fi

if [[ $echo_switch = true ]]; then
        echo
fi
