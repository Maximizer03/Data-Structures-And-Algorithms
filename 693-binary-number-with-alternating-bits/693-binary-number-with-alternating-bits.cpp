class Solution {
public:
	bool hasAlternatingBits(int n) {
		vector<int>v;
		int flg = 0;
		int p = -1;
		for (int i = 31; i >= 0; i--) {
			int bit = (1 << i)&n;
			if (bit > 0) {
				flg = 1;
				if (p == 1) {
					return false;
				}
				p = 1;
			}
			else {
				if (flg) {
					if (p == 0) {
						return false;
					}
					p = 0;
				}
			}
		}
		return true;
	}
};