from itertools import permutations
from functools import reduce

class Solution:

    def add(self, x, y):
        return str(x) + str(y)

    def convert_to_permutations(self, A):
        list_permu = []
        list_answer = []
        for i in permutations(A):
            list_permu.append(list(i))

        for i in list_permu:
            answer = reduce(self.add, i)
            list_answer.append(answer)
        return list_answer

    def add_again(self, a):
        add = list(str(a))
        return add[0] + add[1] + ':' + add[2] + add[3]

    def largestTimeFromDigits(self, A):
        new_list = sorted(self.convert_to_permutations(A), reverse=True)
        # print(new_list)

        list_answer = [
            i for i in new_list
            if '0' <= i <= '2359' and i[2] <= '5'
        ]

        if len(list_answer) > 0:
            return self.add_again(list_answer[0])
        else:
            return ''
    