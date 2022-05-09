class Solution {
public:
    void calc(int i, vector<int>&A, vector<vector<int>>&res, vector<int>cur){
        if(i==A.size()){
            res.push_back(cur);
            return;
        }
        cur.push_back(A[i]);
        calc(i+1,A,res,cur);
        cur.pop_back();
        int j=i;
        while(j<A.size() && A[i]==A[j]){
            j++;
        }
        calc(j,A,res,cur);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& A) {
        sort(begin(A),end(A));
        vector<vector<int>>res;
        vector<int>cur;
        calc(0,A,res,cur);
        return res;
    }
};