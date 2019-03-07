class Solution:
    def isValid(self, s: str) -> bool:
        v=[]
        a=['(','{','[']
        for i in range(len(s)):
            if s[i] in a:
                v.append(s[i])
                continue
            elif s[i]==')':
                if len(v)==0 or v.pop()!='(':
                    return False
            elif s[i]==']':
                if len(v)==0 or v.pop()!='[':
                    return False           
            elif s[i]=='}':
                if len(v)==0 or v.pop()!='{':
                    return False         
        return len(v)==0
        


































































































































































