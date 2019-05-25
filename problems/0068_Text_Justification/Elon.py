class Solution:
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        result = []
        occupied = -1
        vessel = []
        for word in words:
            if occupied + len(word) + 1 > maxWidth:
                result.append(self.fullyFormat(maxWidth, vessel))
                vessel = []
                occupied = -1
            vessel.append(word)
            occupied += len(word) + 1
        result.append(self.leftFormat(maxWidth,vessel))
        return result
    
    def fullyFormat(self, maxWidth, words):
        if len(words) == 1:
            return self.leftFormat(maxWidth,words)
        wordWidth = len(''.join(words))
        evenslot, moreslot = divmod(maxWidth - wordWidth,len(words)-1)
        result = ''
        for word in words[:-1]:
            normal = word + ' '*evenslot
            if moreslot:
                result += normal + ' '
                moreslot -= 1
            else:
                result += normal
        return result + words[-1]
    
    def leftFormat(self, maxWidth, words):
        result =' '.join(words)
        return result + (maxWidth - len(result))*' '