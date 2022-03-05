class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2) return 0;
        int bal=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(' || locked[i]=='0') bal++;
            else bal--;
            if(bal<0) return 0;
        }
        bal=0;
        for(int i=s.size()-1;i>=0;i--) {
            if(s[i]==')' || locked[i]=='0') bal++;
            else bal--;
            if(bal<0) return 0;
        }
            return 1;
    }
};