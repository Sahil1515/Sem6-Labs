
class myClass:
    int_arr =[1000,900,500,400,100,90,50,40,10,9,5,4,1]
    rom_arr=['M','CM','D','CD','C','XC','L','XL','X','IX','V','IV','I']
    roman_number=""
    def int_to_roman(self,number):
        i=0
        while number>0:
            for _in in range(number//self.int_arr[i]):
                self.roman_number=self.roman_number+self.rom_arr[i]
                number=number-self.int_arr[i]
            i=i+1
        return self.roman_number


myobj=myClass()
number=int(input("Enter number:"))
roman_number=myobj.int_to_roman(number)
print(str(number) +" to " + str(roman_number))


# https://www.calculatorsoup.com/calculators/conversions/roman-numeral-converter.php