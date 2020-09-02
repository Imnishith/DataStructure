#
# Check if given number is palindrom
# return 1 : If number of palindrom
# return 0 : If number if non-palindrom
# palindrop number = Org number and reverse of original comes same For Ex. = 101
#


def palin(N,rev):
	if(N==0):
		return rev
	final = palin(N/10,(rev*10+(N%10)))
	return final


def check_palin(n):
	rev_num = palin(n,0);
	#print(rev_num)
	if(rev_num == n):
		print('1')
	else:
		print('0')


num = 101
check_palin(num)
	
	
