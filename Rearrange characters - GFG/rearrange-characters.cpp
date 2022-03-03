// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string s)
    {
        int n = s.size();
		vector<int>a(26, 0);
		for (int i = 0; i < n; i++) {
			a[s[i] - 'a']++;
		}
		int m = (n + 1) / 2;
		string ans = "";
		for (int i = 0; i < 26; i++) {
			if (a[i] > m) {
			    string empty="-1";
				return empty;
			}
		}
		using pii = pair<int, int>;
		priority_queue< pii, vector<pii> >q;
		vector<int>t;
		for (int i = 0; i < 26; i++) {
			if (a[i]) {
				q.push({a[i], i});
			}
		}
		int pr = -1;
		while (!q.empty()) {
			pii p = q.top();
			q.pop();
			if (p.second == pr) {
				pii nxt = q.top();
				q.pop();
				q.push(p);
				pr = nxt.second;
				t.push_back(pr);
				nxt.first--;
				if (nxt.first) {
					q.push(nxt);
				}
			}
			else {
				pr = p.second;
				p.first--;
				t.push_back(pr);
				if (p.first) {
					q.push(p);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			char c = t[i] + 'a';
			ans += c;
		}
		return ans;
    }
    
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  // } Driver Code Ends