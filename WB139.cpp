class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {//剪枝搜索，最长匹配
        int setnum=0;
		int break_flag=0;
		int break_num=0;
		int maxpri=0;
		string best_pri;
		string pop_str;
		setnum=wordDict.size();
		stack<string> str_rec;
		vector<vector<string>> break_vec(100);
		unordered_set<string>::iterator it;
		if(setnum==0&&!s.empty())
		{
		
		    return false;
		}
		
		while(!s.empty()){
			for(it=wordDict.begin();it!=wordDict.end();++it)
			{
				if(isprefix(s,*it)&&!istest(*it,break_vec[break_num]))
				{
					if((*it).length()>maxpri)
					{	
						maxpri=(*it).length();//找到最长匹配
						best_pri=*it;
					}
					//break_vec[break_num].push_back(*it);//搜索栈，存储已经匹配到的部分
					//str_rec.push(*it);
					break_flag=1;
					//s.assign(s,(*it).length(),s.length()-(*it).length());
					//cout<<s<<endl;
					//break_num++
				}
			}
            if(break_flag==0)
			{
			    break_vec[break_num].clear();
			    --break_num;
			    if(break_num==-1)
			        return false;
			    pop_str=str_rec.top();
			    str_rec.pop();
			    s=pop_str.append(s);
			    cout<<s<<break_num<<endl;
			}
			else
			{
				break_vec[break_num].push_back(best_pri);//搜索栈，存储已经匹配到的部分
				str_rec.push(best_pri);//记录前一层搜索树中搜索过的节点
				s.assign(s,best_pri.length(),s.length()-best_pri.length());
				maxpri=0;
				break_num++;
				best_pri="";
			}
			break_flag=0;
		}
		return true;
    }
	bool isprefix(string s,  string a)
	{
		int len=a.length();
		int s_len=a.length();
		bool flag=true;
		if(len>s_len)
		{
			return false;
		}
		for(int i=0;i<len;++i)
		{
			if(s[i]!=a[i])
			{
				flag=false;
				break;
			}
		}
		//cout<<flag;
		return flag;
	}
	bool istest(string s,vector<string> ve)
	{
	    int ve_num=0;
	    ve_num=ve.size();
	    if(ve_num==0)
	    {
	        return false;
	    }
	    else
	    {
	        for(int i=0;i<ve_num;++i)
	        {
	            if(ve[i]==s)
	                return true;
	        }
	    }
	    return false;
	}
};
/*
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]最长匹配解决
"dogs"
["dog","s","gs"]
最长匹配引出下面用例错误
"abcd"
["a","abc","b","cd"]

无法解决
*/

//动态规划

/*其中f[i][j]表示从s中从下标i起j+1个字符能否被组合

具体思路就是：

f[i][j]作为一整段位于字典中 或 f[i][j]可以分两段分别能被组合而成

 

二维数组从左往右从上往下依次被填充。

 */