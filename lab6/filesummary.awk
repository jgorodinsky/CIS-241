#!/bin/gawk -f
BEGIN	{
		#counter for number of directories
		d = 0
	
		#counter for number of files	
		f = 0
		
		#counter for number of s-links
		s = 0
	
		#counter for total
		t = 0

		#storage used (Bytes)
		b = 0
	
	}

#regex for determining if the permissions match a directory, file, or link
$1 ~ /^d[rwxts-]{9}/	{d += 1}
$1 ~ /^\-[rwxts-]{9}/	{f += 1}
$1 ~ /^l[rwxts-]{0}/	{s += 1}

			#takes fifth column and adds it to b
			{b += $5}


END	{
		#sets total
		t = d + f + s

		print ""
		print "Here is the summary of files under your home directory:"
		print ""
		print "directories   files     links      total       storage(Bytes)"
		print "============================================================="
		printf "%-13d %-9d %-11d %-10d %-10d\n\n", d, f, s, t, b
	} 
