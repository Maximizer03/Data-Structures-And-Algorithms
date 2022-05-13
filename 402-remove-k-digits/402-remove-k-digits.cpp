class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> answer;
		int n = num.size();
        k=n-k;
        if(k==0){
            return "0";
        }
		for (int i = 0; i < n; ++i) {
			if (answer.empty()) {
				answer.push(num[i]);
			}
			else {
				while ((!answer.empty()) && (num[i] < answer.top())  && (answer.size() - 1 + n - i >= k)) {
					answer.pop();
				}
				if (answer.empty() || answer.size() < k) {
					answer.push(num[i]);
				}
			}
		}
		vector<char>ret;
		while (!answer.empty()) {
			ret.push_back(answer.top());
			answer.pop();
		}
		string ans="";
        for(int i=0;i<ret.size();i++){
            ans+= ret[i];
        }
        while(ans.back()=='0'){
            ans.pop_back();
        }
        reverse(begin(ans),end(ans));
        if(!ans.size()){
            return "0";
        }
        return ans;
        
    }
};