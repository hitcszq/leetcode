class Solution(object):
    def longestPalindrome(self,s):
        """"
        type s:str
        rtype :str
        """
        #abcddce
        return_num=0
        start_point=0
        end_point=0
        stack_s=[]
        for i in range(len(s)):
            if not stack_s:
                stack_s.append(s[i])
            elif stack_s[len(stack_s)-1]==s[i]:
                j=len(stack_s)-1
                i_iter=i
                cur_num=0
                while  stack_s[j]==s[i_iter] :
                    cur_num+=2
                    j=j-1
                    i_iter=i_iter+1
                    if j<0 or i_iter>len(s)-1:
                        break
                if cur_num>return_num:
                    return_num=cur_num
                    start_point=j
                    end_point=i_iter
                if i+1<=len(s)-1 and stack_s[len(stack_s)-1]==s[i+1]:
                    j=len(stack_s)-1
                    i_iter=i+1
                    cur_num=1
                    while  stack_s[j]==s[i_iter] :
                        cur_num+=2
                        j=j-1
                        i_iter=i_iter+1
                        if j<0 or i_iter>len(s)-1:
                            break
                    if cur_num>return_num:
                        return_num=cur_num
                        start_point=j
                        end_point=i_iter
                stack_s.append(s[i])
            elif i+1<=len(s)-1 and stack_s[len(stack_s)-1]==s[i+1]:
                j=len(stack_s)-1
                i_iter=i+1
                cur_num=1
                while  stack_s[j]==s[i_iter] :
                    cur_num+=2
                    j=j-1
                    i_iter=i_iter+1
                    if j<0 or i_iter>len(s)-1:
                        break
                if cur_num>return_num:
                    return_num=cur_num
                    start_point=j
                    end_point=i_iter
                stack_s.append(s[i])            
            else:
                stack_s.append(s[i])
        if len(s)==1:
            return s
        else:
            return "".join(stack_s[start_point+1:end_point])