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
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        if(root==NULL){
            return 0;
        }
        TreeNode *cur=root;
        int ans=-1;
        while(cur!=NULL){
            if(cur->left!=NULL){
                TreeNode *child=cur->left;
                while(child->right != NULL && child->right!=cur){
                    child=child->right;
                }
                if(child->right==NULL){
                    child->right=cur;
                    cur=cur->left;
                }
                else{
                    child->right=NULL;
                    cnt++;
                    if(cnt==k){
                        ans=cur->val;
                    }
                    cur=cur->right;
                }
            }
            else{
                cnt++;
                if(cnt==k){
                    ans=cur->val;
                }
                cur=cur->right;
            }
        }
        return ans;
    }
};