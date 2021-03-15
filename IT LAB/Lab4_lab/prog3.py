class PowClass:
    x=0
    n=0
    pow_var=1
    def get_input(self):
        print("Enter value of x:")
        self.x=int(input())
        print("Enter value of n:")
        self.n=int(input())

    def find_power(self):
        for i in range(self.n):
            self.pow_var=self.pow_var*self.x
        return self.pow_var


my_obj=PowClass()
my_obj.get_input()
pow_var=my_obj.find_power()
print(str(my_obj.x)+"^"+str(my_obj.n)+" = "+str(pow_var))