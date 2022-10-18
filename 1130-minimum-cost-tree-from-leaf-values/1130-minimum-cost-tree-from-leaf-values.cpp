class Solution {
public:
    map<pair<int,int>,int>mp;
    map<pair<int,int>,int>mp1;
    int p(int i,int j,vector<int>arr) {
        if(i==j) return 0;
        if(j-i==1) return arr[i]*arr[j];
        int mini=INT_MAX;
        if(mp.count({i,j})) return mp[{i,j}];
        priority_queue<int>q;
        int prod=0;
        if(mp1.count({i,j})) prod = mp1[{i,j}];
        else {
            for(int k=i;k<=j;k++) q.push(arr[k]);
            prod=q.top();  //";
            q.pop(); prod*=q.top();
            //cout<<q.top()<<" ";
            
        }
      
        for(int k=i;k<j;k++) {
            mini=min(mini,p(i,k,arr)+p(k+1,j,arr));
        }
        return mp[{i,j}]=mini+prod;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
       return p(0,n-1,arr);
      
        
    }
};