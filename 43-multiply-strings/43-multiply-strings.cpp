class Solution {
public:
	string product(string &s, char c, int d) {
		int n = s.size();
		string t = s;
		reverse(begin(t), end(t));
		string ans = "";
		int num = c - '0', carry = 0;
		for (int i = 0; i < n; i++) {
			int d = t[i] - '0';
			int tot = d * num + carry;
			int last = tot % 10;
			string l = to_string(last);
			ans += l;
			carry = tot / 10;
		}
		if (carry) {
			string l = to_string(carry);
			ans += l;
		}
		reverse(begin(ans), end(ans));
		for (int i = 0; i < d; i++) {
			ans += '0';
		}
		return ans;
	}
	string summation(string t1, string t2) {
		string s1 = t1, s2 = t2;
		if (s1.size() <= s2.size()) {
			swap(s1, s2);
		}
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		int n1 = s1.size(), n2 = s2.size();
		int i = 0, j = 0, carry = 0;
		string ans = "";
		while (i < n1 && j < n2) {
			int n1 = s1[i] - '0';
			int n2 = s2[j] - '0';
			int sum = n1 + n2 + carry;
			int d = sum % 10;
			carry = sum / 10;
			ans += to_string(d);
			i++; j++;

		}
		while (i < n1) {
			int sum = (s1[i] - '0') + carry;
			int d = sum % 10;
			ans += to_string(d);
			i++;
			carry = sum / 10;
		}
		if (carry) {
			string l = to_string(carry);
			ans += l;
		}
		reverse(begin(ans), end(ans));
		return ans;
	}
	string multiply(string num1, string num2) {
        string z="0";
        if(num1==z || num2==z){
            return z;
        }
		string ans = "";
		int n = num2.size();
		for (int i = n - 1; i >= 0; i--) {
			string p = product(num1, num2[i], n - i - 1);
			ans = summation(p, ans);
		}
		return ans;
	}
};