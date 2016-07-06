class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        map={}
        for i in range(len(nums)):
            map[nums[i]]=True
        print map    
        for i in range(len(nums)+1):
            if map.has_key(i)==False:
                missingnum=i
                break
        return missingnum