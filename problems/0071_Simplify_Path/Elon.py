class Solution:
    def simplifyPath(self, path: str) -> str:
        result = []
        for dictory in path.split('/'):
            if not dictory or dictory == '.':
                continue
            elif dictory == '..':
                if not result:
                    continue
                else:
                    result.pop(-1)
            else:
                result.append(dictory)
        return '/' + '/'.join(result)


class Solution:
    def simplifyPath(self, path: str) -> str:
        result = []
        for dictory in [x for x in path.split('/') if x and x != '.']:
            if dictory == '..':
                if result:
                    result.pop()
            else:
                result.append(dictory)
        return '/' + '/'.join(result)