class Solution {
public:
    void addWords(queue<string>&q, unordered_set<string>&s, string &w){
        for(int i=0;i<w.size();i++){
            char c=w[i];
            for(char j='a';j<='z';j++){
                w[i]=j;
                if(w[i]!=c){
                    if(s.count(w)){
                        q.push(w);
                        s.erase(w);
                    }
                }
            }
            w[i]=c;
        }
    }
    int ladderLength(string B, string E, vector<string>& list) {
        unordered_set<string>s(begin(list),end(list));
        if(s.count(E)==0){
            return 0;
        }
        queue<string>q;
        q.push(B);
        int ans=1;
        while(!q.empty()){
            int cnt=q.size();
            while(cnt--){
                string w=q.front();
                q.pop();
                if(w==E){
                    return ans;
                }
                addWords(q,s,w);
            }
            ans++;
        }
        return 0;
    }
};