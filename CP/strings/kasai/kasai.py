# Python code to count total distinct substrings
# of a string

# This is the main function that takes a string
# 'txt' of size n as an argument, builds and return
# the suffix array for the given string
def build_suffix_array(txt, n):
	# Structure to store information of a suffix
	class Suffix:
		def __init__(self, index, rank):
			self.index = index # To store original index
			self.rank = rank # To store ranks and next rank pair
	
	# Store suffixes and their indexes in an array
	# of structures. The structure is needed to sort
	# the suffixes alphabetically and maintain their
	# old indexes while sorting
	suffixes = [Suffix(i, [ord(txt[i])-ord('a'), ord(txt[i+1])-ord('a') if i+1 < n else -1]) for i in range(n)]
	
	# Sort the suffixes using the comparison function
	# defined above.
	suffixes.sort(key=lambda x: x.rank)
	
	# At his point, all suffixes are sorted according
	# to first 2 characters. Let us sort suffixes
	# according to first 4 characters, then first
	# 8 and so on
	ind = [0] * n
	# This array is needed to get the
	# index in suffixes[] from original
	# index. This mapping is needed to get
	# next suffix.
	k = 4
	while k < 2*n:
		# Assigning rank and index values to first suffix
		rank, prev_rank = 0, suffixes[0].rank[0]
		suffixes[0].rank[0] = rank
		ind[suffixes[0].index] = 0
		# Assigning rank to suffixes
		for i in range(1, n):
			# If first rank and next ranks are same as
			# that of previous suffix in array, assign
			# the same new rank to this suffix
			if suffixes[i].rank[0] == prev_rank and suffixes[i].rank[1] == suffixes[i-1].rank[1]:
				prev_rank = suffixes[i].rank[0]
				suffixes[i].rank[0] = rank
			# Otherwise increment rank and assign
			else:
				prev_rank = suffixes[i].rank[0]
				rank += 1
				suffixes[i].rank[0] = rank
			ind[suffixes[i].index] = i
			
		# Assign next rank to every suffix
		for i in range(n):
			nextindex = suffixes[i].index + k//2
			suffixes[i].rank[1] = suffixes[ind[nextindex]].rank[0] if nextindex < n else -1
		
		# Sort the suffixes according to first k characters
		suffixes.sort(key=lambda x: x.rank)
		k *= 2
	# Store indexes of all sorted suffixes in the suffix
	# array
	# Return the suffix array
	return [suffix.index for suffix in suffixes]

# To construct and return LCP
def kasai(txt, suffixArr):
	n = len(suffixArr)
	
	# To store LCP array
	lcp = [0] * n
	
	# An auxiliary array to store inverse of suffix array
	# elements. For example if suffixArr[0] is 5, the
	# invSuff[5] would store 0. This is used to get next
	# suffix string from suffix array.
	invSuff = [0] * n
	
	# Fill values in invSuff[]
	for i in range(n):
		invSuff[suffixArr[i]] = i
		
	# Initialize length of previous LCP
	k = 0
	
	# Process all suffixes one by one starting from
	# first suffix in txt[]
	for i in range(n):
		# If the current suffix is at n-1, then we don’t
		# have next substring to consider. So lcp is not
		# defined for this substring, we put zero
		if invSuff[i] == n-1:
			k = 0
			continue
		
		# j contains index of the next substring to
		# be considered to compare with the present
		# substring, i.e., next string in suffix array
		j = suffixArr[invSuff[i]+1]
		
		# Directly start matching from k'th index as
		# at-least k-1 characters will match
		while i+k < n and j+k < n and txt[i+k] == txt[j+k]:
			k += 1
		lcp[invSuff[i]] = k # lcp for the present suffix.
		
		# Deleting the starting character from the string.
		if k > 0:
			k -= 1
	# return the constructed lcp array
	return lcp

# method to return count of total distinct substring
def count_distinct_substring(txt):
	n = len(txt)
	# calculating suffix array and lcp array
	suffixArr = build_suffix_array(txt, n)
	lcp = kasai(txt, suffixArr)
	
	# n - suffixArr[i] will be the length of suffix
	# at ith position in suffix array initializing
	# count with length of first suffix of sorted
	# suffixes
	result = n - suffixArr[0]
	
	for i in range(1, len(lcp)):
		# subtract lcp from the length of suffix
		result += (n - suffixArr[i]) - lcp[i-1]
		
	result += 1 # For empty string
	return result

# def countSubstrings(s, queries):
# 	for i in queries:
# 		print(count_distinct_substring(s[i[0]:i[1]+1])-1)
	
		


# n,q = map(int,input().split())
# s = input()
# queries = []
# for i in range(q):
#     queries.append(list(map(int,input().split())))
		
# countSubstrings(s, queries)

txt = "ba"
print(count_distinct_substring(txt))



# This code is contributed by Aman Kumar
