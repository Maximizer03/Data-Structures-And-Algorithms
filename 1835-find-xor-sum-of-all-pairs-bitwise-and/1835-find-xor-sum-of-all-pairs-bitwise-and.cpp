class Solution {
public:
	int getXORSum(vector<int>& arr1, vector<int>& arr2) {
		int ans = 0;
		for (int i = 31; i >= 0; i--) {
			int c = 0; long long t = 0;
			for (int j = 0; j < arr2.size(); j++) {
				int b = (1 << i)&arr2[j];
				if (b) {
					c++;
				}
			}
			for (int j = 0; j < arr1.size(); j++) {
				int b = (1 << i)&arr1[j];
				if (b) {
					t += c;
				}
			}
			if (t % 2) {
				ans = ans | (1 << i);
			}
		}
		return ans;
	}
};