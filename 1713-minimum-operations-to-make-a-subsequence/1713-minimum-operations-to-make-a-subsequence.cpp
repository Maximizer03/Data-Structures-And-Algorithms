class Solution {
public:
	int LIS(vector<int>&v) {
		int n = v.size();
		vector<int>lis;
		if (n == 0) {
			return 0;
		}
		lis.push_back(v[0]);
		for (int i = 1; i < n; i++) {
			int lb = lower_bound(begin(lis), end(lis), v[i]) - lis.begin();
			if (lb == lis.size()) {
				lis.push_back(v[i]);
			}
			else {
				lis[lb] = v[i];
			}
		}
		return lis.size();
	}
	int minOperations(vector<int>& t, vector<int>& arr) {
		unordered_map<int, int>m;
		int n = t.size();
		for (int i = 0; i < n; i++) {
			m[t[i]] = i;
		}
		vector<int>v;
		for (int i = 0; i < arr.size(); i++) {
			if (m.find(arr[i]) != m.end()) {
				v.push_back(m[arr[i]]);
			}
		}
		return n - LIS(v);
	}
};