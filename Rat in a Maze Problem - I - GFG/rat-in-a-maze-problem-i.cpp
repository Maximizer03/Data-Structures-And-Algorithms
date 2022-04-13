// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution {
public:
	void calc(int i, int j, vector<string>&ans, string temp, vector<vector<int>>&m, int n) {
	if(i<0 || i>=n || j<0 || j>=n || m[i][j]==0 ){
	    return;
	}
	if (i == n - 1 && j == n - 1) {
		ans.push_back(temp);
		return;
	}
	vector<int>dx = {1, -1, 0, 0};
	vector<int>dy = {0, 0, 1, -1};
	for (int k = 0; k < 4; k++) {
		int xx = dx[k] + i;
		int yy = dy[k] + j;
		if (xx >= 0 && xx < n && yy >= 0 && yy < n && m[xx][yy] == 1) {
			if (k == 0) {
				temp += 'D';
				m[i][j] = 0;
				calc(xx, yy, ans, temp, m, n);
				temp.pop_back();
				m[i][j] = 1;
			}
			else if (k == 1) {
				temp += 'U';
				m[i][j] = 0;
				calc(xx, yy, ans, temp, m, n);
				temp.pop_back();
				m[i][j] = 1;
			}
			else if (k == 2) {
				temp += 'R';
				m[i][j] = 0;
				calc(xx, yy, ans, temp, m, n);
				temp.pop_back();
				m[i][j] = 1;
			}
			else {
				temp += 'L';
				m[i][j] = 0;
				calc(xx, yy, ans, temp, m, n);
				temp.pop_back();
				m[i][j] = 1;
			}
		}
	}
}
vector<string> findPath(vector<vector<int>> &m, int n) {
	vector<string>ans;
	string temp = "";
	calc(0, 0, ans, temp, m, n);
	return ans;
}

};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends