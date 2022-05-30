class Solution {
public:
	long long calc(long long n, long long x) {
		long long ans = 0;
		for (long long i = 0; i <= n; i++) {
			ans += i * (i + 1);
		}
		long long cnt = n;
		for (long long i = n + 1; i <= 2 * n; i++) {
			ans += i * (cnt);
			cnt--;
		}
		ans *= 4;
		long long y = (n * (n + 1)) * 2;
		ans -= y;
		return (ans >= x);
	}
	long long minimumPerimeter(long long x) {
		int l = 1, r = 200000;
		long long ans = 1e9;
		while (l <= r) {
			long long mid = (l + r) / 2;
			if (calc(mid, x)) {
				ans = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		return ans * 8;
	}
};