class Solution(object):
    # def sortArrayByParity(self, A):
    #     a = []
    #     b = []
    #     for i in A:
    #         if(i%2==0):
    #             a.append(i)
    #         else:
    #             b.append(i)
    #     return a+b
    def sortArrayByParity(self, A):
        i=0
        j=len(A)-1
        while(i<j):
            if(A[i]%2==1 and A[j]%2==0):
                temp = A[i]
                A[i] = A[j]
                A[j] = temp
            elif(A[i]%2==0):
                i=i+1
            elif(A[j]%2==1):
                j=j-1
        return A
