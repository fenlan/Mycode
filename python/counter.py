#!/usr/bin/python3

def numOfBook(strs:list, num:int):
	for x in strs:
		if x == "book":
			num = num + 1
	return num

try:
	file1 = open('file_1.dat', 'r')
	file2 = open('file_2.dat', 'r')

	num1 = 0
	num2 = 0
	strlist1 = file1.readline().split(',')
	strlist2 = file2.readline().split(',')
	num1 = numOfBook(strlist1, num1)
	num2 = numOfBook(strlist2, num2)

	print("num1:", num1, ", num2:", num2)
	print("num:", num1 + num2)

	file2.close()
	file1.close()

except Exception as e:
	print("Don't have this file!!!")