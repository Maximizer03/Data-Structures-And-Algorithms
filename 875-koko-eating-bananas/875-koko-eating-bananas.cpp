class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=1e9,n=piles.size();
        int ans=-1;
        while(l<=r){
            long long m=l+ (r-l)/2;
            long long s=0;
            for(int i=0;i<n;i++){
                s+= (long long)(piles[i]+m-1)/m;
            }
            if(s<= (long long)(h)){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};