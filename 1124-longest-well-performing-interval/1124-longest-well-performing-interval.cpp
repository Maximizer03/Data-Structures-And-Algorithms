class Solution {
public:
	int longestWPI(vector<int>& hours) {
		int mx = 0;
		unordered_map<int, int>m;
		int n = hours.size(), sum = 0;
		for (int i = 0; i < n; i++) {
			if (hours[i] > 8) {
				sum++;
			}
			else {
				sum--;
			}
			if (sum > 0) {
				mx = max(mx, i + 1);
			}
			if (sum <= 0) {
				if (m.find(sum - 1) != m.end()) {
					mx = max(mx, i - m[sum - 1]);
				}
			}
			if (m.find(sum) == m.end()) {
				m[sum] = i;
			}
		}
		return mx;
	}
};