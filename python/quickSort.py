#!/usr/bin/python3

def partition(numlist:list, low:int, high:int):
	key = numlist[high]
	i = low - 1
	j = low
	while j < high:
		if numlist[j] <= key:
			i = i + 1
			numlist[i], numlist[j] = numlist[j], numlist[i]
		j = j + 1
	i = i + 1
	numlist[i], numlist[j] = numlist[j], numlist[i]
	return i

def quickSort(numlist:list, low:int, high:int):
	if low < high:
		pos = partition(numlist, low, high)
		quickSort(numlist, low, pos-1)
		quickSort(numlist, pos+1, high)

file = open("data.dat", 'r')
numlist = file.readline().split(',')
numlist = list(map(int, numlist))
file.close()

quickSort(numlist, 0, len(numlist)-1)
print(numlist)