class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n=a.size();
        int ind=0,cnt=1;
        for(int i=1;i<n;i++){
            if(a[i]==a[ind]){
                cnt++;
            }
            else{
                cnt--;
            }
            if(cnt==0){
                ind=i;
                cnt=1;
            }
        }
        return a[ind];
    }
};