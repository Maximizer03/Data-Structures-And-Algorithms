class Solution {
public:
	int getWinner(vector<int>& arr, int k) {
		int mx = 0, n = arr.size();
		for (int i = 0; i < n; i++) {
			mx = max(mx, arr[i]);
		}
		deque<int>d;
		for (int i = 0; i < n; i++) {
			d.push_back(arr[i]);
		}
		map<int, int>m;
		while (d.front() != mx) {
			int x1 = d.front();
			d.pop_front();
			int x2 = d.front();
			d.pop_front();
			if (x1 > x2) {
				d.push_back(x2);
				d.push_front(x1);
				m[x1]++;
				if (m[x1] == k) {
					return x1;
				}
			}
			else {
				d.push_back(x1);
				d.push_front(x2);
				m[x2]++;
				if (m[x2] == k) {
					return x2;
				}
			}
		}
		return d.front();
	}
};