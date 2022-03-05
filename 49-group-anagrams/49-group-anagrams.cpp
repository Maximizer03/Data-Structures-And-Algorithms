class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>>m;
        vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(begin(s),end(s));
            m[s].push_back(i);
        }
        for(auto &x:m){
            vector<string>v;
            for(auto &y:x.second){
                v.push_back(strs[y]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};