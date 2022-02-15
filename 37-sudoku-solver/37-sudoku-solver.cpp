class Solution {
public:
    int p(int r,int c) {
    int rid=r/3,cid=c/3;
    return rid*3+cid;
    }
    unordered_set<char>r[10],c[10],box[10];
    void solveSudoku(vector<vector<char>>& b) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(b[i][j]!='.') 
                    r[i].insert(b[i][j]);
                  int boxn=p(i,j);
                  box[boxn].insert(b[i][j]);
            }
        }
        for(int j=0;j<9;j++) {
            for(int i=0;i<9;i++){
               if(b[i][j]!='.') 
                  c[j].insert(b[i][j]);
            }
        }
        dfs(b,0);
    }
    
    int dfs(vector<vector<char>>& b, int col) {
        if(col==81) return 1;
       
        int x=col/9,y=col%9,z=p(x,y);
        //cout<<x<<" "<<y<<" ";
        if(b[x][y]!='.') return dfs(b,col+1);
        for(char i='1';i<='9';i++) {
           if(r[x].find(i)==r[x].end() && c[y].find(i)==c[y].end() && 
             box[z].find(i)==box[z].end()) {
               r[x].insert(i); c[y].insert(i); box[z].insert(i);
               b[x][y]=i;
               if(dfs(b,col+1)) return 1; 
               b[x][y]='.';
               r[x].erase(i); c[y].erase(i); box[z].erase(i);
           }
        }
        return 0;
    }
};