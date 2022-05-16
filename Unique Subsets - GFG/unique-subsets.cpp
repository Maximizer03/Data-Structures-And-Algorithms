// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void calc(int i, vector<int>cur, vector<vector<int>>&res, int n,vector<int>&arr){
        if(i==n){
            res.push_back(cur);
            return;
        }
        vector<int>v=cur;
        v.push_back(arr[i]);
        calc(i+1,v,res,n,arr);
        int j=i;
        while(j<n && arr[i]==arr[j]){
            j++;
        }
        calc(j,cur,res,n,arr);
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        sort(begin(arr),end(arr));
        vector<vector<int>>res;
        vector<int>cur;
        calc(0,cur,res,n,arr);
        sort(begin(res),end(res));
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends