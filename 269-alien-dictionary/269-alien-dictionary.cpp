class Solution {
public:
    string alienOrder(vector<string>& w) {
        if(w.size()==0) return "";
        if(w.size()==1) w.push_back(w[0]);
        int n=w.size();
        vector<int>adj[26];
        int indeg[26]={0},out[26]={0}; // memset(indeg,0,sizeof(indeg));
        for(int i=0;i<n-1;i++) {
           int j=i+1;
                int k=0,m=0;
                while(k<w[i].size() &&
                      m<w[j].size() && w[i][k]==w[j][m]) {
                  out[w[i][k]-'a']++;  out[w[j][m]-'a']++;
                    k++; m++;
                }
                if(k<w[i].size() &&
                      m<w[j].size()) {
                adj[w[i][k]-'a'].push_back(w[j][m]-'a');
                indeg[w[j][m]-'a']++;
               } else if(k<w[i].size()) return "";
            
            
            while(k<w[i].size()) {
                out[w[i][k++]-'a']++; 
            }
            while( m<w[j].size()) {
                out[w[j][m++]-'a']++;
            }
        }
        string ans="";
        queue<int>q;
        for(int i=0;i<26;i++) {
            if(indeg[i]==0 && out[i]) q.push(i);
        }
        if(q.size()==0) return "";
        while(!q.empty()) {
            int s=q.size();
            while(s--) {
                int k=q.front();q.pop();
                cout<<k<<" ";
                ans+=k+'a';
                for(int i : adj[k]) {
                    indeg[i]--;
                    if(indeg[i]==0) q.push(i);
                }
            }
        }
        
        for(int i=0;i<26;i++) {
            if(indeg[i]>0) { return "";}
        }
        return ans;
    }
};