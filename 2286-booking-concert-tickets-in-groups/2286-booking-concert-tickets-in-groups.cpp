class BookMyShow {
public:
	vector<int>tree, arr;
	int maximo;
	vector<long long>tree2;
	int n, m;
	void build(int v, int tl, int tr) {
		if (tl == tr) {
			tree[v] = arr[tl];
		}
		else {
			int tm = (tl + tr) / 2;
			build(2 * v, tl, tm);
			build(2 * v + 1, tm + 1, tr);
			tree[v] = max(tree[2 * v] , tree[2 * v + 1]);
		}
	}
	void build2(int v, int tl, int tr) {
		if (tl == tr) {
			tree2[v] = arr[tl];
		}
		else {
			int tm = (tl + tr) / 2;
			build2(2 * v, tl, tm);
			build2(2 * v + 1, tm + 1, tr);
			tree2[v] = tree2[2 * v] + tree2[2 * v + 1];
		}
	}
	int minQuery(int l, int r, int v, int tl, int tr) {
		if (l > r) {
			return -1e8;
		}
		if (l == tl && r == tr) {
			return tree[v];
		}
		int tm = (tl + tr) / 2;
		int left = minQuery(l, min(r, tm), 2 * v, tl, tm);
		int right = minQuery(max(l, tm + 1), r, 2 * v + 1, tm + 1, tr);
		return max(left , right);
	}
	long long minQuery2(int l, int r, int v, int tl, int tr) {
		if (l > r) {
			return 0;
		}
		if (l == tl && r == tr) {
			return tree2[v];
		}
		int tm = (tl + tr) / 2;
		long long left = minQuery2(l, min(r, tm), 2 * v, tl, tm);
		long long right = minQuery2(max(l, tm + 1), r, 2 * v + 1, tm + 1, tr);
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
			tree[v] = max(tree[2 * v] , tree[2 * v + 1]);
		}
	}
	void update2(int pos, int new_val, int v , int tl , int tr) {
		if (tl == tr) {
			tree2[v] = new_val;
			return;
		}
		else {
			int tm = (tl + tr) / 2;
			if (pos <= tm) {
				update2(pos, new_val, 2 * v, tl, tm);
			}
			else {
				update2(pos, new_val, 2 * v + 1, tm + 1, tr);
			}
			tree2[v] = tree2[2 * v] + tree2[2 * v + 1];
		}
	}
	BookMyShow(int row, int col) {
		n = row, m = col;
		arr.resize(n);
		for (int i = 0; i < n; i++) {
			arr[i] = m;
		}
		tree.resize(4 * n);
		tree2.resize(4 * n);
		build(1, 0, n - 1);
		build2(1, 0, n - 1);
		maximo = 0;
	}

	vector<int> gather(int k, int C) {
		vector<int>ans;
		if (k > m) {
			return ans;
		}
		else {
			int maxi = minQuery(0, C, 1, 0, n - 1);
			if (maxi < k) {
				return ans;
			}
			int l = 0, r = C;
			int ind = -1;
			while (l <= r) {
				int mid = (l + r) / 2;
				int q = minQuery(0, mid, 1, 0, n - 1);
				if (q < k) {
					l = mid + 1;
				}
				else {
					ind = mid;
					r = mid - 1;
				}
			}
			int colo = m - arr[ind];
			int new_val = arr[ind] - k;
			arr[ind] -= k;
			update(ind, new_val, 1, 0, n - 1);
			update2(ind, new_val, 1, 0, n - 1);
			ans = {ind, colo};
		}
		return ans;
	}

	bool scatter(int k, int C) {
		int l = 0, r = C;
		int ind = -1;
		long long tt = minQuery2(maximo, C, 1, 0, n - 1);
		if (tt < (long long)k) {
			return false;
		}
		while (l <= r) {
			int mid = (l + r) / 2;
			long long sum = minQuery2(maximo, mid, 1, 0, n - 1);
			if (sum >= (long long)k) {
				ind = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		for (int i = maximo; i <= ind; i++) {
			if (arr[i] >= k) {
				int left = arr[i] - k;
				arr[i] -= k;
				k = 0;
				update(i, left, 1, 0, n - 1);
				update2(i, left, 1, 0, n - 1);
			}
			else {
				k -= arr[i];
				arr[i] = 0;
				update(i, 0, 1, 0, n - 1);
				update2(i, 0, 1, 0, n - 1);
			}
		}
		maximo = max(maximo, ind);
		return true;
	}
};