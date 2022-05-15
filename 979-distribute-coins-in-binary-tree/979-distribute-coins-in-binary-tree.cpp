class Solution {
public:
	int ans;
	pair<int, int> calc(TreeNode* root) {
		if (root == NULL) {
			return {0, 0};
		}
		pair<int, int>L = calc(root->left);
		pair<int, int>R = calc(root->right);
        
		int subTreesize = 1 + L.second + R.second;
		int totalCoins = L.first + R.first + root->val;

		ans += abs(subTreesize - totalCoins);

		return {totalCoins, subTreesize};
	}
	int distributeCoins(TreeNode* root) {
		ans = 0;
		calc(root);
		return ans;
	}
};