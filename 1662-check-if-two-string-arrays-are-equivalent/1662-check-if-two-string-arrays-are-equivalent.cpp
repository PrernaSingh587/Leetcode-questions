class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        int x=0,y=0,i=0,j=0;
        while(x<w1.size() && y<w2.size()) {
            if(w1[x][i]!=w2[y][j]) return 0;
            i++;
            if(i==w1[x].size()) {
                i=0; x++;
            }
            j++;
            if(j==w2[y].size()) {
                j=0; y++;
            }
        }
       // cout<<x<<" "<<y<<" "<<i<<" "<<j<<endl;
        if(x<w1.size() || y<w2.size() || i!=0 || j!=0) return 0;
        return 1;
    }
};