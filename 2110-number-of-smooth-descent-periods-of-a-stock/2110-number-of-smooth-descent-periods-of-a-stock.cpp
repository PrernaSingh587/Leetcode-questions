#define ll long long
class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        ll int l=0,c=1;
        for(int i=1;i<p.size();i++) {
            if(p[i]+1==p[i-1]) {
                c+=i-l+1;
            } else {l=i;c++;}
        }
        return c;
    }
};