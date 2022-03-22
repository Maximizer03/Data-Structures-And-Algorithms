class Solution {
public:
    int minAddToMakeValid(string t) {
        int b=0,cnt=0;
        for(int i=0;i<t.size();i++){
            if(t[i]=='('){
                b++;
            }
            else{
                b--;
            }
            if(b<0){
                cnt++;
                b=0;
            }
        }
        cnt+=b;
        return cnt;
    }
};