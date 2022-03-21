class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n=ht.size();
        vector<int>v1(n),v2(n);
        stack<int>st,s2;
        for(int i=0;i<n;i++) {
            while(!st.empty() && ht[st.top()]>=ht[i]) st.pop();
            if(st.empty()) v1[i]=-1;
            else v1[i]=st.top();
            st.push(i);
        }
        for(int i=n-1;i>=0;i--) {
            while(!s2.empty() && ht[s2.top()]>=ht[i]) s2.pop();
            if(s2.empty()) v2[i]=n;
            else v2[i]=s2.top();
            s2.push(i);
        }
        int maxi=0;
        for(int i=0;i<n;i++) {
           // cout<<ht[i]<<" "<<v1[i]<<" "<<v2[i]<<endl;
            int h=ht[i]*(abs(v1[i]-v2[i])-1);
            maxi=max(maxi,h);
        }
        return maxi;
    }
};