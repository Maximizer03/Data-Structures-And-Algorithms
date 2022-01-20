class Solution {
public:
     int calc(TreeNode * root) {
          if (!root) {
               return 0;
          }
          return 1 + max(calc(root->left), calc(root->right));
     }
     int maxDepth(TreeNode* root) {
          if (!root) {
               return 0;
          }
          return calc(root);
     }
};