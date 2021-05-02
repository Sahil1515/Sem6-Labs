

def BubbleSort(arr):
    n=len(arr)
    for i in range(0,n-1):
        for j in range(0,n-i-1):
            if(arr[j]>arr[j+1]):
                   temp=arr[j]
                   arr[j]=arr[j+1]
                   arr[j+1]=temp
                
    return arr

        
arr=[]
n=int(input("Enter the value of n:"))
print("Enter array values:")
for i in range(0,n):
    arr.append(int(input()))

print("\n")

print("Array before Sorting:")
print(arr)
arr=BubbleSort(arr)
print("Sortred Array:")
print(arr)