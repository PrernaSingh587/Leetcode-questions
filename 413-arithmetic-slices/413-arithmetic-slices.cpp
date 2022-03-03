class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        int n = v.size();
        if(n<3) return 0;
        int len=v[1]-v[0], cnt=2, ans = 0;
        for(int i = 2; i<n; i++) {
            if(len==v[i]-v[i-1]) {
                cnt++;
                ans +=cnt-2;
            }
            else {
                len=v[i]-v[i-1];
                cnt=2;
            }
        }
        return ans;
    }
};