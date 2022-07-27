class Solution {
public:
    #define ll long long
    int maximumCandies(vector<int>& can, long long k) {
        sort(can.begin(),can.end());
        ll ans=0,n=can.size(),i=1,j=can[n-1];
        while(i<=j) {
            int m=(i+j)/2;
          ll  int c=0;
            for(int d : can) {
                c+=d/m;
            }
            if(c>=k) {
                ans=m;
                i=m+1;
            } else j=m-1;
            
        }
        return ans;
    }
};