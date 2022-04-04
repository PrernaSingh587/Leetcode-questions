// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    unordered_set<string>st;
   int solve(string A, int n) {
       if(n==0) return 0;
       int dp[n];
       memset(dp,0,sizeof(dp));
       string h="";
       for(int i=0;i<n;i++) {
           for(int j=0;j<i;j++) {
             h=A.substr(j+1,i-j);
             if(st.find(h)!=st.end()) 
                dp[i]=dp[i]||dp[j];
             }
           h=A.substr(0,i+1);
           if(st.find(h)!=st.end()) dp[i]=1;
           
       }
       return dp[n-1];
   }
    int wordBreak(string A, vector<string> &B) {
        for(string h : B) st.insert(h);
        return solve(A,A.size());
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends