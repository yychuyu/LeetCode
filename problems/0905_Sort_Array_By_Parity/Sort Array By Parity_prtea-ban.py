class Solution:
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        import copy
        even_index = 0
        odd_index = len(A) - 1
        ret = copy.copy(A)

        for i in range(len(A)):
            if A[i] % 2 == 0:
                ret[even_index] = A[i]
                even_index += 1
            else:
                ret[odd_index] = A[i]
                odd_index -= 1

        return ret


if __name__ == '__main__':
    A = [3,1,2,4]
    so = Solution()
    print(so.sortArrayByParity(A))
