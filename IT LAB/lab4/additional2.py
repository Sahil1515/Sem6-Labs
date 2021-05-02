

class Reverse:

    def reverse_string_by_words(self,str_input):
        my_list=str_input.split(' ')
        new_str=""
        for ele in my_list:
            new_str=new_str+ ele[::-1]+" "
        return new_str[:len(new_str)-1]



str_input=input("Enter String:")
print("Original Stirng : "+str_input)

my_obj=Reverse()
str_input=my_obj.reverse_string_by_words(str_input)

print("String after reversing each word is : "+str_input)