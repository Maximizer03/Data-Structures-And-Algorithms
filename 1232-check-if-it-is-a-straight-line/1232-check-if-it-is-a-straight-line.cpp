class Solution {
public:
	bool checkStraightLine(vector<vector<int>>& c) {
        sort(begin(c),end(c));
		vector<pair<int, int>>v;
		int n = c.size();
		for (int i = 1; i < n; i++) {
			int xc = c[i][0] - c[i - 1][0];
			int yc = c[i][1] - c[i - 1][1];
            int g= __gcd(xc,yc);
            xc/=g;
            yc/=g;
			if (v.size() == 0) {
				v.push_back({xc, yc});
			}
			else {
				pair<int, int>p = {xc, yc};
				if (v.back() != p) {
					return false;
				}
			}
		}
		return true;
	}
};