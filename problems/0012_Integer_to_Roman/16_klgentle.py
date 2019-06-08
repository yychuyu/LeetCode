class Solution:
    """
    8 = 5 + 3 = V + I + I + I = VIII
    58 = 50 + 8 = L + VIII = LVIII
    68 = 50 + 10 + 8 = L + X + VIII (注意顺序是50+10, 不能写成10+50， XL = 90)

    解题思路是将个位十位百位千位分别转化为对应的字母，然后串起来

    如：1994可以拆成 1000 + 900 + 90 + 4, 分别找到对应的罗马字母：M CM XC IV

    接下来就考虑怎么将数字拆分，比如首位可以这样：1994 / 1000 * 1000 = 1000，百位，十位类似的。
    """

    def __init__(self):
        self.roman_dict = {
            1: "I",
            2: "II",
            3: "III",
            4: "IV",
            5: "V",
            6: "VI",
            7: "VII",
            8: "VIII",
            9: "IX",
            10: "X",
            40: "XL",
            50: "L",
            90: "XC",
            100: "C",
            500: "D",
            400: "CD",
            900: "CM",
            1000: "M",
        }

    def intToRoman(self, num: int) -> str:
        if not 1 <= num <= 3999:
            return
        if num in self.roman_dict.keys():
            return self.roman_dict.get(num)
        ret = ""
        if num % 10 > 0:  # 8
            ret = self.func(num, 1, ret)

        num = num // 10 * 10
        if num % 100 > 0:  # 50
            ret = self.func(num, 10, ret)

        num = num // 100 * 100
        if num % 1000 > 0:  # 500
            ret = self.func(num, 100, ret)

        num = num // 1000 * 1000
        if num % 10000 > 0:  # 5000
            ret = self.func(num, 1000, ret)

        return ret

    def func(self, num, min_d: int, ret: str) -> str:
        d = num % (min_d * 10)
        med = 5 * min_d
        if d in self.roman_dict.keys():
            ret = self.roman_dict.get(d) + ret
        else:
            if d > med:
                ret = (
                    self.roman_dict.get(med)
                    + self.roman_dict.get(min_d) * ((d - med) // min_d)
                    + ret
                )
            else:
                ret = self.roman_dict.get(min_d) * (d // min_d) + ret
        return ret

