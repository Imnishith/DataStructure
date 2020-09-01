#
# Count of sum of digits using recursion
#

def sum_of_digits(count):
	if(count<=0):
		return 0
	final = (count%10) + sum_of_digits(count/10);
	return final

count = 1234
print(sum_of_digits(count))
