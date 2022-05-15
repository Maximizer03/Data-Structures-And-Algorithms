class Solution {
public:
	int subarraysDivByK(vector<int>& nums, int k) {
		vector<int>vec(k);
        vec[0]++;
		long long cnt = 0, sum = 0,n = nums.size();
		for (int i = 0; i < n; i++) {
			sum += nums[i];
			int num = (sum % k + k) % k;
			cnt += vec[num];
			vec[num]++;
		}
		return cnt;
	}
};