class Solution {
public:
	vector<long long> calc(vector<long long>&v) {
		int n = v.size();
		vector<long long>ans;
        set<long long >s;
		for (int mask = 0; mask < (1 << n); mask++) {
			long long sum = 0;
			for (int j = 0; j < n; j++) {
				int bit = (1 << j)&mask;
				if (bit > 0) {
					sum += v[j];
				}
			}
			s.insert(sum);
		}
		for(auto &x:s){
            ans.push_back(x);
        }
		return ans;
	}
	int minAbsDifference(vector<int>& nums, int goal) {
		vector<long long> arr[2];
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			arr[i % 2].push_back(nums[i]);
		}
		for (int i = 0; i < 2; i++) {
			arr[i] = calc(arr[i]);
		}
		long long  ans = 1e18;
		for (int i = 0; i < arr[0].size(); i++) {
			long long x = arr[0][i];
			long long tar = goal - x;
			int l = lower_bound(begin(arr[1]), end(arr[1]), tar) - arr[1].begin();
			int m = arr[1].size();
			l++;
			if (l >= 0 && l < m) {
				long long sum = x + arr[1][l];
				ans = min(ans, abs(goal - sum));
			}
			l--;
			if (l >= 0 && l < m) {
				long long sum = x + arr[1][l];
				ans = min(ans, abs(goal - sum));
			}
			l--;
			if (l >= 0 && l < m) {
				long long sum = x + arr[1][l];
				ans = min(ans, abs(goal - sum));
			}
		}
		return ans;
	}
};