class RangeFreqQuery {
    unordered_map<int, vector<int>> mp;
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
    }
    int query(int L, int R, int val) {
        return upper_bound(begin(mp[val]), end(mp[val]), R) 
            -  lower_bound(begin(mp[val]), end(mp[val]), L); 
    }
};