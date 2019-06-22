#from pysnooper import snoop

class Solution:
    """
    step 1: 去除左则空格
    step 2: 根据空格拆分字符，保留第一个字符
    step 3: 如果开头为英文字母，返回0
    step 4: 对于处理后的字符串，从第二个字符开始读取，若出现非数字则停止
    """
    #@snoop()
    def myAtoi(self, str: str) -> int:
        if not str:
            return 0
        ret = 0
        str = str.lstrip(' ')
        str = str.split(' ')[0]
        if str in ('+','-',' ',''):
            return 0
        elif str[0].isalpha():
            return 0
        elif str[0] not in ('+','-','1','2','3','4','5','6','7','8','9','0'):
            return 0
        elif str[0:2] in ('+-','-+'):
            return 0

        # 查找字母位置
        index_alpha = 0
        if str[1:].isnumeric():
            index_alpha = len(str) -1
        else:
            for i in range(1,len(str)):
                if str[i].isnumeric():
                    index_alpha += 1
                else:
                    break
        if index_alpha == 0 and not str[0].isnumeric():
            return 0
        ret = int(str[0:index_alpha+1])

        if ret > 2147483647:
            return 2147483647
        elif ret < -2147483647:
            return -2147483648

        return ret
