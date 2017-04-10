from collections import defaultdict

def my_atoi(string):
    i = 0
    j = 0
    substring_int = []
    substring = defaultdict(list)      # create a dict with list
    
    while True:
        if i == len(string) or i == MAX :
            break
        if ord(string[i]) == 32 :    #white-space
            i = i+1
            j = j+1
            continue

        substring[j].append(string[i])
        i = i+1

    for m in range(j+1):
        v = conver(substring[m])
        substring_int.append(v)
    
    return substring_int

def conver(substring):
    con_value = 0
    bite = len(substring)

    if substring[0] == '-':
        if substring[1] == '0' and substring[2] == 'x':
            del substring[0]
            del substring[0]
            del substring[0]
            con_value = only_digits_con(substring, 16)
        elif substring[1] == '0':
            del substring[0]
            del substring[0]
            con_value = only_digits_con(substring, 8)
        else :
            del substring[0]
            con_value = only_digits_con(substring, 10)

        con_value = 0 - con_value

    elif substring[0] == '+':
        if substring[1] == '0' and substring[2] == 'x':
            del substring[0]
            del substring[0]
            del substring[0]
            con_value = only_digits_con(substring,16)
        elif substring[1] == '0':
            del substring[0]
            del substring[0]
            con_value = only_digits_con(substring, 8)
        else :
            del substring[0]
            con_value = only_digits_con(substring, 10)

    elif substring[0] == '0':
        if substring[1] == 'x':
            del substring[0]
            del substring[0]
            con_value = only_digits_con(substring, 16)
        else :
            del substring[0]
            con_value = only_digits_con(substring, 8)
    else :
        con_value = only_digits_con(substring, 10)

    return con_value

def only_digits_con(substring, base):
    substring_int = 0

    for i in range(len(substring)):
        if string[i].isdigit():
            substring_int = substring_int*base + int(substring[i])
        else :
            substring_int = substring_int*base + ord(substring[i]) - ord('A') + 10

    return substring_int

MAX = 200
substring_int = []
string = '1234 -1234 +1234 01234 -01234 +01234 0x1234 -0x1234 +0x1234'
li = list(string)

substring_int = my_atoi(li)
for i in range(len(substring_int)):
    print(substring_int[i], end=" ")
print()
