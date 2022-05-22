class Solution {
public:
	int getXORSum(vector<int>& arr1, vector<int>& arr2) {
		vector<int>cnt(32, 0);
		vector<long long>rem(32, 0);
		for (int i = 31; i >= 0; i--) {
			for (int j = 0; j < arr2.size(); j++) {
				int b = (1 << i)&arr2[j];
				if (b) {
					cnt[i]++;
				}
			}
		}
		for (int i = 31; i >= 0; i--) {
			for (int j = 0; j < arr1.size(); j++) {
				int b = (1 << i)&arr1[j];
				if (b) {
					rem[i] += cnt[i];
				}
			}
		}
		int ans = 0;
		for (int i = 31; i >= 0; i--) {
			if (rem[i] % 2) {
				ans = ans | (1 << i);
			}
		}
		return ans;
	}
};