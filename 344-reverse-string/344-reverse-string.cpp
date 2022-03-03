class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0,r=s.size()-1;
        while(l<r){
            char ch= s[r];
            s[r]=s[l];
            s[l]=ch;
            l++;r--;
        }
    }
};