if [ $1 = "d" ]; then
	while read x
	do
		if [ -d "$x" ]; then
			echo "$x"
		fi
	done
elif [ $1 = "f" ]; then
	while read x
	do
		if [ -f "$x" ]; then
			echo "$x"
		fi
	done
else
	echo "Wrong argument for select."
fi
