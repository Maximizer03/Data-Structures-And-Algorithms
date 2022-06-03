class Solution {
public:
	int maxIceCream(vector<int>& c, int x) {
		int ans = 0;
		long long sum = 0;
		sort(begin(c), end(c));
		for (int i = 0; i < c.size(); i++) {
			sum += c[i];
			if (sum > (long long)(x)) {
				return ans;
			}
			ans++;
		}
		return ans;
	}
};