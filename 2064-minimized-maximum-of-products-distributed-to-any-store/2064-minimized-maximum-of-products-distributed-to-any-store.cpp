class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int m=q.size(),ans=-1;
        int i=1,j=100000;
        while(i<=j) {
            int m=(i+j)/2;
            int c=0;
            for(int x : q) {
                c+=x/m;
                if(x%m) c++;
            }
            if(c>n) {
                i=m+1;
            } else if(c<n) {ans=m; j=m-1;}
            else {
                ans=m;
                j=m-1;
            }
        }
        return ans;
    }
};