class Solution {
public:

    int stoneGameVI(vector<int>& av, vector<int>& bv) {
        priority_queue<pair<int,int>>q;
        for(int i=0;i<av.size();i++) {
            q.push({av[i]+bv[i],i});
        }
        int f=1,ta=0,tb=0;
        while(!q.empty()) {
            auto k=q.top(); q.pop();
            int x=k.first,y=k.second;
            if(f) ta+=av[y];
            else tb+=bv[y];
            f=!f;
        }
        if(ta==tb) return 0;
        return ta<tb?-1:1;
    }
};