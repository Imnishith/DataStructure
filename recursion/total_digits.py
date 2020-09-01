#
# Count total number of digits using recursion


def total_digits(count):
	final = 0
	if(count<10):
		return 1
	final = 1+ total_digits(count/10)
	return final
      



count = 100
print(total_digits(count));
