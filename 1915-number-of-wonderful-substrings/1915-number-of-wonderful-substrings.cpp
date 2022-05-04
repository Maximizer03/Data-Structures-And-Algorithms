class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans=0;
        int mask=0;
        unordered_map<int,int>cnt;
        cnt[0]++;
        for(int i=0;i<word.size();i++){
            mask= mask ^ (1<<(word[i]-'a'));
            ans+=cnt[mask];
            for(int j=0;j<10;j++){
                int new_mask= mask ^(1<<j);
                ans+=cnt[new_mask];
            }
            cnt[mask]++;
        }
        return ans;
    }
};