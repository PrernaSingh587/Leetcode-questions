class Solution {
public:
    string smallestSubsequence(string s) {
        string res="";
        int a[26]={0},vis[26]={0};
        for(char c : s) a[c-'a']++;
        for(char c : s) {
            a[c-'a']--;
            if(vis[c-'a']) continue;
            while(res.size() && res.back()>c && a[res.back()-'a']) {
                vis[res.back()-'a']=0;
                res.pop_back();
            }
            vis[c-'a']=1;
            res+=c;
        }
        return res;
    }
};