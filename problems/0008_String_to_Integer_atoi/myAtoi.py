class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        str = str.strip()
        if not str:
            return 0
        if str[0] != '-' and str[0] != '+' and str[0] not in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
            return 0
        flag = 1
        if str[0] == '-' and len(str) > 1:
            flag = -1
            str = str[1:]
        elif str[0] == '+' and len(str) > 1:
            str = str[1:]
        tmp_str = ""
        for c in str:
            if c in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
                tmp_str += c
            else:
                break
        if not tmp_str:
            return 0
        result = int(tmp_str) * flag
        if result > 2147483647:
            return 2147483647
        elif result < -2147483648:
            return -2147483648
        else:
            return result