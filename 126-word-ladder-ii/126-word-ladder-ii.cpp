class Solution {
public:
    vector<vector<string>>v;
    unordered_map<string,vector<string>>mp;
    void back(string st, string en, vector<string> w) {
        if(st==en) {
            reverse(w.begin(),w.end());
            v.push_back(w);
            return;
        }
        for(int i=0;i<mp[en].size();i++) {
            cout<<mp[en][i]<<" ";
            w.push_back(mp[en][i]);
            back(st,mp[en][i],w);
            w.pop_back();
        }
    }
    vector<vector<string>> findLadders(string st, string en, vector<string>& wordList) {
        unordered_map<string,int>vis;
        
        int c=0;
        queue<string>q;
        q.push(st);
        
        vis[st]=1;
        unordered_set<string>wq;
        for(string k : wordList) wq.insert(k);
        int f=0;
        while(!q.empty()) {
            int s=q.size();
            while(s--) {
                string h=q.front();    q.pop();
                
            if(h==en) {
                cout<<1<<" ";
                back(st,en,{en});
                return v;
            }
            
             for(int i=0;i<h.size();i++) {
                 for(char x='a'; x<='z'; x++) {
                     string d=h;
                     d[i]=x;
                     if(d==h || (wq.find(d)==wq.end())) continue;
                     if(vis.count(d)==0) {
                         vis[d]=vis[h]+1;
                          q.push(d);
                         mp[d].push_back(h);
                     } else if(vis[d]==vis[h]+1) {
                          mp[d].push_back(h);
                     }  
                     
                 }
             }    
            }  
        }
        return v;
    }
};