class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {//��֦�������ƥ��
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
						maxpri=(*it).length();//�ҵ��ƥ��
						best_pri=*it;
					}
					//break_vec[break_num].push_back(*it);//����ջ���洢�Ѿ�ƥ�䵽�Ĳ���
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
				break_vec[break_num].push_back(best_pri);//����ջ���洢�Ѿ�ƥ�䵽�Ĳ���
				str_rec.push(best_pri);//��¼ǰһ�����������������Ľڵ�
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
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]�ƥ����
"dogs"
["dog","s","gs"]
�ƥ������������������
"abcd"
["a","abc","b","cd"]

�޷����
*/

//��̬�滮

/*����f[i][j]��ʾ��s�д��±�i��j+1���ַ��ܷ����

����˼·���ǣ�

f[i][j]��Ϊһ����λ���ֵ��� �� f[i][j]���Է����ηֱ��ܱ���϶���

 

��ά����������Ҵ����������α���䡣

 */