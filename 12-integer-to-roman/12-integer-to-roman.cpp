class Solution {
public:
	string intToRoman(int num) {
		map<int, string>m;
		m[4] = "IV", m[9] = "IX", m[40] = "XL", m[90] = "XC", m[400] = "CD", m[900] = "CM";
		m[1] = 'I', m[5] = 'V', m[10] = 'X', m[50] = 'L', m[100] = 'C', m[500] = 'D', m[1000] = 'M';
		vector<int>v = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
		string ans = "";
		while (num != 0) {
			int d = 0;
			for (int i = 0; i <= 3; i++) {
				if (num < pow(10, i)) {
					break;
				}
				d = pow(10, i);
			}
			int x = (num / d) * (d);
			int l = upper_bound(begin(v), end(v), x) - v.begin() - 1;
			ans += m[v[l]];
			num -= v[l];
		}
		return ans;
	}
};