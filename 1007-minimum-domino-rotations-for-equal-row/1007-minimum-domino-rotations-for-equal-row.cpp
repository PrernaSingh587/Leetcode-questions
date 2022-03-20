class Solution {
public:
    int minDominoRotations(vector<int>& ts, vector<int>& bt) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<ts.size();i++) {
            if(mp.count(ts[i])==0) mp[ts[i]].resize(3,0);
            if(mp.count(bt[i])==0)  mp[bt[i]].resize(3,0);
            if(ts[i]==bt[i]) {
                mp[ts[i]][0]++;
               
            } else {
                int x=ts[i],y=bt[i];
                mp[x][1]++;
                mp[y][2]++;
            }
        }
        int mini=INT_MAX;
        for(auto i=mp.begin();i!=mp.end();i++) {
            vector<int>p=i->second;
            if(p[0]+p[1]+p[2]==ts.size()) {
                
                mini=min(mini,min(p[1],p[2]));
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};