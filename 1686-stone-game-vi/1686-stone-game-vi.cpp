class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<vector<int>>ind(201);
        for(int i=0;i<n;i++) {
            ind[a[i]+b[i]].push_back(i);
        }
        
        int ta=0,tb=0,turn=0;
        for(int i=200;i>=1;i--) {
           
            for(int k=0;k<ind[i].size();k++) {
                 cout<<i<<" ";
                if(turn==0) {
                    ta+=a[ind[i][k]];
                } else tb+=b[ind[i][k]];
                turn^=1;
                
            }
        }
        cout<<ta<<" "<<tb;
        if(ta==tb) return 0;
        if(ta>tb) return 1;
        return -1;
    }
};