/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
		int sum=0;
        vector<int> sum_n;
        if(root==NULL)
            return 0;
		preorder(root,0,sum_n);
		for(int i=0;i<sum_n.size();++i)
		{
			cout<<sum_n[i]<<endl;
			sum=sum+sum_n[i];
		}
		return sum;
    }
	void preorder(TreeNode* node,int x_parent,vector<int>& sum)
	{
			int x_son=0;
			x_son=node->val+x_parent*10;
			if (node->left!=NULL)
			    preorder(node->left,x_son,sum);
			if (node->right!=NULL)   
			    preorder(node->right,x_son,sum);
			if(node->left==NULL&&node->right==NULL)
			{
			    sum.push_back(x_son);
			}
	}
};
[4,9,0,null,1]