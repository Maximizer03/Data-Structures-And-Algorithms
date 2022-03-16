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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>cur;
        if(root==NULL){
            return cur;
        }
        while(!q.empty()){
            int s=q.size();
            int mx=INT_MIN;
            for(int i=0;i<s;i++){
                TreeNode *p=q.front();
                q.pop();
                mx=max(mx,p->val);
                if(p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }
            }
            cur.push_back(mx);
        }
        return cur;
    }
};