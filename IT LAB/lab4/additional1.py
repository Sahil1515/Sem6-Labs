class Validity:

    def check_validity(self,exp_input):
        stack=[]
        exp_arr=['(','{','[']

        for ele in exp_input:
            if ele in exp_arr:
                stack.append(ele)
            elif (ele==')' and stack[len(stack)-1]!='(') or (ele=='}' and stack[len(stack)-1]!='{') or (ele==']' and stack[len(stack)-1]!='['):
                return False
            else:
                stack.pop()
        
        if len(stack) !=0:
            return False
        
        return True

exp_input=input("Enter the expression:")

my_obj=Validity()

if my_obj.check_validity(exp_input):
    print("Valid Expression!")
else:
    print("Invalid Expression!")

