class Solution {
public:
    map<pair<int,int>,int>mp;
    int solve(vector<int>& p,int k,int m) {
        if(k>=p.size()) return 0;
        if(mp.count({k,m})) return mp[{k,m}];
        int ans=INT_MIN,n=p.size(),sum=0,c=0,j=min(n,(2*m+k));
        //cout<<j<<" "<<k<<endl;
        for(int i=k;i<j;i++) {
            c++;
            sum+=p[i];
            ans=max(ans,sum-solve(p,i+1,max(m,c)));
        }
        return mp[{k,m}]= ans;
    }
    int stoneGameII(vector<int>& p) {
        int sum=0;
        for(int i: p) sum+=i;
        int h=solve(p,0,1);
       // cout<<h<<" ";
        return (h+sum)/2;
    }
};