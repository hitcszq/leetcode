class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> nums_rec;
        int nums_length=0;
		nums_length=nums.size();
		map<int, int>::iterator iter;
		for(int i=0;i<nums_length;++i)
		{
			iter=nums_rec.find(nums[i]);
			if(iter==nums_rec.end())
			{
				 nums_rec.insert(pair<int, int>(nums[i], 1));
			}
			else if(iter->second==1)
			{
				iter->second=2;
			}
		}
		for(iter=nums_rec.begin();iter!=nums_rec.end();++iter)
		{
			if(iter->second==1)
			{
				return iter->first;
			}
		}
		return 0;
    }
};
/*
利用异或操作。异或的性质1：交换律a ^ b = b ^ a，性质2：0 ^ a = a。于是利用交换律可以将数组假想成相同元素全部相邻，于是将所有元素依次做异或操作，相同元素异或为0，最终剩下的元素就为Single Number。时间复杂度O(n)，空间复杂度O(1)*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        //异或
        int elem = 0;
        for(int i = 0; i < n ; i++) {
            elem = elem ^ A[i];
        }
        
        return elem;
    }
};