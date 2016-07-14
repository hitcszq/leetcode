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
			else if(iter->second==2)
			{
				iter->second=3;
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