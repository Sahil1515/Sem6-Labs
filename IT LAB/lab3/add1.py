
def linearSearch(arr,x):
   for i in range(0,len(arr)):
       if x==arr[i]:
           return i
        
arr=[]
n=int(input("Enter the value of n:"))
print("Enter array values:")
for i in range(0,n):
    arr.append(int(input()))

print("\n")
x=int(input("Enter number to serach:"))
res=linearSearch(arr,x)
if res == None:
    print("Noty found!")