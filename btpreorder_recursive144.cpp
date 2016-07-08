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
    vector<int> preorderTraversal(TreeNode* root) {
		vector<int> seq;
        preorder(root,seq);
		return seq;
    }
	void preorder(TreeNode* node,vector<int> &seq)
	{
		if(node!=NULL)
		{
			seq.push_back(node->val);
			preorder(node->left,seq);
			preorder(node->right,seq);
		}
	}
};