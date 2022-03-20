class Solution {
public:
  map<pair<int,int>,int>mp;
    int solve(string w1, string w2, int i, int j) {
        if(i==w1.size() && j==w2.size()) return 0;
        if(i==w1.size() || j==w2.size()) return j==w2.size()?w1.size()-i:w2.size()-j;
        if(mp.count({i,j})) return mp[{i,j}];
        if(w1[i]==w2[j]) return mp[{i,j}]=solve(w1,w2,i+1,j+1);

            return mp[{i,j}]=1+min(solve(w1,w2,i,j+1),
                                   min(solve(w1,w2,i+1,j),solve(w1,w2,i+1,j+1)));
       
    }
    int minDistance(string w1, string w2) {
        return solve(w1,w2,0,0);
    }
};