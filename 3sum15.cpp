class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
		int nums_num=0;
		nums_num=nums.size();
		int k=0;
		sort(nums.begin(),nums.end());
		for(int i=0;i<nums_num;++i)
		{
			if(i==0||nums[i]!=nums[i-1])
			{	
				k=nums_num;
				for(int j=i+1;j<nums_num;++j)
				{
					if(j>=k)
						break;
					if(j==i+1||(nums[j]!=nums[j-1]))
					{
						if(nums[i]+nums[j]+nums[k]==0)
						{
							vector<int> add(3);
							add[0]=nums[i];
							add[1]=nums[j];
							add[2]=nums[k];
							triplets.push_back(add);
							--k;
						}
						else if(nums[i]+nums[j]+nums[k]>0)
						{
							--j;
							--k;
						}
						else
							continue;
					}
				}
			} 
			
		}
		return triplets;
    }
};