class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& t) {
		int n = t.size();
		vector<int>ans(n);
		vector<pair<int, int>>st;
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && t[i] >= st.back().first) {
				st.pop_back();
			}
			ans[i] = st.empty() ? 0 : st.back().second - i;
			st.push_back({t[i], i});
		}
		return ans;
	}
};