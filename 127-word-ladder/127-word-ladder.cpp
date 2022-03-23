#define pb push_back
class Solution {
public:
    int ladderLength(string bg, string en, vector<string>& wr) {
        unordered_set<string>st;
        for(string w : wr) st.insert(w);
        unordered_map<string,vector<string>>mp;
        unordered_map<string,int>vis;
         for(int i=0;i<bg.size();i++)
            for(char c='a';c<='z';c++) {
                    string tem=bg;
                    tem[i]=c; 
                    if(tem==bg) continue;
                    if(st.find(tem)!=st.end()) {
                        mp[bg].pb(tem);// cout<<tem<<" ";
                    }
                }
  
        for(string w : wr) {
            for(int i=0;i<w.size();i++) {
                for(char c='a';c<='z';c++) {
                    string tem=w;
                    tem[i]=c; 
                    if(tem==w) continue;
                    if(st.find(tem)!=st.end()) {
                        mp[w].pb(tem);// cout<<tem<<" ";
                    }
                }
            }
        }
        int p=1;
        queue<string>q;
        q.push(bg);
        vis[bg]=1;
        while(!q.empty()) {
            int s=q.size();
            while(s--) {
                string k=q.front(); q.pop();
                if(k==en) return p;
                for(string h : mp[k]) {
                    // cout<<h<<" ";
                    if(vis.count(h)) continue;
                    vis[h]=1;
                    q.push(h);
                }
            }
           p++;
        }
        return 0;
    }
};