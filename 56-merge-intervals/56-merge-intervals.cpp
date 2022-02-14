class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        int n=in.size();
        sort(in.begin(),in.end());
        int x=in[0][0],y=in[0][1];
        vector<vector<int>>v;
        for(int i=1;i<n;i++) {
            if(y<in[i][0]) {
                v.push_back({x,y});
                x=in[i][0],y=in[i][1];
            } else {
                y=max(y,in[i][1]);
            }
        }
        v.push_back({x,y});
        return v;
    }
};