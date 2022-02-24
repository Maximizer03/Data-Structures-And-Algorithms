class Solution {
public:
	long long minimumDifference(vector<int>& nums) {
		int m = nums.size();
		int n = m / 3;
		long long sum = 0;
		priority_queue<int>q;
		for (int i = 0; i < n; i++) {
			q.push(nums[i]);
			sum += nums[i];
		}
		vector<long long>mini(m, 1e17);
		mini[n - 1] = sum;
		long long mn = mini[n - 1];
		for (int i = n; i < m - n; i++) {
			q.push(nums[i]);
			int v = q.top();
			q.pop();
			sum += (nums[i] - v);
			mn = min(mn, sum);
			mini[i] = mn;
		}
		sum = 0;
		priority_queue<int, vector<int>, greater<int>>qm;
		for (int i = m - 1; i >= m - n; i--) {
			qm.push(nums[i]);
			sum += nums[i];
		}
		vector<long long>maxi(m, -1e17);
		maxi[m - n] = sum;
		long long mx = sum;
		for (int i = m - n - 1; i >= n; i--) {
			qm.push(nums[i]);
			int v = qm.top();
			qm.pop();
			sum += (nums[i] - v);
			mx = max(mx, sum);
			maxi[i] = mx;
		}
		for (int i = 1; i < m; i++) {
			mini[i] = min(mini[i], mini[i - 1]);
		}
		for (int i = m - 2; i >= 0; i--) {
			maxi[i] = max(maxi[i], maxi[i + 1]);
		}
		long long fnl = 2e18;
		for (int i = n - 1; i < m - n; i++) {
			long long x = mini[i];
			long long y = maxi[i + 1];
			fnl = min(fnl, x - y);
		}
		return fnl;
	}
};