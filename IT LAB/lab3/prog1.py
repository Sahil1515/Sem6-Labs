def calculator(a,b,op):
    switcher={
        '*':a*b,
        '//':a/b,
        '+':a+b,
        '-':a-b,
    }
    return switcher[op]

a=input("Enter first number:")
b=input("Enter second number:")
op=raw_input("Enter Operation to do (hint: + - * ): ")
res=calculator(a,b,op)
print(res)
