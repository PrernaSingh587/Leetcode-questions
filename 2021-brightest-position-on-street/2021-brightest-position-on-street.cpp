class Solution {
public:
    int brightestPosition(vector<vector<int>>& l) {
        vector<vector<int>>v;
        for(vector<int>v1 : l ) {
            v.push_back({v1[0]-v1[1],0});
            v.push_back({v1[0]+v1[1],1});
        }
        sort(v.begin(),v.end());
        int maxi=0,ans=-1,c=0;
        for(int i=0;i<v.size();i++) {
            if(v[i][1]==0) c++;
            else c--;
            if(maxi<c) {
                maxi=c;
                ans=v[i][0];
            }
        }
        return ans;
    }
};