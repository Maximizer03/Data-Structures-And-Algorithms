struct FenwickTree {
	// one based indexing
	vector<int> bit;
	int n;
	void init(int n) {
		this->n = n;
		bit.assign(n + 1, 0);
	}
	int pref(int i) {
		int sum = 0;
		while (i > 0) {
			sum += bit[i];
			i = i - (i & (-i));
		}
		return sum;
	}
	int rsum(int l, int r) {
		return pref(r) - pref(l - 1);
	}
	// assigns x at pos i
	void update(int i, int x) {
		x -= rsum(i, i);
		while (i <= n) {
			bit[i] += x;
			i = i + (i & (-i));
		}
	}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        // coordinate compression
        set<int>s;
        for(auto &x:nums){
            s.insert(x);
        }
        map<int,int>m;
        int cnt=1;
        for(auto &x:s){
            m[x]=cnt;
            cnt++;
        }
        //
        FenwickTree f;
        f.init(n+1);
        
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            int x= m[nums[i]];
            int val= f.rsum(1,x-1);
            ans.push_back(val);
            int org= f.rsum(x,x);
            f.update(x,org+1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};