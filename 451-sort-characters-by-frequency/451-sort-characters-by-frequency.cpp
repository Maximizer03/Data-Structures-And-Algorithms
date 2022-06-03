class Solution {
public:
	string frequencySort(string s) {
		map<char, int>m;
		for (int i = 0; i < s.size(); i++) {
			m[s[i]]++;
		}
		vector<pair<int ,char>>ans;
		for (auto &x : m) {
			ans.push_back({x.second, x.first});
		}
		sort(begin(ans), end(ans));
		reverse(ans.begin(), ans.end());
		string t = "";
		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < ans[i].first; j++) {
				t += ans[i].second;
			}
		}
		return t;
	}
};