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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int cnt=0;
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>v;
            while(s--){
                TreeNode * p=q.front();
                q.pop();
                v.push_back(p->val);
                if(p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }
            }
            if(cnt%2){
                reverse(v.begin(),v.end());
            }
            ans.push_back(v);
            cnt++;
        }
        return ans;
    }
};