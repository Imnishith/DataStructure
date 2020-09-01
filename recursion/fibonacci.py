#
# Calculate nth fibonacci number using recursion
# fib[0] = 0
# fib[1] = 1
# fib[2] = fib[0] + fib[1]
# fib[n] = fib[n-2] + fib[n-1]
# 

def nth_fib(n):
	if n==0:
		return 0
	if n==1:
		return 1
	
	final = nth_fib(n-2)+nth_fib(n-1)
	return final

n = 20
print(nth_fib(n))

