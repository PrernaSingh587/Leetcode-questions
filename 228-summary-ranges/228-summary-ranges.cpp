#define ll long long
class Solution {
public:
    string help(long long int n) {
        if(n==0) return "0";
        string h="";
        int f=0;
        if(n<0) f=1;
        n=abs(n);
        while(n) {
            h+=(n%10)+'0';
            n/=10; 
        }
        reverse(h.begin(),h.end());
        cout<<h<<" ";
        if(f==1) return h='-'+h;
        return h;
    }
    vector<string> summaryRanges(vector<int>& s) {
        if(!s.size()) return {};
        vector<string>v;
        if(s.size()==1) {
            string h=help((ll)s[0]);
            v.push_back(h); return v;
        } else {
            string j=help((ll)s[0]);
            int k=s[0];
            int f=0;
            for(int i=1;i<s.size();i++) {
                if(s[i]==s[i-1]+1) {
                    f=0;
                    continue;
                } else {
                    if(k!=s[i-1])
                    v.push_back(j+"->"+help((ll)s[i-1]));
                    else v.push_back(help((ll)s[i-1]));
                    j=help(s[i]);
                    k=s[i];
                    f=1;
                }
            }
            if(f==0) {
                 v.push_back(j+"->"+help((ll)s[s.size()-1]));
            } else {
                v.push_back(help((ll)s[s.size()-1]));
            }
        }
                            return v;
    }
};