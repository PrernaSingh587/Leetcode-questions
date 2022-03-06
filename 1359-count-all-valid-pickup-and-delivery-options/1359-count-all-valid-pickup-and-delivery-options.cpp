class Solution {
public:
    map<pair<int,int>,int>mp;
    long solve(int up, int ud) {
        if(up==0 && ud==0) return 1;
        if(up<0 || ud<0 || up>ud) return 0;
        long ans=0;
        if(mp.count({up,ud})) return mp[{up,ud}];
        ans+=up*solve(up-1,ud);
        ans%=1000000007;
        ans+=(ud-up)*solve(up,ud-1);
        ans%=1000000007;
        return mp[{up,ud}]= ans;
    }
    int countOrders(int n) {
        return solve(n,n);
    }
};