class myClass:
    arr=[]
    def get_input(self,N):
        print("Enter "+str(N)+" values:")
        for i in range(N):
            ele=int(input())
            self.arr.append(ele)
        

    def get_two_numbers(self,target_sum):
        for i in range(len(self.arr)):
            for j in range(i+1,len(self.arr)):
                if self.arr[i]+self.arr[j]==target_sum:
                    return (i,j)
        return None


myobj=myClass()
N=int(input("Enter the value of N:"))
myobj.get_input(N)

target_sum=int(input("Enter the target sum:"))

indices=myobj.get_two_numbers(target_sum)

if indices==None:
    print("No pair found!")
else:
    print(indices[0],indices[1])
