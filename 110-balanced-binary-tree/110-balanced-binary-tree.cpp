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
    int height(TreeNode * root, int &bal){
        if(root==NULL){
            return 0;
        }
        int lh=height(root->left,bal);
        int rh= height(root->right,bal);
        bal = (bal & (abs(rh-lh)<=1));
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        int bal=1;
        int h= height(root,bal);
        return bal;
    }
};