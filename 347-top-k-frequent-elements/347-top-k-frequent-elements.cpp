class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Bucket Sort Superb Technique
        unordered_map<int,int>cnt;
        for(auto x:nums){
            cnt[x]++;
        }
        vector<vector<int>>bucket(nums.size()+1);
        for(auto x:cnt){
            bucket[x.second].push_back(x.first);
        }
        reverse(begin(bucket),end(bucket));
        vector<int>res;
        for(auto x:bucket){
            for(auto y:x){
                res.push_back(y);
                if(res.size()==k){
                    return res;
                }
            }
        }
        return {};
    }
};