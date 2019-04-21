from collections import deque


class Solution:
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """

        def check(p, q):
            # if both are None
            if not p and not q:
                return True
            # one of p and q is None
            if not q or not p:
                return False
            if p.val != q.val:
                return False
            return True

        deq = deque([(p, q), ])
        while deq:
            p, q = deq.popleft()
            if not check(p, q):
                return False

            if p:
                deq.append((p.left, q.left))
                deq.append((p.right, q.right))

        return True


if __name__ == '__main__':
    a = [1, 3, 5, 7, 9]
    b = [2, 4, 6, 8, 0]
    d = deque([(a, b), ])
    print(d)
    n = 1
    while d:
        print(n)
        n += 1
        a, b = d.popleft()
        print(a, b)
