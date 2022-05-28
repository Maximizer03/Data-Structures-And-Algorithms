class Solution {
public:
	int numPairsDivisibleBy60(vector<int>& time) {
		vector<int>cnt(61, 0);
		int ans = 0;
		for (int i = 0; i < time.size(); i++) {
			int x = time[i] % 60;
			ans += cnt[(60 - x) % 60];
			cnt[x]++;
		}
		return ans;
	}
};