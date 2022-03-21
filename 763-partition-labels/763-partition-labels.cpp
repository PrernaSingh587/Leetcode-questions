class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        int a[26]={0};
        int i=0;
        for(char c : s) {a[c-'a']=i; i++;}
        int top=0,maxi=0;
        vector<int>v;
        for(i=0;i<n;i++) {
            maxi=max(maxi,a[s[i]-'a']);
            if(i==maxi) {
                v.push_back(i-top+1);
                top=i+1;
            }
        }
            
        return v;
    }
};