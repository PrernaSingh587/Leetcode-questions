//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string>v;
		    int n=s.size();
		    for(int i=pow(2,n)-1;i>=1;i--) {
		        string ans="";
		        for(int j=0;j<n;j++) {
		            if((i>>j)&1) {
		                ans+=s[j];
		            }
		        }
		        v.push_back(ans);
		    }
		    sort(v.begin(),v.end());
		    return v;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends