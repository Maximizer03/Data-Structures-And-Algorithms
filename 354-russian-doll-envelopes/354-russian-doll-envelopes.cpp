class Solution {
public:
	int LIS(vector<int>&v) {
		int n = v.size();
		vector<int>ord;
		for (int i = 0; i < n; i++) {
			int l = lower_bound(begin(ord), end(ord), v[i]) - ord.begin();
			if (l == ord.size()) {
				ord.push_back(v[i]);
			}
			else {
				ord[l] = v[i];
			}
		}
		return ord.size();
	}
	int maxEnvelopes(vector<vector<int>>& E) {
        // sort in increasing order of width and descreasing order of height and find LIS of height
		sort(begin(E), end(E), [&](vector<int>&A, vector<int>&B) {
			if (A[0] < B[0]) {
				return true;
			}
			else if (A[0] == B[0]) {
				return A[1] >= B[1];
			}
			else {
				return false;
			}
		}   );
		int n = E.size();
		vector<int>v;
		for (int i = 0; i < n; i++) {
			v.push_back(E[i][1]);
		}
		return LIS(v);
	}
};