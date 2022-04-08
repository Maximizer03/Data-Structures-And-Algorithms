class Solution {
public:
	vector<int> asteroidCollision(vector<int>& A) {
		vector<int>ord;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] < 0) {
				while (ord.size() > 0 && ord.back() > 0 && abs(ord.back()) < abs(A[i])) {
					ord.pop_back();
				}
				if (ord.size()) {
					if (ord.back() < 0) {
						ord.push_back(A[i]);
					}
					else if (ord.back() == abs(A[i])) {
						ord.pop_back();
					}
				}
				else {
					ord.push_back(A[i]);
				}
			}
			else {
				ord.push_back(A[i]);
			}
		}
		return ord;
	}
};