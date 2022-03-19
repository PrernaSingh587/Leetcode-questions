class Solution {
public:
    int findCenter(vector<vector<int>>& ed) {
        int n=ed.size();
        int ind[n+2]; memset(ind,0,sizeof(ind));
        for(vector<int>v : ed) {
            ind[v[0]]++; ind[v[1]]++;
        }
        for(int i=1;i<=n+1;i++) {
            if(ind[i]!=1) return i;
        }
        return 0;
    }
};