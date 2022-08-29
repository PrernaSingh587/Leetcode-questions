class Solution {
public:
    int solve(int n, vector<int>v,int k) {
        int sum=0,maxi=INT_MIN;
        set<int>mp;
        mp.insert(0);
        for(int i=0;i<n;i++) {
            sum+=v[i];
           //cout<<sum-k<<". ";
            auto j=mp.lower_bound(sum-k);
            if(j!=mp.end()){ 
            int kk= (*j);
               // cout<<sum-kk<<"\n";
            maxi=max(maxi,sum-kk);} //else cout<<"something. ";
             mp.insert(sum);
        }
        return maxi;
    }
    int maxSumSubmatrix(vector<vector<int>>& mat, int kl) {
       int n=mat.size(),m=mat[0].size();
        int sum=0,maxi=INT_MIN;
        for(int j=0;j<m;j++) {
             vector<int>v(n,0);
            for(int k=j;k<m;k++) {
                for(int i=0;i<n;i++) {
                v[i]+=mat[i][k];
            }
                maxi=max(maxi,solve(n,v,kl));
            }
            
        }
        return maxi;
    }
};