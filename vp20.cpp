class Solution {
public:
    bool isValid(string s) {
        stack<char> judge_stack;
		judge_stack.push(s[0]);
		int len=0;
		len=s.length();
		char top;
		for(int i=1;i<len;++i)
		{
		    if(judge_stack.empty())
		    {
		        judge_stack.push(s[i]);
		    }
		    else{
		    top=judge_stack.top();
			if(top=='{' && s[i]=='}')
				judge_stack.pop();
			else if (top=='(' && s[i]==')')
				{judge_stack.pop();}
			else if (top=='[' && s[i]==']')
				{judge_stack.pop();}
			else
				{judge_stack.push(s[i]);}
		    }
			
		}
		if(judge_stack.empty())
			return true;
		else
			return false;
    }
};
//ac注意判断栈空的情况