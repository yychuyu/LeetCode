
def find_Longest_Palindromic_Substring(text):
    answer = ""
    length = len(text)
    max = 0

    for middle in range(1, length):
        for start in range(0, middle):
            # case aabaa
            if text[start:middle] == text[middle * 2 - start:middle:-1]:
                if (middle - start) << 1 > max:
                    max = (middle - start) << 1
                    answer = text[start:middle * 2 - start]
            # case aaa=> aa aa
            if text[start:middle + 1] == text[middle * 2 - start:middle - 1:-1]:
                if ((middle - start) << 1) + 1 > max:
                    max = ((middle - start) << 1) + 1
                    answer = text[start:middle * 2 - start + 1]
            if text[start:middle + 1] == text[middle * 2 - start + 1:middle:-1]:
                if ((middle - start) << 1) + 2 > max:
                    max = ((middle - start) << 1) + 2
                    answer = text[start:2 * middle - start + 2]
        if (max <= 2) and (text[middle - 1] == text[middle]):
            max = 2
            answer = text[middle - 1:middle + 1]

    return answer

if __name__ == '__main__':

    print "result = %s" %find_Longest_Palindromic_Substring(raw_input('input string: '))