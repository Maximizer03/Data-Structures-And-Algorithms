class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
        int p1 = 1, p2 = 1;
        for (int i = 3; i <= n; i++) {
            int c = p1 + p2;
            p1 = p2;
            p2 = c;
        }
        return p2;
    }
};