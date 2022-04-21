class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& val) {
        int n=val.size();
        int prev=val[0],ans=prev;
        for(int i=1;i<n;i++) {
            ans=max(ans,val[i]-i+prev);
            prev=max(prev,val[i]+i);
        }
        return ans;
    }
};