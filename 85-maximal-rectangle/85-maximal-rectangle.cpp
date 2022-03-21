class Solution {
public:
    int solve(vector<int>v,int m) {
        stack<int>s1,s2;
        int maxi=0;
        vector<int>v1(m),v2(m);
        for(int i=0;i<m;i++) {
            while(!s1.empty() && v[s1.top()]>=v[i]) {
                s1.pop();
            }
            if(s1.empty()) v1[i]=-1;
            else v1[i]=s1.top();
            s1.push(i);
        }
         for(int i=m-1;i>=0;i--) {
            while(!s2.empty() && v[s2.top()]>=v[i]) {
                s2.pop();
            }
            if(s2.empty()) v2[i]=m;
            else v2[i]=s2.top();
            s2.push(i);
        }
        for(int i=0;i<m;i++) {
            int hh=v[i]*(v2[i]-v1[i]-1);
            maxi=max(maxi,hh);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int maxi=0;
        vector<int>v(m,0);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]=='1')
                v[j]+=1;
                else v[j]=0;
            }
            maxi=max(maxi,solve(v,m));
        }
        return maxi;
    }
};