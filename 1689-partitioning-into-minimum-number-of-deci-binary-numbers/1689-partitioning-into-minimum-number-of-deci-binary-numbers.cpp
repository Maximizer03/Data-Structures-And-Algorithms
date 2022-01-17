class Solution {
public:
    int minPartitions(string n) {
        // answer is just the maximum digit value in the strings
        int d=0;
        for(int i=0;i<n.size();i++){
            int dig= n[i]-'0';
            d=max(d,dig);
        }
        return d;
    }
};