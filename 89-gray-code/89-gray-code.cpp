class Solution {
public:
    int calc(string s) {
	int n = s.size();
	int p = 1;
	int sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '1') {
			sum += p;
		}
		p *= 2;
	}
	return sum;
}

void solve(int n, vector<string>&gc) {
	if (n == 1) {
		gc.push_back("0");
		gc.push_back("1");
		return;
	}
	vector<string>ans;
	solve(n - 1, gc);
	// debug(gc);
	for (int i = 0; i < gc.size(); i++) {
		string temp = '0' + gc[i];
		ans.push_back(temp);
	}
	for (int i = gc.size() - 1; i >= 0; i--) {
		string temp = '1' + gc[i];
		ans.push_back(temp);
	}
	gc = ans;
}
    vector<int> grayCode(int n) {
        vector<int>ans;
        vector<string>grayCode;
        solve(n,grayCode);
        for(int i=0;i<grayCode.size();i++){
            ans.push_back(calc(grayCode[i]));
        }
        return ans;
    }
};