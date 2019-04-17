class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        list = getList(nums1,nums2)
        mid = math.ceil(len(list)/2)
        if len(list)%2 == 0 :
            result = (list[mid-1]+list[mid])/2
        else:
            result = list[mid-1]
        return result;


def getList( nums1: List[int], nums2: List[int]):
    flag = 1
    i = j = 0
    resultList = []
    nums1Length = len(nums1)
    nums2Length = len(nums2)
    while flag:
        if i >= nums1Length:
            resultList = resultList + nums2[j:]
            break
        elif j >= nums2Length:
            resultList = resultList + nums1[i:]
            break
        if nums1[i] < nums2[j]:
            resultList.append(nums1[i])
            i += 1
        else:
            resultList.append(nums2[j])
            j += 1
    return resultList