#!/usr/bin/python

"""Bubble Sort"""

list = [3, 5, 4, 9, 8, 2, 1, 7, 6, 0];

print list

swapped = False

for i in range(len(list) or not swapped):
	swapped = False
	for j in range(i + 1, len(list)):
		if list[j] < list[i]:
			temp = list[j]
			list[j] = list[i]
			list[i] = temp
print list
