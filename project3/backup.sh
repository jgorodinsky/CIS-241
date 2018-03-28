echo

#Iterates through each argument passed to the script
for var in "$@"
do

#Checks if argument is a script option
if [[ $var = "-"* ]]; then
	
	#Checks if $var equals --help flag
	if [[ $var = "--help" ]]; then
		echo help statement requested


	else
		#Checks if $var matches other flags
		if [[ $var = *"l"* ]]; then

			echo list of backup dir contents requested

		fi
		
		if [[ $var = *"n"* ]]; then
			
			echo number of files and mem used requested

		fi
	fi

fi

#Exits for loop
done

echo
