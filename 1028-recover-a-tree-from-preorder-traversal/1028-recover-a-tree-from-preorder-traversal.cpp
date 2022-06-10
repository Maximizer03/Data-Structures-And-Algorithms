class Solution {
public:
    void calc(int i, int d, TreeNode *root, vector<pair<int, int>>&p) {
        int n = p.size();
        if (i == n) {
            return;
        }
        int cnt = 0;
        vector<int>v;
        for (int j = i + 1; j < n; j++) {
            if (p[j].second <= p[i].second || cnt >= 2) {
                break;
            }
            if (p[j].second == p[i].second + 1) {
                cnt++;
                if (cnt == 1) {
                    TreeNode * L =  new TreeNode(p[j].first);
                    root->left = L;
                    calc(j, d + 1, L, p);
                }
                else {
                    TreeNode * R =  new TreeNode(p[j].first);
                    root->right = R;
                    calc(j, d + 1, R, p);
                }
            }
        }
    }
    TreeNode* recoverFromPreorder(string s) {
        vector<pair<int, int>>p;
        int n = s.size();
        int cnt = 0;
        string cur = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '-') {
                cnt++;
            }
            else {
                cur = "";
                int j = i;
                while (j < n && s[j] != '-') {
                    cur += s[j];
                    j++;
                }
                int num = stoi(cur);
                p.push_back({num, cnt});
                i = j - 1;
                cnt = 0;
            }
        }
        TreeNode * root = new TreeNode(p[0].first);
        calc(0, 0, root, p);
        return root;
    }
};