class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []
        if n < k:
            return result
        number_sets = list(range(1, n + 1))
        self.comb2(k, 0, number_sets, [], result, n)
        return result

    def comb2(self, remain, head_index, number_sets, vessel, result, length):
        if remain > length - head_index:
            return
        if not remain:
            result.append(vessel)
        else:
            while head_index < len(number_sets):
                self.comb2(remain - 1, head_index + 1, number_sets,
                           vessel + [number_sets[head_index]], result, length)
                head_index += 1