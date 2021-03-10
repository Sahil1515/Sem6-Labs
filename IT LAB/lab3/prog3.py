
def binarySearch(arr,left,right,x):
    if left>=right:
        return -1
    mid=(left+right)/2
    if arr[mid]==x:
        return mid
    elif x>arr[mid]:
        return binarySearch(arr,mid,right,x)
    else:
        return binarySearch(arr,left,mid,x)
    
arr=[]
n=int(input("Enter the value of n:"))
print("Enter array values;")
for i in range(0,n):
    arr.append(int(input()))

print("\n")
x=int(input("Enter number to serach:"))
res=binarySearch(arr,0,len(arr),x)
print(res)