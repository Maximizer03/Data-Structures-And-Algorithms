class Solution {
private:
	int gcd(int a, int b) {
		if(b==0){
            return a;
        }
        return gcd(b,a%b);
	}
public:
	int maxPoints(vector<vector<int>>& points) {
		int n = points.size(), ans = 1;
		for (int i = 0; i < n; i++) {
			unordered_map<string, int> cnt;
			int dup = 1;
			for (int j = i + 1; j < n; j++) {
				int dx = (points[j][0] - points[i][0]);
                int dy = points[j][1] - points[i][1];
                int g = gcd(dx, dy);
				cnt[to_string(dx / g) + '_' + to_string(dy / g)]++;
			}
			for (auto p : cnt) {
				ans = max(ans, p.second + 1);
			}
		}
		return ans;
	}
};
