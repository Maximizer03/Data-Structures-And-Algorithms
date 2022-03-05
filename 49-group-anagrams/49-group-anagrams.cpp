class Solution {
public:
	string sorted(string &s) {
		vector<int>a(26, 0);
		for (int i = 0; i < s.size(); i++) {
			a[s[i] - 'a']++;
		}
		string ans = "";
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < a[i]; j++) {
				char ch = i + 'a';
				ans += ch;
			}
		}
		return ans;
	}
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<int>>m;
		vector<vector<string>>ans;
		for (int i = 0; i < strs.size(); i++) {
			string nw = sorted(strs[i]);
			m[nw].push_back(i);
		}
		for (auto &x : m) {
			vector<string>v;
			for (auto &y : x.second) {
				v.push_back(strs[y]);
			}
			ans.push_back(v);
		}
		return ans;
	}
};