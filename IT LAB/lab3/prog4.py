
def sort_it(myStr):
    words = [word.lower() for word in myStr.split()]
    words.sort()
    str_ret=""
    for word in words:
        str_ret=str_ret+" " +word

    return str_ret


f=open('file1.txt','r')

str_arr=""
for line in f:
    str_arr=str_arr+sort_it(line)

str_arr=sort_it(str_arr)
print(str_arr)