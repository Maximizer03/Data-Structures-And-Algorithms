class Solution {
public:
	int largestInteger(int num) {
		string s = to_string(num);
		int n = s.size();
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int n1 = (s[i] - '0');
				int n2 = (s[j] - '0');
				if (n1 % 2 == n2 % 2 && n1 < n2) {
					swap(s[i], s[j]);
				}
			}
		}
		int ans = stoi(s);
		return ans;
	}
};