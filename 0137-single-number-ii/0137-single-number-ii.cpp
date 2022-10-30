class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int ones=0,twos=0;
        for(int i : nums) {
            ones = (i^ones)&(~twos);
            twos = (i^twos)&(~ones);
        }
        return ones;
    }
};