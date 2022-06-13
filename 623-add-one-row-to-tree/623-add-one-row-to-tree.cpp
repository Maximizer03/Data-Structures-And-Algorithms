class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, NULL);
        }
        queue<TreeNode*>q;
        q.push(root);
        int lev = 1;
        for (int i = 0; i < depth - 2; i++) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode *p = q.front();
                q.pop();
                if (p->left) {
                    q.push(p->left);
                }
                if (p->right) {
                    q.push(p->right);
                }
            }
        }
        while(!q.empty()){
            TreeNode *p=q.front();
            q.pop();
            TreeNode *cur= p->left;
            TreeNode *nxt= new TreeNode(val);
            p->left=nxt;
            p->left->left=cur;
            cur=p->right;
            nxt= new TreeNode(val);
            p->right=nxt;
            p->right->right=cur;
        }
        return root;
    }
};