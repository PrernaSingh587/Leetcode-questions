class Solution {
public:
    vector<string> wordBreak(string A, vector<string>& B) {
        int n=A.size();
    int m=B.size();
    unordered_map<int,vector<string>>mp;
    unordered_set<string>st(B.begin(),B.end());

    for(int i=n-1;i>=0;i--) {
        string k="";
        for(int j=i;j<n;j++) {
            k+=A[j];
            if(st.find(k)!=st.end()) {
                
                if((j+1)<n)
                {
                    for(int d=0;d<mp[j+1].size();d++) {
                        string ans=k+' ';
                    ans+=mp[j+1][d];
                    mp[i].push_back(ans);
                }}
                else mp[i].push_back(k);
            }
        }
    }
    return mp[0];
    }
};