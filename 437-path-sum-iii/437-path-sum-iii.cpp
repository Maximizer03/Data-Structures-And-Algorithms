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
    void calc(TreeNode* root, int cur, int sum, unordered_map<int,int>&m, int &ans){
        if(root==NULL){
            return;
        }
        cur+=root->val;
        if(m.find(cur-sum)!=m.end()){
            ans+=m[cur-sum];
        }
        m[cur]++;
        calc(root->left,cur,sum,m,ans);
        calc(root->right,cur,sum,m,ans);
        m[cur]--;
    }
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return 0;
        }
        unordered_map<int,int>m;
        m[0]++;
        int ans=0;
        calc(root,0,sum,m,ans);
        return ans;
    }
};