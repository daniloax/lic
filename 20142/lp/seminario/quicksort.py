#!/usr/bin/python

"""Quick Sort"""

list = [3, 5, 4, 9, 8, 2, 1, 7, 6, 0];

print list

for i in range(len(list)):
	for j in range(i + 1, len(list)):
		if list[j] < list[i]:
			temp = list[j]
			list[j] = list[i]
			list[i] = temp
		
print list
