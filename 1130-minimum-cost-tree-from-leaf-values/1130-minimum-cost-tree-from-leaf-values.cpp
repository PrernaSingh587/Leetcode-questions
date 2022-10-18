class Solution {
public:
    map<pair<int,int>,vector<int>>mp;
    vector<int> p(int i,int j,vector<int>arr) {
        if(i==j) return {arr[i],0};
        if(j-i==1) return {arr[i]*arr[j],arr[i]*arr[j]};
        int mini=INT_MAX,c=1;
        if(mp.count({i,j})) return mp[{i,j}];
        vector<int>l,r;
        for(int k=i;k<j;k++) {
            l=p(i,k,arr); r=p(k+1,j,arr);
            int a=0,b=0;
            for(int x=i;x<=k;x++) a=max(a,arr[x]);
            for(int x=k+1;x<=j;x++) b=max(b,arr[x]);
             //cout<<mini<<" "<<l[1]<<" "<<r[1]<<" "<<c<<endl;
            if(mini>l[1]+r[1]+(a*b)) {
                mini = l[1]+r[1]+(a*b);
                c=a*b;
               
            }
        }
        return mp[{i,j}]={c,mini};
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
       vector<int>ans= p(0,n-1,arr);
        return ans[1];
        
    }
};