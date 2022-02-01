class Solution {
public:
	bool isRectangleCover(vector<vector<int>>& rectangles) {
		long long xmax = INT_MIN, xmin = INT_MAX, ymax = INT_MIN, ymin = INT_MAX;
        long long area=0,sum=0;
        map<pair<int,int>,int>m;
        int cnt=0;
        set<pair<int,int>>s;
		for (auto &rec : rectangles) {
			long long x = rec[0], y = rec[1], a = rec[2], b = rec[3];
			xmax = max({xmax, x, a});
			xmin = min({xmin, x, a});
			ymax = max({ymax, y, b});
			ymin = min({ymin, y, b});
            s.insert({x,y});
            s.insert({x,b});
            s.insert({a,b});
            s.insert({a,y});
            m[{x,y}]++;m[{x,b}]++;m[{a,b}]++;m[{a,y}]++;
            sum+= (a-x)*(b-y);
		}
        cnt=s.size();
        area= (xmax-xmin)*(ymax-ymin);
        if(m[{xmin,ymin}]==1 && m[{xmin,ymax}]==1 && m[{xmax,ymin}]==1 && m[{xmax,ymax}]==1 ){
            if(area==sum){
                int rnt=0;
                for(auto &x:m){
                    if(x.second%2==0){
                        rnt++;
                    }
                }
                if(rnt==cnt-4){
                    return 1;
                }
            }
        }
        return 0;
	}
};