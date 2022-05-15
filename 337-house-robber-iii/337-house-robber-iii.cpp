class Solution {
public:
    map<pair<TreeNode*,int>,int>dp;
	int calc(TreeNode* root, int tight) {
		if (root == NULL) {
			return 0;
		}
        if(dp.count({root,tight})!=0){
            return dp[{root,tight}];
        }
		int ans = 0;
		if (tight) {
			ans = calc(root->left, 0) + calc(root->right, 0);
		}
		else {
			int op1 = calc(root->left, 0) + calc(root->right, 0);
			int op2 = calc(root->left, 1) + calc(root->right, 1) + root->val;
			ans = max(op1, op2);
		}
		return dp[{root,tight}]=ans;
	}
	int rob(TreeNode* root) {
		return calc(root, 0);
	}
};