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
    void calc(TreeNode * root, int dep,int &mx){
        if(root==NULL){
            return;
        }
        mx=max(mx,dep);
        if(root->left!=NULL){
            calc(root->left,dep+1,mx);
        }
        if(root->right!=NULL){
            calc(root->right,dep+1,mx);
        }
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int d=1,mx=1;
        calc(root,d,mx);
        return mx;
    }
};