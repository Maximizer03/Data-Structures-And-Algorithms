class Solution {
public:
	int minCost(string s, vector<int>& T) {
		int n = s.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int j = i, mx = 0, sum = 0;
			while (j < n && s[j] == s[i]) {
				sum += T[j];
				mx = max(mx, T[j]);
				j++;
			}
			ans += sum - mx;
			i = j - 1;
		}
		return ans;
	}
};