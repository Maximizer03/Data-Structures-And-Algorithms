class Solution {
public:
	vector<pair<int, int>> get(vector<int>&a) {
		int n = a.size();
		vector<pair<int, int>>res; // (sum,size)
		for (int i = 1; i < (1 << n); i++) {
			int cnt = 0, sum = 0;
			for (int j = 0; j < n; j++) {
				int b = (1 << j)&i;
				if (b > 0) {
					cnt++; sum += a[j];
				}
			}
			res.push_back({sum, cnt});
		}
		sort(begin(res), end(res));
		return res;
	}
	int calc(int sum, int len, vector<pair<int, int>>&p1, vector<pair<int, int>>&p2) {
		for (int i = 0; i < p1.size(); i++) {
			int s = p1[i].first;
			int x = p1[i].second;
			int req_sum = sum - s;
			int req_size = len - x;
			if (req_sum >= 0 && req_size > 0) {
				pair<int, int>p = {req_sum, req_size};
				if (binary_search(begin(p2), end(p2), p)) {
					return 1;
				}
			}
		}
		return 0;
	}
	bool splitArraySameAverage(vector<int>& a) {
		int n = a.size();
		vector<pair<int, int>>p1, p2;
		vector<int>v1, v2;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			if (i % 2) {
				v1.push_back(a[i]);
			}
			else {
				v2.push_back(a[i]);
			}
		}
		p1 = get(v1);
		p2 = get(v2);
		for (int len = 1; len <= n - 1; len++) {
			int x = sum * len;
			if (x % n == 0) {
				int req = x / n;
				if (calc(req, len, p1, p2)) {
					return true;
				}
			}
		}
		return false;
	}
};