
class myClass:
    my_string=""

    def get_String(self):
        self.my_string=input("Enter the string:")

    def print_String(self):
        new_str=self.my_string.upper()
        print(new_str)

my_obj=myClass()

my_obj.get_String()
my_obj.print_String()
