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
    int calc(TreeNode* root, unordered_map<int,int>&m){
        if(root==NULL){
            return 0;
        }
        int leftSum=calc(root->left,m);
        int rightSum= calc(root->right,m);
        
        int subSum= leftSum+rightSum + root->val;
        
        // cout<<subSum<<endl;
        
        m[subSum]++;
        
        return subSum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>m;
        int tot= calc(root,m);
        int mx=0;
        for(auto &x:m){
            mx=max(mx,x.second);
        }
        vector<int>ans;
        for(auto &x:m){
            if(x.second==mx){
                ans.push_back(x.first);
            }
        }
        return ans;
        
    }
};