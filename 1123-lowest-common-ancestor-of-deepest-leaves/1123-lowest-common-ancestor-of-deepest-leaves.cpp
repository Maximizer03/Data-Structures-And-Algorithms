class Solution {
public:
	TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q) {
		if (root == NULL || root == p || root == q) {
			return root;
		}
		TreeNode *left = lca(root->left, p, q);
		TreeNode *right = lca(root->right, p, q);
		if (!left) return right;
		if (!right) return left;
		return root;
	}
	TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // lca of leftmost deepest and rightmost deepest will be the answer
		if (root == NULL) return root;
		queue<TreeNode*>q;
		vector<TreeNode*>prev;
		q.push(root);
		while (!q.empty()) {
			prev.clear();
			int s = q.size();
			for (int i = 0; i < s; i++) {
				TreeNode *p = q.front();
				prev.push_back(p);
				q.pop();
				if (p->left) q.push(p->left);
				if (p->right)q.push(p->right);
			}
		}
		TreeNode *u = prev[0];
		TreeNode *v = prev.back();
		return lca(root, u, v);
	}
};