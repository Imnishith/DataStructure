#
# Calculate sum of N (n>0) numbers using recursion
#

def sum_of_N_numbers(n):
	if(n<=0):
		return 0
	final = n + sum_of_N_numbers(n-1)
	return final

N = 5
print(sum_of_N_numbers(N))
	
