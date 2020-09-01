#
# Listout all substring pattern for a given string
# Logic : For each given character in given recursion tree there are two possibilities,
# 1) You add character
# 2) You don't add
# For ex.
#          ''
#     ''        'A'      (index = 1)
#   ''  'B'  'A'  'AB'   (index = 2)
# As seen in above recursion tree, we need to print all leaf nodes
#


def generate_subsequnce(list,cur,len):
	count = 0
	count1 = 0
	for item in list:
		count1+=1
	if(count1 == len):
		print(cur+'')
		return;
	generate_subsequnce(list,cur,len+1);
	generate_subsequnce(list,cur+list[len],len+1)

list = ['A','B']
cur = ''
len = 0
generate_subsequnce(list,cur,len);
