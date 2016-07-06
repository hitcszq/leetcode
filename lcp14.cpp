class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<string>::iterator it;
		int min_length=65553;
		int string_num=0;
		//string_num=strs.size();
		string first_prefix;
		string prefix;
		string str_first;
		str_first=*(strs.begin());
		for(it=strs.begin();it!=strs.end();it++)
		{
			if((*it).length()<min_length)
			{
				min_length=(*it).length();
			}
		}
		if(min_length==0)
		{
			return "";
		}
		for(int i=1;i<min_length;i++)
		{
			first_prefix=str_first.assign(0,i);
			for(it=strs.begin();it!=strs.end();it++)
			{
				prefix=str_first.assign(0,i);
					if(prefix!=first_prefix)
					{
						return str_first.assign(0,i);
					}
			}
		}
		return 0;
    }
};