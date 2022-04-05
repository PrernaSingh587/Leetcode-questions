class Solution {
public:
    int isDigit(char c) {
        return c>='0' && c<='9';
    }
    string solve(string s,int &i) {
        string res="";
        while(i<s.size() && s[i]!=']') {
            if(!isDigit(s[i])) {
                res+=s[i++];
            } else {
                int n=0;
                while(i<s.size() && isDigit(s[i])) {
                    n=n*10+(s[i]-'0');
                    i++;
                }
                i++;
                string ans=solve(s,i);
                while(n--) {
                    res+=ans;
                }
                i++;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int i=0;
        return solve(s,i);
    }
};