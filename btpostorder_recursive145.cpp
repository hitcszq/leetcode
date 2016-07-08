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
    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> seq;
        postorder(root,seq);
		return seq;
    }
	void postorder(TreeNode* node,vector<int> &seq)
	{
		if(node!=NULL)
		{
			postorder(node->left,seq);
			postorder(node->right,seq);
			seq.push_back(node->val);
		}
	}
};