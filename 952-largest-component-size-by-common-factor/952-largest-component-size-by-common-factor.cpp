class Solution {
private:
	vector<int>p, r,spf;
public:
	void init(int n) {
		p.resize(n + 1);
		r.resize(n + 1);
		for (int v = 0; v <= n; v++) {
			p[v] = v;
			r[v] = 0;
		}
	}
    void sieve(int n){
        spf.resize(n);
        // spf[i]=smallest prime factor of i
        for(int i=2;i<n;i++){
            spf[i]=i;
        }
        for(int i=2;i*i<n;i++){
            if(spf[i]==i){
                for(int j=i*i;j<n;j+=i){
                    if(spf[j]>i){
                        spf[j]=i;
                    }
                }
            }
        }
    }
    vector<int>fact(int n){
        vector<int>v;
        while(n>1){
            v.push_back(spf[n]);
            n/=spf[n];
        }
        return v;
    }
	int find_set(int v) {
		if (v == p[v]) {
			return v;
		}
		return p[v] = find_set(p[v]);
	}
	void union_sets(int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			if (r[a] < r[b]) {
				swap(a, b);
			}
			p[b] = a;
			if (r[a] == r[b]) {
				r[a]++;
			}
		}
	}
	int largestComponentSize(vector<int>& nums) {
		int mx = *max_element(begin(nums), end(nums));
		init(mx + 1);
        sieve(mx+1);
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			int x = nums[i];
			vector<int>v= fact(x);
            for(auto &y:v){
                union_sets(y,x);
            }
		}
		map<int, int>m;
		for (int i = 0; i < n; i++) {
			int s = find_set(nums[i]);
			m[s]++;
		}
		int ans = 0;
		for (auto &x : m) {
			ans = max(ans, x.second);
		}
		return ans;
	}
};