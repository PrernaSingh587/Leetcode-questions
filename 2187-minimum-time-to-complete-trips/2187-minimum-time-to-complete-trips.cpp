class Solution {
public:
    long long minimumTime(vector<int>& time, int tot) {
       sort(time.begin(),time.end());
      long long int i=1,j=time[time.size()-1]*(long)tot,n=time.size(),ans=0;
        while(i<=j) {
            long long int m=(i+j)/2;
           long long  int c=0;
            for(int k : time) {
                c+=(m/k);
            }
           // cout<<i<<" "<<j<<" "<<m<<" "<<c<<endl;
            if(c<tot) {
                i=m+1;
            } else {
                ans=m;
                j=m-1;
            }
        }
        return ans;
    }
};