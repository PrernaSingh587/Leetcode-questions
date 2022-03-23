class Solution {
public:
    int solve(vector<int>& ts, vector<int>& bt,int x) {
        int n=ts.size();
        int a=0,b=0;
        for(int i=0;i<n;i++) {
            if(ts[i]!=x && bt[i]!=x) return -1;
            else if(ts[i]!=x) a++;
            else if(bt[i]!=x) b++;
        }
        return min(a,b);
    }
    int minDominoRotations(vector<int>& ts, vector<int>& bt) {
        
        int rot=solve(ts,bt,ts[0]);
        if(rot!=-1) return rot;
        return solve(ts,bt,bt[0]);
    }
};