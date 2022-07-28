class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int n=p.size(),ans=0;
        int maxi=0;
        for(int i : p) maxi=max(maxi,i);
        int i=1,j=maxi;
        while(i<=j) {
            int m=(i+j)/2;
            long long int c=0;
            for(int k : p) {
                c=c+(k/m);
                if(k%m) c++;
            } 
            if(c<=h) {
                j=m-1;
                ans=m;
            } else i=m+1;
        }
        return ans;
    }
};