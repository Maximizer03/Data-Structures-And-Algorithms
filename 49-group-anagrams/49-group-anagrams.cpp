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
		unordered_map<string, vector<string>>m;
		vector<vector<string>>ans;
		for (int i = 0; i < strs.size(); i++) {
			string nw = sorted(strs[i]);
			m[nw].push_back(strs[i]);
		}
		for (auto &x : m) {
			ans.push_back(x.second);
		}
		return ans;
	}
};