class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n=c.size();
        int h=n-k,top=0;
        int mini=INT_MAX;
        int sum=0,tot=0;
        for(int i=0;i<h;i++) {
            sum+=c[i]; tot+=c[i];
        }
        mini=min(mini,sum);
        for(int i=h;i<n;i++) {
            sum-=c[top++]; tot+=c[i];
            sum+=c[i];
            mini=min(mini,sum);
        }
        return tot-mini;
    }
};