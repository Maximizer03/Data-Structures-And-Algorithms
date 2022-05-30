class Solution {
public:
	vector<long long>arr, tree;
	void build(int v, int tl, int tr) {
		if (tl == tr) {
			tree[v] = arr[tl];
		}
		else {
			int tm = (tl + tr) / 2;
			build(2 * v, tl, tm);
			build(2 * v + 1, tm + 1, tr);
			tree[v] = tree[2 * v] + tree[2 * v + 1];
		}
	}
	long long query(int l, int r, int v, int tl, int tr) {
		if (l > r) {
			return 0LL;
		}
		if (l == tl && r == tr) {
			return tree[v];
		}
		int tm = (tl + tr) / 2;
		long long left = query(l, min(r, tm), 2 * v, tl, tm);
		long long right = query(max(l, tm + 1), r, 2 * v + 1, tm + 1, tr);
		return left + right;
	}
	void update(int pos, int new_val, int v , int tl , int tr) {
		if (tl == tr) {
			tree[v] = new_val;
			return;
		}
		else {
			int tm = (tl + tr) / 2;
			if (pos <= tm) {
				update(pos, new_val, 2 * v, tl, tm);
			}
			else {
				update(pos, new_val, 2 * v + 1, tm + 1, tr);
			}
			tree[v] = tree[2 * v] + tree[2 * v + 1];
		}
	}
	int createSortedArray(vector<int>& v) {
		int n = *max_element(begin(v), end(v)) + 1;
		arr.resize(n);
		tree.resize(4 * n);
		build(1, 0, n-1);
		long long ans = 0, mod = 1e9 + 7;
		for (int i = 0; i < v.size(); i++) {
			long long cnt_left = query(0, v[i] - 1, 1, 0, n);
			long long cnt_right =  query(v[i] + 1, n, 1, 0, n);
			long long mn = min(cnt_left, cnt_right);
			arr[v[i]]++;
			update(v[i], arr[v[i]], 1, 0, n);
			ans = (ans % mod + mn % mod) % mod;
		}
		return ans;
	}
};