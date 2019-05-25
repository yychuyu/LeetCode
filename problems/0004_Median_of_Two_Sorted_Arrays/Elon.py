class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        #dividTwoPart O(log(m,n)):
        #Make nums1 shorter
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        m , n = len(nums1), len(nums2)
        if n == 0:
            return  0
        
        l , r , k = 0, m, (m+n+1) // 2
        
        while l <= r:
            mid = l + (r - l) // 2
            j = k - mid
            if mid < m and nums1[mid] < nums2[j-1]:
                l = mid + 1
            elif mid > 0 and nums1[mid-1] > nums2[j]:
                r = mid - 1
            else:
                print (mid)
                if mid == 0 : leftmax = nums2[j-1]
                elif j == 0: leftmax = nums1[mid-1]
                else : leftmax = max(nums2[j-1],nums1[mid-1])
                if (m + n ) % 2 == 1:
                    return leftmax 
                if mid == m : rightmin = nums2[j]
                elif j == n : rightmin = nums1[mid]
                else: rightmin = min(nums2[j],nums1[mid])

                return (leftmax+rightmin)/2

        
                
        
        
        
        '''
        #findKthNumber O(log(m+n)):
        length = len(nums1)+len(nums2)
        if length % 2 == 1:
            res = self.findKthNumber(nums1,nums2,length//2+1)
            print (res)
        else:
            res = (self.findKthNumber(nums1,nums2,length//2)+self.findKthNumber(nums1,nums2,length//2+1))/2
            
        return res
    
    def findKthNumber(self, nums1, nums2, k):
        # 使nums1更短
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        # nums1空时，直接从nums2中输出第k个数
        if len(nums1) < 1:
            return nums2[k-1]
        if k == 1:
            return (min(nums1[0],nums2[0]))
        mid = k//2-1
        n1 = min(len(nums1)-1,mid)
        if nums1[n1] > nums2[mid]:
            return self.findKthNumber(nums1,nums2[mid+1:], k-mid-1)
        else:
            return self.findKthNumber(nums1[n1+1:],nums2,k-n1-1)
        '''
            