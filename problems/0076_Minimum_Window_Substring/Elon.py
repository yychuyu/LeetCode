class Solution:
    def minWindow(self, s: str, t: str) -> str:
        target = collections.defaultdict(int)
        for i in t:
            target[i] += 1
        remain = len(t)
        tail = start = end = 0
        for head, char in enumerate(s, 1):
            remain -= (target[char] > 0)
            target[char] -= 1
            if not remain:
                while target[s[tail]] < 0 and tail < head:
                    target[s[tail]] += 1
                    tail += 1
                if not end or end - start > head - tail:
                    start, end = tail, head
        return s[start:end]
