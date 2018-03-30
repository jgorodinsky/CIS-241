l_f=false
n_f=false 
help_f=false


echo

#Iterates through each argument passed to the script
for var in "$@"
do

#Checks if argument is a script flag
if [[ $var = "-"* ]]; then
	
	#Checks if $var equals --help flag
	if [[ $var = "--help" ]]; then
		help_f=true
		echo help statement requested


	else
		#Checks if each character of var matches other flags
		for ((i=1; i <${#var}; i++)); do
			
			opt=${var:$i:1}
			

			if [[ $opt = "l" ]]; then

				echo list of backup dir contents requested
				l_f=true
			
		
			elif [[ $opt = "n" ]]; then
			
				echo number of files and mem used requested
				n_f=true

			else
				echo backup.sh: invalid option $opt
			fi


		done
	fi
fi

#Exits for loop
done

echo
