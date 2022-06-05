class Solution {
public:
    #define pp vector<int>
    int minCost(vector<int>& st, vector<int>& hm, vector<int>& rc, vector<int>& cc) {
        int x1 = st[0];
        int x2 = hm[0];
        int y1 = st[1];
        int y2 = hm[1];
        int ans = 0;

        if (x1 == x2 && y1 == y2) return 0; // when start and home at same position

        if (x1 < x2) {
            for (int i = x1 + 1; i <= x2 ; i++)
                ans += rc[i];
        }
        else {
            for (int i = x2; i <= x1 - 1; i++)
                ans += rc[i];
        }

        if (y1 < y2) {
            for (int i = y1 + 1; i <= y2 ; i++)
                ans += cc[i];
        }
        else {
            for (int i = y2; i <= y1 - 1; i++)
                ans += cc[i];
        }
        return ans;
    }
};