class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(int i=31;i>=0;i--) {
            int c=0;
            for(int j : nums) {
                int d = (j>>i)&1;
                c+=d;
            }
            int y=(c%3);
            x+=(y<<i);
        }
        return x;
    }
};