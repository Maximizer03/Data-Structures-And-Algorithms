class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>m;
        int mx=0;   
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(m.find(x+1)==m.end()){
                int st=x;
                int cnt=0;
                while(m.find(st)!=m.end()){
                    cnt++;
                    st--;
                }
                mx=max(mx,cnt);
            }
        }
        return mx;
    }
};