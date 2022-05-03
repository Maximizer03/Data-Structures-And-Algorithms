/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	TreeNode * head = new TreeNode(0);
	void dfs(TreeNode *root) {
		if (root == NULL) {
			return;
		}
		dfs(root->left);
		head->right = root;
		root->left = NULL;
		head = root;
		dfs(root->right);
	}
	TreeNode* increasingBST(TreeNode* root) {
		TreeNode * ans = head;
		dfs(root);
		return ans->right;
	}
};