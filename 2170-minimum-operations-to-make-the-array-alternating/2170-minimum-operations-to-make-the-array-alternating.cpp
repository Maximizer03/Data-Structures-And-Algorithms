class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        map<int,int>ev,od;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ev[nums[i]]++;
            }
            else{
                od[nums[i]]++;
            }
        }
        vector<pair<int,int>>even,odd;
        for(auto &x:ev){
            even.push_back({x.second,x.first});
            // cout<<x.first<<" "<<x.second<<endl;
        }
        for(auto &x:od){
            odd.push_back({x.second,x.first});
            // cout<<x.first<<" "<<x.second<<endl;
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        reverse(even.begin(),even.end());
        reverse(odd.begin(),odd.end());
        int so=n/2;
        int se=(n+1)/2;
        int ans=1e9;
        for(int i=0;i<even.size();i++){
            int cnt=even[i].first;
            int num=even[i].second;
            int ind=-1;
            for(int j=0;j<odd.size();j++){
                int num2= odd[j].second;
                if(num!=num2){
                    ind=j;
                    break;
                }
            }
            if(ind==-1){
                int op= se-cnt+so;
                ans=min(ans,op);
            }
            else{
                cout<<se-cnt<<" "<<so-odd[ind].first<<endl;
                int op= (se-cnt) +  (so- odd[ind].first);
                ans=min(ans,op);
            }
        }
        for(int i=0;i<odd.size();i++){
            int cnt=odd[i].first;
            int num=odd[i].second;
            int ind=-1;
            for(int j=0;j<even.size();j++){
                int cnt2=even[j].first;
                int num2= even[j].second;
                if(num!=num2){
                    ind=j;
                    break;
                }
            }
            if(ind==-1){
                int op= so-cnt+se;
                ans=min(ans,op);
            }
            else{
                int op= so-cnt + se- even[ind].first;
                ans=min(ans,op);
            }
        }
        return ans;
        
    }
};