
# import sys
# sys.setrecursionlimit(1500)

class setGenerator:
    arr=[]
    all_subsets=[]
    def get_array_input(self,N):
        print("Enter "+str(N)+" numbers:")
        for i in range(N):
            ele=int(input())
            self.arr.append(ele)

    def helper(self,i,subsets):
        # self.all_subsets.append(subsets)
        print(subsets)
        for ele in range(i,len(self.arr)):
            subsets.append(self.arr[ele])
            self.helper(ele+1,subsets)
            subsets.pop()

       
    def get_unique_sets(self):
        subsets=[]
        self.helper(0,subsets)
        # print(self.all_subsets)
      
my_obj=setGenerator()
N=int(input("Enter N:"))
my_obj.get_array_input(N)

print("Subsets are:")
my_obj.get_unique_sets()

    

