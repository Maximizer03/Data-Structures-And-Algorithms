class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>s;
        set<int>cur;
        for(auto x:arr){
            set<int>t;
            t.insert(x);
            for(auto y:cur){
                t.insert((y|x));
            }
            cur=t;
            for(auto x:cur){
                s.insert(x);
            }
        }
        return s.size();
    }
};