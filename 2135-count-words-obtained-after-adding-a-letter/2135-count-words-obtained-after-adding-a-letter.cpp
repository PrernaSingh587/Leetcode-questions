class Solution {
public:
    int wordCount(vector<string>& stt, vector<string>& tw) {
        int n=stt.size(),m=tw.size();
        map<vector<int>,int>st;
        for(string s : tw) {
            vector<int>v(26,0);
            for(char c : s) {
                v[c-'a']++;
            }
            st[v]++;
        }
        int ans=0;
        for(string h : stt) {
            vector<int>v(26,0);
            for(char c : h) {
                v[c-'a']++;
            }
            for(char d='a';d<='z';d++) {
                if(v[d-'a']!=0) continue;
                v[d-'a']++;
                if(st.find(v)!=st.end()) {
                ans+=st[v];
             st.erase(v);
                }
                v[d-'a']--;
            }
        }
        return ans;
    }
};