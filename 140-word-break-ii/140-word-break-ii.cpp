class Solution {
public:
	vector<string>res;
	int dp[25][25];
	void calc(int i, int n, string cur, string &s) {
		if (i == n) {
			res.push_back(cur);
			return;
		}
		cur += " ";
		for (int j = i; j < n; j++) {
            if(dp[i][j]>0){
                string t = cur + s.substr(i, j-i+1);
			    calc(j + 1, n, t, s);
            }
		}

	}
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string>st;
         for(string x:wordDict){
            st.insert(x);
        }
		int n = s.size();
        memset(dp,0,sizeof(dp));
		for (int i = 0; i < n; i++) {
			string cur = "";
			for (int j = i; j < n; j++) {
				cur += s[j];
				if (st.find(cur) != st.end()) {
					dp[i][j] ++;
				}
			}
		}
        // catsanddog
		for (int i = 0; i < n; i++) {
			if (dp[0][i]>0) {
                string cur= s.substr(0,i+1);
				calc(i + 1, n, cur, s);
			}
		}
		return res;
	}
};