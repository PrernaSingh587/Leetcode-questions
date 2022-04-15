class Solution {
public:
    map<pair<int,int>,int>mp;
    int solve(vector<int>& p,int i,int j) {
        if(i>j) return 0;
        if(mp.count({i,j})) return mp[{i,j}];
        return mp[{i,j}]=max(p[i]-solve(p,i+1,j),p[j]-solve(p,i,j-1));
    }
    bool stoneGame(vector<int>& p) {
        int i=0,j=p.size()-1;
        int h=solve(p,i,j);
        return h>0;
    }
};