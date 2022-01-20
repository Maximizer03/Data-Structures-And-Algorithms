class Solution {
public:
     vector<vector<int>> findSubsequences(vector<int>& nums) {
          vector<vector<int>>seqs;
          int n = nums.size();
          if (n <= 1) {
               return seqs;
          }
          for (int i = 0; i < (1 << n); i++) {
               vector<int>seq;
               for (int j = 0; j < n; j++) {
                    int bit = (1 << j)&i;
                    if (bit > 0) {
                         seq.push_back(nums[j]);
                    }
               }
               if (seq.size() >= 2) {
                    bool flg = 1;
                    for (int j = 1; j < seq.size(); j++) {
                         if (seq[j] < seq[j - 1]) {
                              flg = 0;
                              break;
                         }
                    }
                    if (flg) {
                         seqs.push_back(seq);
                    }
               }
          }
          sort(seqs.begin(), seqs.end());
          vector<vector<int>>ans;
          if (seqs.size()) {
               ans.push_back(seqs[0]);
          }
          for (int i = 1; i < seqs.size(); i++) {
               if (seqs[i] != seqs[i - 1]) {
                    ans.push_back(seqs[i]);
               }
          }
          return ans;
     }
};