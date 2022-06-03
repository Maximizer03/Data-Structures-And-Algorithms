class Solution {
public:
	int maximumScore(int a, int b, int c) {
		priority_queue<int>q;
		q.push(a); q.push(b); q.push(c);
		int ans = 0;
		while (q.size() >= 2) {
			int x = q.top();
			q.pop();
			int y = q.top();
			q.pop();
			ans++;
			x--; y--;
			if (x > 0) {
				q.push(x);
			}
			if (y > 0) {
				q.push(y);
			}
		}
		return ans;
	}
};