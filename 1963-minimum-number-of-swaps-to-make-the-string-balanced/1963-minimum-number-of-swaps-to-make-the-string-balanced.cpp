class Solution {
public:
    int minSwaps(string s) {
        vector<int>v;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                v.push_back(i);
            }
        }
        int sum=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                sum--;
            }
            else if(s[i]=='['){
                sum++;
            }
            if(sum<0){
                cnt++;
                swap(s[i],s[v.back()]);
                v.pop_back();
                sum+=2;
            }
        }
        return cnt;
    }
};