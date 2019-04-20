class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]]:
        list = []
        for i in range (len(A[0])):
            temp = [ j[i] for j in A]
            list.append(temp)
        return list