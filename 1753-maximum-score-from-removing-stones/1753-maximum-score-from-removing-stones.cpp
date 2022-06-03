class Solution {
public:
	int maximumScore(int a, int b, int c) {
		vector<int>arr;
        arr.push_back(a);arr.push_back(b);
        arr.push_back(c);
        sort(begin(arr),end(arr));
        if(arr[2]> arr[1]+arr[0]){
            return arr[1]+arr[0];
        }
        return (arr[0]+arr[1]+arr[2])/2;
	}
};