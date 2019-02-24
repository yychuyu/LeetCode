class Solution(object)
    def rotatedDigits(self, N)
        
        type N int
        rtype int
        
        valid = [2, 5, 6, 9]
        nonValid = [3, 4, 7]
        def isGood(num)
            for y in nonValid
                if str(y) in str(num)
                    return False
            return any(str(x) in str(num) for x in valid)
        return sum(map(int, [isGood(n) for n in range(1, N + 1)]))
